// CubicServer - A fast and extensible reimplementation of Minecraft's server
// Copyright (C) 2024 - CubicServer contributors
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

const std = @import("std");
const logz = @import("logz");

// TODO: This needs to be overridable by the build system
const csmc_version = "dev";

pub fn main() !void {
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    defer _ = gpa.deinit();
    const allocator = gpa.allocator();

    // Taken straight from the README
    // https://github.com/karlseguin/log.zig/blob/c927400c5f2dff63b0f09587949371289e3dec22/readme.md
    try logz.setup(allocator, .{
        .level = .Debug,
        .pool_size = 100,
        .buffer_size = 4096,
        .large_buffer_count = 8,
        .large_buffer_size = 16384,
        .output = .stdout,
        .encoding = .logfmt,
    });
    defer logz.deinit();

    logz.debug().ctx("Logger initialized successfully").log();
    logz.info().ctx("Starting cubic-server").stringSafe("version", csmc_version).log();

    const raw_bind_address = try comptime std.net.Ip4Address.parse("0.0.0.0", 25565);
    const bind_address = std.net.Address{ .in = raw_bind_address };
    var server = std.net.StreamServer.init(std.net.StreamServer.Options{
        .reuse_port = true,
    });
    defer server.deinit();

    try server.listen(bind_address);

    const addr = server.listen_address;
    logz.info().ctx("Server started").int("port", addr.getPort()).log();

    while (true) {
        var client = try server.accept();
        defer client.stream.close();

        logz.debug().ctx("New connection").log();

        const message = try client.stream.reader().readAllAlloc(allocator, 1024);
        defer allocator.free(message);

        logz.info().stringSafe("Data from client", message).log();
    }
}
