target_sources (${CMAKE_PROJECT_NAME} PRIVATE
        ServerPackets.cpp
        ServerPackets.hpp
        ClientPackets.cpp
        ClientPackets.hpp
        common.hpp
        ParseExceptions.hpp
        typeSerialization.hpp
        WorldEvent.hpp
)

add_subdirectory(serialization)
