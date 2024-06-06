# Cubic Server

A fast and extensible C++ implementation of Minecraft's server.

## Status

This project is currently undergoing a complete rewrite and is therefore not
usable at all in its current state, if you wish to use the previous "working"
version switch to the master branch of this repo and follow the instructions
there.

## Goals

The version currently targeted is **1.20.6**, but future versions may
be implemented depending on how well Cubic Server gets developed.

Older versions might be maintained too but the support is not quite planned yet.

The principal points we want to target are better performances, since Minecraft's
server performance is going downhill since 1.13, but also proper extensibility
without needing a third-party to implement changes into the server downstream
(Such as spigot for example).

## Running

Precompiled binaries are not currently available.

See **Building** section to know how to compile the server.

## Building

Currently **only Linux x86_64** is targeted, it might build on another system
but it isn't guaranted for now (Windows, FreeBSD and OpenBSD will be supported
later down the road, but not until we have a solid codebase.)

### Dependencies

Here is the list of dependencies required to build CubicServer:

 - gcc7\* (Any c++17 compliant compiler should work but it is not guarranted as
 we do not code strictly to the standard)
 - gnumake (Build system)

\* gcc7 is the lowest version that should work with this codebase but it has
not been tested yet, a higher compiler version will always be recommended for
optimization reasons. See the gcc c++17 feature matrix
[here](https://gcc.gnu.org/projects/cxx-status.html#cxx17).

### How to build
#### Build from source on your machine
To build follow those steps :
```bash
git clone https://github.com/CubicMC/cubic-server
cd cubic-server
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=RELEASE ..
make -j `nproc` # The "-j `nproc`" is here to speed-up the compilation
```
#### Build from source with nix
To build with docker follow those steps :
```bash
nix build github:CubicMC/cubic-server/rewrite
```

## Contributing

Any contributions are welcome, if you don't know what to do you can take a look
at our issues tab and start talking in one of them to contribute :D.
