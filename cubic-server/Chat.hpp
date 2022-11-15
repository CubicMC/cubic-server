#ifndef CUBICSERVER_CHAT_HPP
#define CUBICSERVER_CHAT_HPP

#include <stdint.h>

enum class MsgType : int32_t {
    Chat = 0,
    System = 1,
    GameInfo = 2,
    Say = 3,
    Whisper = 4,
    Team = 5,
    Emote = 6, // Don't ask me...
    Tellraw = 7,
};

class Chat
{

};


#endif //CUBICSERVER_CHAT_HPP
