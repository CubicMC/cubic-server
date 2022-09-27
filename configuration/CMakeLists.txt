# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found. Any number of sources could be listed here.
add_library (ConfigHandler ConfigHandler.cpp)

find_package(yaml-cpp REQUIRED)
include_directories(${YAML_INCLUDE_DIRS})
target_link_libraries(${YAML_CPP_LIBRARIES})


# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
target_include_directories (ConfigHandler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})