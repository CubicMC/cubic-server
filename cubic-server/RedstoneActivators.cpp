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
    this->feedPower(false);
    this->_powered = false;
    if (this->_isWooden)
        ; // TODO make activation noise (1277)
    else // stone
        ; // TODO make activation noise (1111)
}

void PressurePlate::press(void)
{
    // note: a powered pressure plate is equivalent to having:
    //       a redstone block in lieu of the pressure plate + a redstone block in lieu of the attached block
    this->feedPower(true);
    this->_powered = true;
    if (this->_isWooden)
        ; // TODO ? std::unique_ptr<std::vector<uint8_t>> createSoundEffect(const SoundEffect &);
          // TODO ? Player::playSoundEffect(SoundsList sound, FloatingPosition position, SoundCategory category);
    else // stone
        ; // TODO make activation noise (1112)
}

PressurePlate::PressurePlate(std::shared_ptr<Dimension> dim, Position pos, bool isWooden):
    Lever(dim, pos, Facing::Floor),
    _isWooden(isWooden),
    _duration(isWooden ? 15 : 10) // ticks
{
    _connectedBlocks = {
        {0, 0, 0}, // current
        {0, -1, 0}, // below
        {1, 0, 0}, // north
        {-1, 0, 0}, // south
        {0, 0, 1}, // west
        {0, 0, -1}}; // east
}
PressurePlate::~PressurePlate(void) { }

/**************** BUTTON *****************/

void Button::unpress(void)
{
    this->feedPower(false);
    this->_powered = false;
    if (this->_isWooden)
        ; // TODO make activation noise (1272)
    else // stone
        ; // TODO make activation noise (1106)
}

void Button::press(void)
{
    // note: a powered button is equivalent to having:
    //       a redstone block in lieu of the button + a redstone block in lieu of the attached block
    this->feedPower(true);
    this->_powered = true;
    this->_clock.start();
    if (this->_isWooden)
        ; // TODO ? std::unique_ptr<std::vector<uint8_t>> createSoundEffect(const SoundEffect &);
          // TODO ? Player::playSoundEffect(SoundsList sound, FloatingPosition position, SoundCategory category);
    else // stone
        ; // TODO make activation noise (1107)
    if (this->_clock.getTick() == this->_duration) {
        this->unpress();
        this->_clock.stop();
    }
}

Button::Button(std::shared_ptr<Dimension> dim, Position pos, Facing facing, bool isWooden):
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
Button::~Button(void) { }

/***************** LEVER *****************/

void Lever::feedPower(int xOffset, int yOffset, int zOffset, bool giving)
{
    Position pos = this->_pos + Position({xOffset + 1, yOffset, zOffset});

    // TODO awaiting BlockId::power();
    //    this->_dim->getLevel().getChunkColumnFromBlockPos(Position2D(pos.x % 16, pos.z % 16)).getBlock(pos)->power(giving ? 15 : 0);
}
void Lever::feedPower(bool giving)
{
    for (std::vector<int> blk : this->_connectedBlocks)
        this->feedPower(blk[0], blk[1], blk[2], giving);
}

Lever::Lever(std::shared_ptr<Dimension> dim, Position pos, Facing facing):
    Redstone::RedstoneItem(dim, pos),
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
Lever::~Lever(void) { }

/*************** CIRCUITRY ***************/

using namespace Redstone;

void RedstoneWire::feedPower(int powerToFeed)
{
    for (std::vector<int> blk : this->_connectedBlocks)
        this->feedPower(blk[0], blk[1], blk[2], powerToFeed);
}
void RedstoneWire::feedPower(int xOffset, int yOffset, int zOffset, int powerToFeed)
{
    Position pos = this->_pos + Position(xOffset, yOffset, zOffset);

    // TODO awaiting BlockId::power();
    //    this->_dim->getLevel().getChunkColumnFromBlockPos(pos.x % 16, pos.z % 16).getBlock(this->_pos).power(powerToFeed);
}

RedstoneWire::RedstoneWire(std::shared_ptr<Dimension> dim, Position pos, uint8_t power, std::vector<bool> connected):
    Redstone::RedstoneItem(dim, pos),
    _power(power),
    _connected(connected)
{
    static const std::vector<std::vector<int>> possibleConnections = {
        // {up, level, down}
        {1, 1, 0},  {1, 0, 0},  {1, -1, 0}, // 3 adjacent blocks, facing north
        {-1, 1, 0}, {-1, 0, 0}, {-1, -1, 0}, // 3 adjacent blocks, facing south
        {0, 1, 1},  {0, 0, 1},  {0, -1, 1}, // 3 adjacent blocks, facing west
        {0, 1, -1}, {0, 0, -1}, {0, -1, -1} // 3 adjacent blocks, facing east
    };
    static const std::list<std::string> conTo = {
        // wires connect to...
        "redstone_block",
        "redstone_torch",
        "redstone_wire",
        "redstone_repeater",
        "redstone_comparator",
        "lever",
        "stone_button",
        "wooden_button",
        "tripwire_hook",
        "daylight_detector",
        "daylight_detector_inverted",
        "observer",
        "sculk_sensor",
        "target",
        "chiseled_bookshelf",
        "detector_rail",
        "lectern",
        "lightning_rod",
        "trapped chest",
        "wooden_pressure_plate",
        "stone_pressure_plate",
        "heavy_weighted_pressure_plate",
        "light_weighted_pressure_plate",
    };

    _connectedBlocks = {
        {1, 0, 0}, // north
        {-1, 0, 0}, // south
        {0, 0, 1}, // west
        {0, 0, -1}, // east
    };
    Position posLevel, posAdj, chunkPos = {this->_pos.x % 16, this->_pos.y % 16, this->_pos.z % 16};
    for (std::vector<int> blk : possibleConnections) {
        posLevel = chunkPos + Position({blk[1], 0, blk[2]});
        posAdj = chunkPos + Position({blk[0], blk[1], blk[2]});

        if ((blk[1] == 1 // can't connect to an upward block if there is a block above
             && std::to_string(this->_dim->getLevel().getChunkColumnFromBlockPos(Position2D(chunkPos.x, chunkPos.z % 16)).getBlock(chunkPos)) !=
                 "air" // TODO air... or "transparent" blocks)
            ) ||
            (blk[1] == -1 // can't connect to a down ward block if there is a block at the same level as the wire
             && std::to_string(this->_dim->getLevel().getChunkColumnFromBlockPos(Position2D(chunkPos.x, chunkPos.z % 16)).getBlock(posLevel)) !=
                 "air" // TODO air... or "transparent" blocks)
            ))
            continue;
        if (std::find(conTo.begin(), conTo.end(), std::to_string((int) (this->_dim->getChunk(Position2D(this->_pos.x, this->_pos.z)).getBlock(posAdj)))) != conTo.end()) {
            _connectedBlocks.push_back({blk[0], blk[1], blk[2]});
            this->_connected[blk[0] == 1 ? Connection::CNorth : blk[0] == -1 ? Connection::CSouth : blk[2] == 1 ? Connection::CWest : /****EAST****/ Connection::CEast] = true;
        }
    }
    // TODO problem: a new connected wire won't inherit the power of the previous one
    //      how to do that without going cyclic?...
    this->feedPower(_power - 1);
    // TODO change texture according to this->_connected: 4-way, line, corner, triple
}
RedstoneWire::~RedstoneWire(void) { }

/***************** BASE *****************/
RedstoneItem::RedstoneItem(std::shared_ptr<Dimension> dim, Position pos):
    _dim(dim),
    _pos(pos)
{
}
RedstoneItem::~RedstoneItem(void) { }
