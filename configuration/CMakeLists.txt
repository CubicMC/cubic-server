# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found. Any number of sources could be listed here.
add_library (ConfigHandler ConfigHandler.cpp)

# include(ExternalProject)
# set(YAML_LIB yaml-cpp)
# ExternalProject_Add(
#     yaml-cpp
#     SOURCE_DIR ${PROJECT_SOURCE_DIR}/${YAML_LIB}
#     GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git

#     # CONFIGURE_COMMAND cmake ../${YAML_LIB}
#     # BUILD_COMMAND cmake --build .
#     # INSTALL_COMMAND cmake --install . --prefix ${PROJECT_SOURCE_DIR}
#     # UPDATE_COMMAND ""
# )
# add_dependencies(yaml-cpp yaml-cpp)

# find_package(yaml-cpp REQUIRED)

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

target_link_libraries(ConfigHandler PUBLIC yaml-cpp::yaml-cpp)


# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
target_include_directories (ConfigHandler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})