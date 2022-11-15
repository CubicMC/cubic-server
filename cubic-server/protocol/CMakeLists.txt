# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found. Any number of sources could be listed here.
target_sources (${CMAKE_PROJECT_NAME} PRIVATE
        ServerPackets.cpp
        ClientPackets.cpp
        common.hpp
)
