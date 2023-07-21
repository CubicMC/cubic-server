#include "Redstone.hpp"
#include <list>

using namespace Redstone::Activators;

/**************** BUTTON *****************/

void Button::unpress(void) {
    // this->_dim->getBlock(this->_pos)->power(0);
    this->_powered = false;
    if (this->_isWooden)
        ;// TODO make activation noise (1272)
    else // stone
        ;// TODO make activation noise (1106)
}

void Button::press(void) {
    // TODO awaiting BlockId::power();
    // note: a powered button is equivalent to having:
    //       a redstone block in lieu of the button + a redstone block in lieu of the attached block
    if (this->_facing == Facing::Ceiling)
        ; // this->_dim->getBlock(this->_pos + Vector3<double>(0, 1, 0))->power(15);
    else if (this->_facing == Facing::Floor)
        ; // this->_dim->getBlock(this->_pos + Vector3<double>(0, -1, 0))->power(15);
    else { // wall
        if (this->_facing == Facing::North)
            ; // this->_dim->getBlock(this->_pos + Vector3<double>(1, 0, 0))->power(15);
        else if (this->_facing == Facing::South)
            ; // this->_dim->getBlock(this->_pos + Vector3<double>(-1, 0, 0))->power(15);
        else if (this->_facing == Facing::West)
            ; // this->_dim->getBlock(this->_pos + Vector3<double>(0, 0, 1))->power(15);
        else // east
            ; // this->_dim->getBlock(this->_pos + Vector3<double>(0, 0, -1))->power(15);
    }
    // this->_dim->getBlock(this->_pos)->power(15);
    this->_powered = true;
    this->_clock.start();
    if (this->_isWooden)
        ;// TODO ? std::unique_ptr<std::vector<uint8_t>> createSoundEffect(const SoundEffect &);
         // TODO ? Player::playSoundEffect(SoundsList sound, FloatingPosition position, SoundCategory category);
    else // stone
        ;// TODO make activation noise (1107)
    if (this->_clock.getTick() == this->_duration) {
        this->unpress();
        this->_clock.stop();
    }
}

Button::Button(std::shared_ptr<Dimension> dim, Vector3<double> pos, Facing facing, bool isWooden):
    Lever(dim, pos, facing),
    _isWooden(isWooden),
    _duration(isWooden ? 15 : 10) // ticks
{}
Button::~Button(void) {}

/***************** LEVER *****************/

void Lever::unpress(void) {
    // TODO retract power
    this->_powered = false;
    // TODO make deactivation noise (591)
}

void Lever::press(void) {
    // TODO deliver power level 15 to attached and adjacent blocks
    this->_powered = true;
    // TODO make activation noise (591)
}

Lever::Lever(std::shared_ptr<Dimension> dim, Vector3<double> pos, Facing facing):
    _dim(dim),
    _pos(pos),
    _facing(facing),
    _powered(false)
{
    // TODO deliver power level 15 to attached and adjacent blocks
}
Lever::~Lever(void) {}

/*************** CIRCUITRY ***************/

using namespace Redstone;

RedstoneWire::RedstoneWire(uint8_t power, std::vector<bool> connected):
    _power(power),
    _connected(connected)
{
    static const std::list<std::string> conTo = { // wires connect to...
        "redstone_block", "redstone_torch", "redstone_wire", "redstone_repeater", "redstone_comparator",
        "lever", "stone_button", "wooden_button", "tripwire_hook", "daylight_detector", "daylight_detector_inverted",
        "observer", "sculk_sensor", "target", "chiseled_bookshelf", "detector_rail", "lectern", "lightning_rod", "trapped chest",
        "wooden_pressure_plate", "stone_pressure_plate", "heavy_weighted_pressure_plate", "light_weighted_pressure_plate",
    };
    // TODO awaiting BlockId::power();
    // this->_dim->getBlock(this->_pos + Vector3<double>( 1,  0,  0))->power(_power - 1);
    // this->_dim->getBlock(this->_pos + Vector3<double>(-1,  0,  0))->power(_power - 1);
    // this->_dim->getBlock(this->_pos + Vector3<double>( 0,  0,  1))->power(_power - 1);
    // this->_dim->getBlock(this->_pos + Vector3<double>( 0,  0, -1))->power(_power - 1);
    // this->_connected[Connection::CNorth] = std::find(conTo.begin(), conTo.end(), this->_dim->getBlock(this->_pos + Vector3<double>( 1,  0,  0)).name) != conTo.end();
    // this->_connected[Connection::CSouth] = std::find(conTo.begin(), conTo.end(), this->_dim->getBlock(this->_pos + Vector3<double>(-1,  0,  0)).name) != conTo.end();
    // this->_connected[Connection::CWest]  = std::find(conTo.begin(), conTo.end(), this->_dim->getBlock(this->_pos + Vector3<double>( 0,  0,  1)).name) != conTo.end();
    // this->_connected[Connection::CEast]  = std::find(conTo.begin(), conTo.end(), this->_dim->getBlock(this->_pos + Vector3<double>( 0,  0, -1)).name) != conTo.end();
    // TODO change texture accordingly
}
RedstoneWire::~RedstoneWire(void) {}