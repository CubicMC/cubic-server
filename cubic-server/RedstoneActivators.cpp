#include "Redstone.hpp"
#include <list>

using namespace Redstone::Activators;

/************ PRESSURE PLATE *************/

void PressurePlate::unpress(void)
{
    this->_clock.start();
    if (this->_clock.getTick() == this->_duration) {
        this->unpress();
        this->_clock.stop();
    }
    // TODO awaiting BlockId::power();
    this->feedPower(false);
    this->_powered = false;
    if (this->_isWooden)
        ;// TODO make activation noise (1277)
    else // stone
        ;// TODO make activation noise (1111)
}

void PressurePlate::press(void)
{
    // note: a powered pressure plate is equivalent to having:
    //       a redstone block in lieu of the pressure plate + a redstone block in lieu of the attached block
    // TODO awaiting BlockId::power();
    this->feedPower(true);
    this->_powered = true;
    if (this->_isWooden)
        ;// TODO ? std::unique_ptr<std::vector<uint8_t>> createSoundEffect(const SoundEffect &);
         // TODO ? Player::playSoundEffect(SoundsList sound, FloatingPosition position, SoundCategory category);
    else // stone
        ;// TODO make activation noise (1112)
}

PressurePlate::PressurePlate(std::shared_ptr<Dimension> dim, Vector3<double> pos, bool isWooden):
    Lever(dim, pos, Facing::Floor),
    _isWooden(isWooden),
    _duration(isWooden ? 15 : 10) // ticks
{
    _connectedBlocks = {{ 0,  0,  0}, // current
                        { 0, -1,  0}, // below
                        { 1,  0,  0}, // north
                        {-1,  0,  0}, // south
                        { 0,  0,  1}, // west
                        { 0,  0, -1}};// east
}
PressurePlate::~PressurePlate(void) {}

/**************** BUTTON *****************/

void Button::unpress(void)
{
    // TODO awaiting BlockId::power();
    this->feedPower(false);
    this->_powered = false;
    if (this->_isWooden)
        ;// TODO make activation noise (1272)
    else // stone
        ;// TODO make activation noise (1106)
}

void Button::press(void)
{
    // note: a powered button is equivalent to having:
    //       a redstone block in lieu of the button + a redstone block in lieu of the attached block
    // TODO awaiting BlockId::power();
    this->feedPower(true);
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
{
    _connectedBlocks = {{0, 0, 0}}; // current
    if (this->_facing == Facing::Ceiling)
        _connectedBlocks.push_back({0, 1, 0});
    else if (this->_facing == Facing::Floor)
        _connectedBlocks.push_back({0, -1, 0});
    else { // wall
        if (this->_facing == Facing::North)
            _connectedBlocks.push_back({1, 0, 0});
        else if (this->_facing == Facing::South)
            _connectedBlocks.push_back({-1, 0, 0});
        else if (this->_facing == Facing::West)
            _connectedBlocks.push_back({0, 0, 1});
        else // east
            _connectedBlocks.push_back({0, 0, -1});
    }
}
Button::~Button(void) {}

/***************** LEVER *****************/

void Lever::feedPower(int xOffset, int yOffset, int zOffset, bool giving)
{
    // TODO awaiting BlockId::power();
//    this->_dim->getChunk(this->_pos)->getBlock(this->_pos
//        + Vector3<double>(xOffset, yOffset, zOffset))->power(giving ? 15 : 0);
}
void Lever::feedPower(bool giving)
{
    for (std::vector<int> blk : this->_connectedBlocks)
        this->feedPower(blk[0], blk[1], blk[2], giving);
}

Lever::Lever(std::shared_ptr<Dimension> dim, Vector3<double> pos, Facing facing):
    _dim(dim),
    _pos(pos),
    _facing(facing),
    _powered(false)
{
    _connectedBlocks = {{0, 0, 0}};
    if (this->_facing == Facing::Ceiling)
        _connectedBlocks.push_back({0, 1, 0});
    else if (this->_facing == Facing::Floor)
        _connectedBlocks.push_back({0, -1, 0});
    else { // wall
        if (this->_facing == Facing::North)
            _connectedBlocks.push_back({1, 0, 0});
        else if (this->_facing == Facing::South)
            _connectedBlocks.push_back({-1, 0, 0});
        else if (this->_facing == Facing::West)
            _connectedBlocks.push_back({0, 0, 1});
        else // east
            _connectedBlocks.push_back({0, 0, -1});
    }
}
Lever::~Lever(void) {}

/*************** CIRCUITRY ***************/

using namespace Redstone;

void RedstoneWire::feedPower(int powerToFeed)
{
    for (std::vector<int> blk : this->_connectedBlocks)
        this->feedPower(blk[0], blk[1], blk[2], powerToFeed);
}
void RedstoneWire::feedPower(int xOffset, int yOffset, int zOffset, int powerToFeed)
{
    // TODO awaiting BlockId::power();
//    this->_dim->getChunk(this->_pos)->getBlock(this->_pos
//        + Vector3<double>(xOffset, yOffset, zOffset))->power(powerToFeed);
}

RedstoneWire::RedstoneWire(uint8_t power, std::vector<bool> connected):
    _power(power),
    _connected(connected)
{
    static std::vector<std::vector<int>> possibleConnections = {
        { 1,  1,  0}, { 1,  0,  0}, { 1, -1,  0}, // 3 adjacent blocks, facing north
        {-1,  1,  0}, {-1,  0,  0}, {-1, -1,  0}, // 3 adjacent blocks, facing south
        { 0,  1,  1}, { 0,  0,  1}, { 0, -1,  1}, // 3 adjacent blocks, facing west
        { 0,  1, -1}, { 0,  0, -1}, { 0, -1, -1}  // 3 adjacent blocks, facing east
    };
    static const std::list<std::string> conTo = { // wires connect to...
        "redstone_block", "redstone_torch", "redstone_wire", "redstone_repeater", "redstone_comparator",
        "lever", "stone_button", "wooden_button", "tripwire_hook", "daylight_detector", "daylight_detector_inverted",
        "observer", "sculk_sensor", "target", "chiseled_bookshelf", "detector_rail", "lectern", "lightning_rod", "trapped chest",
        "wooden_pressure_plate", "stone_pressure_plate", "heavy_weighted_pressure_plate", "light_weighted_pressure_plate",
    };

    _connectedBlocks = {{ 1,  0,  0}, // north
                        {-1,  0,  0}, // south
                        { 0,  0,  1}, // west
                        { 0,  0, -1}};// east
    for (std::vector<int> blk : possibleConnections) {
        // TODO temporarily silented because getBlock is capricious
//        if (std::find(conTo.begin(), conTo.end(), this->_dim->getChunk(this->_pos)->getBlock(this->_pos + Vector3<double>(blk[0], blk[1], blk[2])).name) != conTo.end()) {
                    _connectedBlocks.push_back({blk[0], blk[1], blk[2]});
                    this->_connected[blk[0] ==  1 ? Connection::CNorth
                                   : blk[0] == -1 ? Connection::CSouth
                                   : blk[2] ==  1 ? Connection::CWest
                                   : /****EAST****/ Connection::CEast] = true;
        }
//    }
    // TODO v awaiting BlockId::power();
    this->feedPower(_power - 1);
    // TODO change texture according to this->_connected: 4-way, line, corner, triple
}
RedstoneWire::~RedstoneWire(void) {}