if (NOT NO_GUI)
    target_sources (${CMAKE_PROJECT_NAME} PRIVATE
        ManagementInterface.cpp
        ManagementInterface.hpp
        LogsInterface.cpp
        LogsInterface.hpp
        PlayersInterface.cpp
        PlayersInterface.hpp
        InterfaceContainer.cpp
        InterfaceContainer.hpp
    )
endif()
