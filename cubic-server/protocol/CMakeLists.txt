target_sources (${CMAKE_PROJECT_NAME} PRIVATE
        ServerPackets.cpp
        ServerPackets.hpp
        ClientPackets.cpp
        ClientPackets.hpp
        common.hpp
        ParseExceptions.hpp
        typeSerialization.hpp
        serialization/add.hpp
        serialization/addPrimaryType.hpp
        serialization/pop.hpp
        serialization/popPrimaryType.hpp
)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
