#include "DefaultWorld.hpp"

DefaultWorld::DefaultWorld()
    : World()
{
    _theEnd = new TheEnd();
    _theNether = new TheNether();
    _overworld = new Overworld();
}

void DefaultWorld::tick()
{
    World::tick();
    // TODO: Launch threads for all the dimensions
    _processingThreads.push_back(new std::thread(&Overworld::tick, _overworld));
    _processingThreads.push_back(new std::thread(&TheNether::tick, _theNether));
    _processingThreads.push_back(new std::thread(&TheEnd::tick, _theEnd));
}

void DefaultWorld::initialize()
{
    _theEnd->initialize();
    _theNether->initialize();
    _overworld->initialize();
}
