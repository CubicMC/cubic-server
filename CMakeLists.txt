cmake_minimum_required (VERSION 3.14.0)
project (CubicServer)

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
    json
    URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz
)
FetchContent_MakeAvailable(json)

FetchContent_Declare(
    noise
    GIT_REPOSITORY https://github.com/Reputeless/PerlinNoise.git
    GIT_TAG v3.0.0
)
FetchContent_MakeAvailable(noise)

FetchContent_Declare(
    argparse
    GIT_REPOSITORY https://github.com/p-ranav/argparse.git
)
FetchContent_MakeAvailable(argparse)

FetchContent_Declare(
    CRCpp
    GIT_REPOSITORY https://github.com/d-bahr/CRCpp.git
    GIT_TAG release-1.2.0.0
)
FetchContent_MakeAvailable(CRCpp)

if(GTEST) # if the flag GTEST is true
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    FetchContent_Declare(
        rapidcheck
        GIT_REPOSITORY https://github.com/emil-e/rapidcheck.git
    )
    set(RC_ENABLE_GTEST TRUE)
    FetchContent_MakeAvailable(rapidcheck)
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
    curl
    CRCpp
)

# if(GTEST)
#     target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE rapidcheck rapidcheck_gtest)
#     target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${rapidcheck_SOURCE_DIR}/extras/gtest/include)
# endif()
