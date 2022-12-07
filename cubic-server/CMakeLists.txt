target_sources (${CMAKE_PROJECT_NAME} PRIVATE
        main.cpp
        Server.cpp
        Server.hpp
        Client.cpp
        Client.hpp
        Player.cpp
        Player.hpp
        Entity.cpp
        Entity.hpp
        Chat.cpp
        Chat.hpp
        WorldGroup.cpp
        WorldGroup.hpp
        World.cpp
        World.hpp
        Dimension.cpp
        Dimension.hpp
)

add_subdirectory (protocol)
add_subdirectory (default)
add_subdirectory (math)
add_subdirectory (configuration)
add_subdirectory (logging)
add_subdirectory (interface)
add_subdirectory (world-storage)