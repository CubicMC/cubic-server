cmake_minimum_required (VERSION 3.14.0)
project (CubicServer)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
  json
  URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz
)
FetchContent_MakeAvailable(json)

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

# Recurse into the "Hello" and "Demo" subdirectories. This does not actually
# cause another cmake executable to run. The same process will walk through
# the project's entire directory structure.
# add_subdirectory (tests)
add_subdirectory (protocol)
add_subdirectory (cubic-server)
add_subdirectory (math)
add_subdirectory (configuration)
add_subdirectory (logging)
add_subdirectory (interface)
add_subdirectory (world-storage)

if(GTEST)
  enable_testing()
endif()

find_package(Threads REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

add_executable(${CMAKE_PROJECT_NAME})
add_subdirectory(cubic-server)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${GTKMM_INCLUDE_DIRS})
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC cubic-server)
target_link_libraries (${CMAKE_PROJECT_NAME} PRIVATE
        Threads::Threads
        nlohmann_json::nlohmann_json
        ${GTKMM_LIBRARIES}
)
