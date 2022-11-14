#include "World.hpp"

void World::tick()
{
    for (auto & _processingThread : _processingThreads)
        if (!_processingThread->joinable()) {
            free(_processingThread);
            _processingThread = nullptr;
        }

    std::remove_if(_processingThreads.begin(),
                   _processingThreads.end(),
                   [](const std::thread *cli)
                   { return cli == nullptr; });
}