# Add executable called "helloDemo" that is built from the source files
# "demo.cxx" and "demo_b.cxx". The extensions are automatically found.
add_executable (cubic-server main.cpp Server.cpp Client.cpp)

find_package(Threads REQUIRED)

# Link the executable to the Hello library. Since the Hello library has
# public include directories we will use those link directories when building
# helloDemo
target_link_libraries (cubic-server PRIVATE Protocol Threads::Threads Logging)
