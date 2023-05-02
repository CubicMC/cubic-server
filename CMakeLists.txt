cmake_minimum_required(VERSION 3.14.0)

if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.24.0)
    cmake_policy(SET CMP0135 OLD)
endif()

project(CubicServer VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(CheckIPOSupported)

# if debug mode is enabled, add -g3 flag
if (CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3")
endif()

if (CMAKE_BUILD_TYPE MATCHES Release)
    check_ipo_supported()
    set_property(GLOBAL PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
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
    URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz
)

FetchContent_Declare(
    noise
    GIT_REPOSITORY https://github.com/Reputeless/PerlinNoise.git
    GIT_TAG v3.0.0
)

FetchContent_Declare(
    argparse
    GIT_REPOSITORY https://github.com/p-ranav/argparse.git
)

FetchContent_Declare(
    CRCpp
    GIT_REPOSITORY https://github.com/d-bahr/CRCpp.git
    GIT_TAG release-1.2.0.0
)

FetchContent_MakeAvailable(
    yaml-cpp
    json
    noise
    argparse
    CRCpp
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
    )
    option(RC_ENABLE_GTEST "Enable Google Test integration for RapidCheck library" ON)
    set(RC_ENABLE_GTEST TRUE)

    FetchContent_MakeAvailable(
        rapidcheck
        googletest
    )
endif()

if(GTEST)
    enable_testing()
endif()

set(CMAKE_BUILD_RPATH /usr/local/lib/gcc12)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

find_package(Threads REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

add_executable(${CMAKE_PROJECT_NAME})
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -Wall -Wextra -Wno-unknown-pragmas -Wno-restrict -Wno-missing-field-initializers)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
    PROGRAM_NAME="${CMAKE_PROJECT_NAME}"
    PROGRAM_VERSION="${CMAKE_PROJECT_VERSION}"
)
add_subdirectory(cubic-server)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    ${GTKMM_INCLUDE_DIRS}
    ${noise_SOURCE_DIR}
)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC cubic-server)
target_link_libraries (${CMAKE_PROJECT_NAME} PRIVATE
    Blocks
    Threads::Threads
    nlohmann_json::nlohmann_json
    ${GTKMM_LIBRARIES}
    argparse
    yaml-cpp
    curl
    CRCpp
)
