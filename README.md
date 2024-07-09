# Cubic Server

A fast and extensible implementation of Minecraft's server.

## Status

This project is currently undergoing a complete rewrite and is therefore not
usable at all in its current state, if you wish to use the previous "working"
version switch to the master branch of this repo and follow the instructions
there.

## Goals

The version currently targeted is **1.21**, but future versions may
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

 - zig 0.13.0

### How to build
#### Build from source on your machine
To build follow those steps :
```bash
git clone https://github.com/CubicMC/cubic-server
cd cubic-server
zig build
```

## Contributing

Any contributions are welcome, if you don't know what to do you can take a look
at our issues tab and start talking in one of them to contribute :D.
