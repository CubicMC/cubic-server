# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 3.14.0)
project (CubicServer)

set(CMAKE_CXX_FLAGS_DEBUG  "-g3")

set(CMAKE_CXX_STANDARD 14)

if (NOT GTEST)
  message(WARNING
                " GTEST flag set to false or not set\n"
                " disable gtest compilation\n"
                " use -D GTEST=true to enable it"
  )
  set(GTEST false)
endif()

if(GTEST) # if the flag GTEST is true
  include(FetchContent)
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

if(GTEST)
  enable_testing()
endif()