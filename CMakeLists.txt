cmake_minimum_required(VERSION 3.20.0)

if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.24.0)
    cmake_policy(SET CMP0135 OLD)
endif()

# Options
option(USE_CLANG "Build application with clang" OFF)
if (USE_CLANG)
    set(CMAKE_CXX_COMPILER /usr/bin/clang++)
    set(CMAKE_C_COMPILER /usr/bin/clang)
endif()

option(DEBUG_NETWORK "Print network messages" OFF)
if(DEBUG_NETWORK)
    add_compile_definitions(DEBUG_NETWORK)
endif()

option(NO_GUI "Build without GUI" OFF)
option(STATIC_LINK "Link the binary statically" OFF)

message(STATUS "Debugging network: ${DEBUG_NETWORK}")
message(STATUS "Building without GUI: ${NO_GUI}")
message(STATUS "Linking statically: ${STATIC_LINK}")

# This must be set before the project command
set(CMAKE_USER_MAKE_RULES_OVERRIDE_CXX ${CMAKE_CURRENT_SOURCE_DIR}/cxx_flag_overrides.cmake)
set(CMAKE_USER_MAKE_RULES_OVERRIDE_C ${CMAKE_CURRENT_SOURCE_DIR}/c_flag_overrides.cmake)

project(CubicServer VERSION 0.1.0 LANGUAGES CXX C)

set(MINECRAFT_VERSION "1.19.3")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(CheckIPOSupported)

# if debug mode is enabled, add -g3 flag
if (CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3 -rdynamic")
endif()#include "Plu

set(CMAKE_CXX_FLAGS "-rdynamic")

if (CMAKE_BUILD_TYPE MATCHES Release)
    check_ipo_supported(RESULT ipo_supported OUTPUT ipo_error)
    if (ipo_supported)
        set_property(GLOBAL PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
    else()
        message(STATUS "IPO / LTO not supported!")
    endif()
endif()

# Disable building of mbedtls programs
set(ENABLE_PROGRAMS OFF CACHE BOOL "" FORCE)
set(ENABLE_TESTING OFF CACHE BOOL "" FORCE)

set(FETCHCONTENT_QUIET OFF)

include(FetchContent)
include(boost.cmake)

FetchContent_Declare(
    yaml-cpp
    GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
    GIT_TAG 4ae4cb7309c07b2d8623d7e4f01efa6321441366 # The latest yaml-cpp commit at the time of writing.
    GIT_PROGRESS TRUE
)

FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.2
    GIT_PROGRESS TRUE
)

FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.11.0
    GIT_PROGRESS TRUE
)

FetchContent_Declare(
    noise
    GIT_REPOSITORY https://github.com/Reputeless/PerlinNoise.git
    GIT_TAG v3.0.0
    GIT_PROGRESS TRUE
)

FetchContent_Declare(
    nbt
    GIT_REPOSITORY https://github.com/CubicMC/libnbt.git
    GIT_TAG v1.0.1
    GIT_PROGRESS TRUE
)

FetchContent_Declare(
    argparse
    GIT_REPOSITORY https://github.com/p-ranav/argparse.git
    GIT_TAG v2.9
    GIT_PROGRESS TRUE
)

FetchContent_Declare(
    mbedtls
    GIT_REPOSITORY https://github.com/Mbed-TLS/mbedtls.git
    GIT_TAG v3.4.0
)

FetchContent_Declare(
    plugin-interface
    GIT_REPOSITORY https://github.com/CubicMC/plugin-interface.git
)

FetchContent_MakeAvailable(
    yaml-cpp
    json
    noise
    argparse
    nbt
    spdlog
    mbedtls
    plugin-interface
)

# Fix spdlog warnings
get_target_property(spdlog_include spdlog INTERFACE_INCLUDE_DIRECTORIES)
target_include_directories(spdlog SYSTEM INTERFACE ${spdlog_include})
target_compile_options(spdlog PUBLIC -Wno-array-bounds -Wno-stringop-overflow)

# Fix yaml-cpp warnings
get_target_property(yaml_cpp_include yaml-cpp INTERFACE_INCLUDE_DIRECTORIES)
target_include_directories(yaml-cpp SYSTEM INTERFACE ${yaml_cpp_include})

if(GTEST) # if the flag GTEST is true
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    FetchContent_Declare(
        rapidcheck
        GIT_REPOSITORY https://github.com/emil-e/rapidcheck.git
        GIT_TAG a5724ea5b0b00147109b0605c377f1e54c353ba2 # The latest rapidcheck commit at the time of writing.
    )
    option(RC_ENABLE_GTEST "Enable Google Test integration for RapidCheck library" ON)

    FetchContent_MakeAvailable(
        rapidcheck
        googletest
    )

    set(ENABLE_TESTING ON CACHE BOOL "" FORCE)
    enable_testing()
endif()

find_package(Threads REQUIRED)
find_package(CURL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM gtkmm-3.0)

if(NOT GTKMM_FOUND)
    message(WARNING "Gtkmm not found! Building without GUI.")
    set(NO_GUI ON)
endif()

add_executable(${CMAKE_PROJECT_NAME})
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
    PROGRAM_NAME="${CMAKE_PROJECT_NAME}"
    PROGRAM_VERSION="${CMAKE_PROJECT_VERSION}"
    MINECRAFT_VERSION="${MINECRAFT_VERSION}"
    GUI_UNAVAILABLE=$<BOOL:${NO_GUI}>
)

if (STATIC_LINK)
    target_link_libraries (${CMAKE_PROJECT_NAME} PRIVATE -static)
endif()

include(blocks.cmake)

add_subdirectory(cubic-server)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    ${noise_SOURCE_DIR}
    ${nbt_SOURCE_DIR}
    ${boost_SOURCE_DIR}
)

if (NOT NO_GUI)
    target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
        ${GTKMM_INCLUDE_DIRS}
    )
endif()

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC cubic-server ${Blocks_SOURCE_DIR})

target_link_libraries (${CMAKE_PROJECT_NAME} PRIVATE
    Blocks
    Threads::Threads
    nlohmann_json::nlohmann_json
    z
    argparse
    yaml-cpp
    MbedTLS::mbedtls
    spdlog::spdlog
    CURL::libcurl
    $<$<BOOL:${MINGW}>:ws2_32>
    $<$<NOT:$<BOOL:${Boost_FOUND}>>:Boost::asio>
    $<$<NOT:$<BOOL:${Boost_FOUND}>>:Boost::container>
    $<$<NOT:$<BOOL:${Boost_FOUND}>>:Boost::system>
    $<$<NOT:$<BOOL:${Boost_FOUND}>>:Boost::lockfree>
    $<$<NOT:$<BOOL:${Boost_FOUND}>>:Boost::circular_buffer>
    plugin-interface
)

if (CMAKE_BUILD_TYPE MATCHES RELWITHDEBINFO)
    target_link_libraries (${CMAKE_PROJECT_NAME} PRIVATE
        asan
        ubsan
    )
endif()

if (NOT NO_GUI)
    target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
        ${GTKMM_LIBRARIES}
    )
endif()
