cmake_minimum_required(VERSION 3.14.0)

if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.24.0)
    cmake_policy(SET CMP0135 OLD)
endif()

option(USE_CLANG "Build application with clang" OFF)
if (USE_CLANG)
    set(CMAKE_CXX_COMPILER /usr/bin/clang++)
    set(CMAKE_C_COMPILER /usr/bin/clang)
endif()

set(CMAKE_USER_MAKE_RULES_OVERRIDE_CXX ${CMAKE_CURRENT_SOURCE_DIR}/cxx_flag_overrides.cmake)

project(CubicServer VERSION 0.1.0 LANGUAGES CXX)

set(MINECRAFT_VERSION "1.19.3")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(CheckIPOSupported)

if (CMAKE_BUILD_TYPE MATCHES Release)
    check_ipo_supported(RESULT ipo_supported OUTPUT ipo_error)
    if (ipo_supported)
        set_property(GLOBAL PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
    else()
        message(STATUS "IPO / LTO not supported!")
    endif()
endif()

include(FetchContent)

FetchContent_Declare(
    yaml-cpp
    GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
    GIT_TAG 4ae4cb7309c07b2d8623d7e4f01efa6321441366 # The latest yaml-cpp commit at the time of writing.
)
# FetchContent_GetProperties(yaml-cpp)

# if(NOT yaml-cpp_POPULATED)
#     message(STATUS "Fetching yaml-cpp...")
#     FetchContent_Populate(yaml-cpp)
#     add_subdirectory(${yaml-cpp_SOURCE_DIR} ${yaml-cpp_BINARY_DIR})
# endif()

FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.2
)

FetchContent_Declare(
    noise
    GIT_REPOSITORY https://github.com/Reputeless/PerlinNoise.git
    GIT_TAG v3.0.0
)

FetchContent_Declare(
    argparse
    GIT_REPOSITORY https://github.com/p-ranav/argparse.git
    GIT_TAG v2.9
)

FetchContent_MakeAvailable(
    yaml-cpp
    json
    noise
    argparse
)

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
endif()

if(GTEST)
    enable_testing()
endif()

# set(CMAKE_BUILD_RPATH /usr/local/lib/gcc12)
# set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

find_package(Threads REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM gtkmm-3.0)

option(NO_GUI "Build without GUI" OFF)
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

include(blocks.cmake)

add_subdirectory(cubic-server)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    ${GTKMM_INCLUDE_DIRS}
    ${noise_SOURCE_DIR}
)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC cubic-server ${Blocks_SOURCE_DIR})

target_link_libraries (${CMAKE_PROJECT_NAME} PRIVATE
    Blocks
    Threads::Threads
    nlohmann_json::nlohmann_json
    z
    argparse
    yaml-cpp
)

if (NOT NO_GUI)
    target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
        ${GTKMM_LIBRARIES}
    )
endif()
