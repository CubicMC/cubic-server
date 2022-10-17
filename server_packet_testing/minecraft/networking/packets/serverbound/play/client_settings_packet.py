import operator

from minecraft.networking.packets import Packet
from minecraft.networking.types import (
    String, Byte, VarInt, Boolean, UnsignedByte, Enum, BitFieldEnum,
    AbsoluteHand
)
from minecraft.utility import attribute_transform


class ClientSettingsPacket(Packet):
    @staticmethod
    def get_id(context):
        return 0x05 if context.protocol_later_eq(464) else \
               0x04 if context.protocol_later_eq(389) else \
               0x03 if context.protocol_later_eq(343) else \
               0x04 if context.protocol_later_eq(336) else \
               0x05 if context.protocol_later_eq(318) else \
               0x04 if context.protocol_later_eq(94) else \
               0x15

    packet_name = 'client settings'

    @staticmethod
    def get_definition(context):
        return [
            {'locale': String},
            {'view_distance': Byte},
            {'chat_mode': VarInt if context.protocol_later(47) else Byte},
            {'chat_colors': Boolean},
            {'displayed_skin_parts': UnsignedByte},
            {'main_hand': VarInt} if context.protocol_later(49) else {},

            {'enable_text_filtering': Boolean}
            if context.protocol_later_eq(757) else
            {'disable_text_filtering': Boolean}
            if context.protocol_later_eq(755) else {},

            {'allow_server_listings': Boolean}
            if context.protocol_later_eq(755) else {},
        ]

    # Set a default value for 'enable_text_filtering', because most clients
    # will probably want this value, and to avoid breaking old code.
    enable_text_filtering = False

    # To support the possibility of both 'enable_text_filtering' and
    # 'disable_text_filtering' fields existing, make 'disable_text_filtering'
    # (which is the less likely to be used of the two) into a property that
    # stores the negation of its value in the ordinary attribute
    # 'enable_text_filtering'.
    disable_text_filtering = attribute_transform(
        'enable_text_filtering', operator.not_, operator.not_)

    # Set a default value for 'allow_server_listings', because most clients
    # will probably want this value, and to avoid breaking old code.
    allow_server_listings = False

    field_enum = classmethod(
        lambda cls, field, context: {
            'chat_mode': cls.ChatMode,
            'displayed_skin_parts': cls.SkinParts,
            'main_hand': AbsoluteHand,
        }.get(field))

    class ChatMode(Enum):
        FULL = 0    # Receive all types of chat messages.
        SYSTEM = 1  # Receive only command results and game information.
        NONE = 2    # Receive only game information.

    class SkinParts(BitFieldEnum):
        CAPE = 0x01
        JACKET = 0x02
        LEFT_SLEEVE = 0x04
        RIGHT_SLEEVE = 0x08
        LEFT_PANTS_LEG = 0x10
        RIGHT_PANTS_LEG = 0x20
        HAT = 0x40

        ALL = 0x7F
        NONE = 0x00

    # This class alias is retained for backward compatibility.
    Hand = AbsoluteHand
