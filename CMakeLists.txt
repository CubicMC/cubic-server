cmake_minimum_required (VERSION 3.14.0)
project (CubicServer)

set(CMAKE_CXX_STANDARD 20)

# if debug mode is enabled, add -g3 flag
if (CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3")
endif()

include(FetchContent)

FetchContent_Declare(
  json
  URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz
)
FetchContent_MakeAvailable(json)

FetchContent_Declare(
    argparse
    GIT_REPOSITORY https://github.com/p-ranav/argparse.git
)
FetchContent_MakeAvailable(argparse)

if(GTEST) # if the flag GTEST is true
  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
  )
  # For Windows: Prevent overriding the parent project's compiler/linker settings
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  FetchContent_MakeAvailable(googletest)
endif()

if(GTEST)
  enable_testing()
endif()

set(CMAKE_BUILD_RPATH /usr/local/lib/gcc12)

find_package(Threads REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

add_executable(${CMAKE_PROJECT_NAME})
add_subdirectory(cubic-server)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${GTKMM_INCLUDE_DIRS})
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC cubic-server)
target_link_libraries (${CMAKE_PROJECT_NAME} PRIVATE
        Threads::Threads
        nlohmann_json::nlohmann_json
        ${GTKMM_LIBRARIES}
        argparse
)
