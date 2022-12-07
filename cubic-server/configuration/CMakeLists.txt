# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found. Any number of sources could be listed here.
target_sources (${CMAKE_PROJECT_NAME} PRIVATE
        ConfigHandler.cpp
        ConfigHandler.hpp)

include(FetchContent)

FetchContent_Declare(yaml-cpp
  GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
  GIT_TAG 4ae4cb7309c07b2d8623d7e4f01efa6321441366)  # The latest yaml-cpp commit at the time of writing.
FetchContent_GetProperties(yaml-cpp)

if(NOT yaml-cpp_POPULATED)
  message(STATUS "Fetching yaml-cpp...")
  FetchContent_Populate(yaml-cpp)
  add_subdirectory(${yaml-cpp_SOURCE_DIR} ${yaml-cpp_BINARY_DIR})
endif()

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC yaml-cpp::yaml-cpp)
