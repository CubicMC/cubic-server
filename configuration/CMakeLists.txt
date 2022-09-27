# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found. Any number of sources could be listed here.
add_library (ConfigHandler ConfigHandler.cpp)

################ Find yaml-cpp ################

find_package (PkgConfig REQUIRED)

pkg_search_module (yaml-cpp_PC yaml-cpp)

find_library (yaml-cpp_LIBRARY
  NAMES yaml-cpp
  HINTS
    ${yaml-cpp_PC_LIBDIR}
    ${yaml-cpp_PC_LIBRARY_DIRS})

find_path (yaml-cpp_INCLUDE_DIR
  NAMES yaml-cpp/yaml.h
  PATH_SUFFIXES yaml-cpp
  HINTS
    ${yaml-cpp_PC_INCLUDEDIR}
    ${yaml-cpp_PC_INCLUDE_DIRS})

mark_as_advanced (
  yaml-cpp_LIBRARY
  yaml-cpp_INCLUDE_DIR)

include (FindPackageHandleStandardArgs)

find_package_handle_standard_args (yaml-cpp
  REQUIRED_VARS
    yaml-cpp_LIBRARY
    yaml-cpp_INCLUDE_DIR
  VERSION_VAR yaml-cpp_PC_VERSION)

set (yaml-cpp_LIBRARIES ${yaml-cpp_LIBRARY})
set (yaml-cpp_INCLUDE_DIRS ${yaml-cpp_INCLUDE_DIR})

if (yaml-cpp_FOUND AND NOT (TARGET yaml-cpp::yaml-cpp))
  add_library (yaml-cpp::yaml-cpp UNKNOWN IMPORTED)

  set_target_properties (yaml-cpp::yaml-cpp
    PROPERTIES
      IMPORTED_LOCATION ${yaml-cpp_LIBRARY}
      INTERFACE_INCLUDE_DIRECTORIES ${yaml-cpp_INCLUDE_DIRS})
endif ()

################################################


# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
target_include_directories (ConfigHandler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})