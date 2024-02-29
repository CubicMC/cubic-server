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

        while (true) {
            var buffer: [1024]u8 = undefined;
            var client_buffer = std.ArrayList(u8).init(allocator);
            const read_len = try client.stream.reader().read(&buffer);

            if (read_len == 0)
                break;
            logz.info().stringSafe("Data from client", buffer[0..read_len]).log();
            try client_buffer.appendSlice(buffer[0..read_len]);
            var len_parsed: u32 = undefined;
            var packet_length: i32 = undefined;
            len_parsed = parse_varint_to(client_buffer.items, &packet_length) catch continue;
            logz.info().int("len_parsed", len_parsed).int("packet_length", packet_length).log();
        }
    }
}

fn parse_varint_to(buffer: []const u8, value: *i32) !u32 {
    const SEGMENT_BITS: u8 = 0x7F;
    const CONTINUE_BIT: u8 = 0x80;

    var position: u5 = 0;
    var byte_position: u8 = 0;
    value.* = 0;

    while (true) {
        if (buffer.len <= byte_position)
            return error.Overflow;
        const currentByte = buffer[byte_position];
        const correct_byte: u32 = currentByte & SEGMENT_BITS;
        value.* |= @intCast(correct_byte << position);

        if ((currentByte & CONTINUE_BIT) == 0) break;

        if (byte_position >= 4)
            return error.Overflow;

        position += 7;
        byte_position += 1;
    }

    byte_position += 1;
    return byte_position;
}

const expect = @import("std").testing.expect;
const expectError = @import("std").testing.expectError;
const expectEqual = @import("std").testing.expectEqual;

test "simple_1_byte_varint" {
    const buffer = [_]u8{0x0A};
    var value: i32 = undefined;
    const len_parsed = try parse_varint_to(&buffer, &value);
    const expected_len_parsed: u32 = 1;
    const expected_value: i32 = 10;
    try expectEqual(expected_len_parsed, len_parsed);
    try expectEqual(expected_value, value);
}

test "simple_2_byte_varint" {
    const buffer = [_]u8{ 0x8A, 0x01 };
    var value: i32 = undefined;
    const len_parsed = try parse_varint_to(&buffer, &value);
    const expected_len_parsed: u32 = 2;
    const expected_value: i32 = 0x8A;
    try expectEqual(expected_len_parsed, len_parsed);
    try expectEqual(expected_value, value);
}

test "simple_4_byte_varint" {
    const buffer = [_]u8{ 0x8A, 0x81, 0x80, 0x00 };
    var value: i32 = undefined;
    const len_parsed = try parse_varint_to(&buffer, &value);
    const expected_len_parsed: u32 = 4;
    const expected_value: i32 = 0x8A;
    try expectEqual(expected_len_parsed, len_parsed);
    try expectEqual(expected_value, value);
}

test "simple_5_byte_varint" {
    const buffer = [_]u8{ 0x8A, 0x81, 0x80, 0x80, 0x00 };
    var value: i32 = undefined;
    const len_parsed = try parse_varint_to(&buffer, &value);
    const expected_len_parsed: u32 = 5;
    const expected_value: i32 = 0x8A;
    try expectEqual(expected_len_parsed, len_parsed);
    try expectEqual(expected_value, value);
}

test "6_byte_varint" {
    const buffer = [_]u8{ 0x8A, 0x81, 0x80, 0x80, 0x80, 0x00 };
    var value: i32 = undefined;
    try expectError(error.Overflow, parse_varint_to(&buffer, &value));
}

fn parse_string_to(buffer: []const u8, value: []u8) !u32 {
    _ = value;
    _ = buffer;
}

fn parse_ushort_to(buffer: []const u8, value: *u16) !u32 {
    if (buffer.len < 2)
        return error.Overflow;
    value.* = @as(u16, @intCast(buffer[1])) | (@as(u16, @intCast(buffer[0])) << 8);
    return 2;
}

test "simple_ushort_256" {
    const buffer = [_]u8{ 0x01, 0x00 };
    var value: u16 = undefined;
    const len_parsed = try parse_ushort_to(&buffer, &value);
    const expected_len_parsed: u32 = 2;
    const expected_value: u16 = 0x0100;
    try expectEqual(expected_len_parsed, len_parsed);
    try expectEqual(expected_value, value);
}

test "simple_ushort_1" {
    const buffer = [_]u8{ 0x00, 0x01 };
    var value: u16 = undefined;
    const len_parsed = try parse_ushort_to(&buffer, &value);
    const expected_len_parsed: u32 = 2;
    const expected_value: u16 = 0x0001;
    try expectEqual(expected_len_parsed, len_parsed);
    try expectEqual(expected_value, value);
}

test "ushort_not_enough_data" {
    const buffer = [_]u8{0x42};
    var value: u16 = undefined;
    try expectError(error.Overflow, parse_ushort_to(&buffer, &value));
}
