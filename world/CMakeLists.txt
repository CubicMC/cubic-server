# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found. Any number of sources could be listed here.
# add_library (TimeFormatter TimeFormatter.cpp)
# add_library (FileAndFolderHandler FileAndFolderHandler.cpp)
add_library (World ChunkColumn.cpp Level.cpp LevelData.cpp World.cpp)

# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
# target_include_directories (TimeFormatter PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# target_include_directories (FileAndFolderHandler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories (World PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})