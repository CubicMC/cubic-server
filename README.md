# Cubic Server

A fast and extensible C++ implementation of Minecraft's server.

## Status

This project is before anything a school project, therefore it is in its
early stage and not a lot works for now. Most of the stuff made here could also
already exists somewhere else but reimplemented here for the sake of having
something to work on. I would therefore not recommend anyone using it
for now, but **contributions are more than welcome** ;).

## Goals

The version currently targeted is **1.19.3**, but future versions may
be implemented depending on how well Cubic Server gets developed.

The principal points we want to target are better performances, since Minecraft's
server performance is going downhill since 1.13, but also proper extensibility
without needing a third-party to implement changes into the server downstream
(Such as spigot for example).

## Running

Precompiled binaries are currently available [here](https://github.com/CubicMC/cubic-server/releases).

See **Building** section to know how to compile the server.

## Building

Currently **only Linux x86_64 and FreeBSD** are targeted, it might build on another system
but it isn't guaranted for now.

To build follow those steps :
```bash
git clone https://github.com/CubicMC/cubic-server
cd cubic-server
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=RELEASE ..
make -j `nproc` # The "-j `nproc`" is here to speed-up the compilation
```

## Contributing

Any contributions are welcome, if you don't know what to do you can take a look
at our issues tab and start talking in one of them to contribute :D.
