target_sources (${CMAKE_PROJECT_NAME} PRIVATE
    ClientPackets.cpp
    ClientPackets.hpp
    common.hpp
    metadata.hpp
    metadata.cpp
    PacketUtils.hpp
    ParseExceptions.hpp
    ServerPackets.cpp
    ServerPackets.hpp
    Structures.cpp
    Structures.hpp
    typeSerialization.hpp
    WorldEvent.hpp
)

add_subdirectory(serialization)
add_subdirectory(container)
