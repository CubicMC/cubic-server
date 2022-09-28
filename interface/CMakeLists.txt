# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found. Any number of sources could be listed here.
add_library (ManagementInterface ManagementInterface.cpp)

# Use the package PkgConfig to detect GTK+ headers/library files
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

target_link_libraries(ManagementInterface PRIVATE ${GTKMM_LIBRARIES})

# Add other flags to the compiler
# target_compile_definitions(ManagementInterface PRIVATE ${GTKMM_CFLAGS_OTHER})

target_include_directories(ManagementInterface PRIVATE ${GTKMM_INCLUDE_DIRS})
target_link_libraries(ManagementInterface PRIVATE ${GTKMM_LIBRARY_DIRS})

# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
target_include_directories (ManagementInterface PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})