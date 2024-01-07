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

You can also use the docker-compose file to run the server using docker.

See **Building** section to know how to compile the server.

## Building

Currently **only Linux x86_64 and FreeBSD** are targeted, it might build on another system
but it isn't guaranted for now.

### Dependencies

Here is the list of dependencies required to build CubicServer:

 - gcc12/g++12 or clang15/clang++15 (Minimum versions, above should work too, but below will definitely not)
 - cmake (The build system)
 - make (Building system, you might work without but it is not tested)
 - pkgconf (Cmake package shenanigans)
 - git (Cloning deps)
 - libcurl-dev (Calling the Mojang API)
 - wget (For the bootstrap script)
 - python3 (Generating code)
 - zlib-dev (Compression)
 - boost-dev (Optional, will be cloned and built here if not present)

To install those dependencies you can see an example for Fedora 38 from our
[build image](https://github.com/CubicMC/cubic-runners/blob/master/Dockerfile)

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
#### Build from source with docker
To build with docker follow those steps :
```bash
git clone https://github.com/CubicMC/cubic-server
cd cubic-server
docker build --tag cubic-server .
docker compose up
```

## Contributing

Any contributions are welcome, if you don't know what to do you can take a look
at our issues tab and start talking in one of them to contribute :D.
