/*
  libnbt
  Written in 2019 by IDidMakeThat
  Forked by CubicServer

  To the extent possible under law, the author(s) have dedicated all copyright
  and related and neighboring rights to this software to the public domain
  worldwide. This software is distributed without any warranty.

  You should have received a copy of the CC0 Public Domain Dedication along
  with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
*/

#ifndef NBT_H
#define NBT_H

#ifdef __cplusplus
extern "C" {
#endif

#define LIBNBT_VERSION 10
#define LIBNBT_NBT_VERSION 19133

#include <stddef.h>

#ifndef NBT_NO_STDLIB
#include <stdlib.h>
#include <string.h>
#define NBT_MALLOC malloc
#define NBT_REALLOC realloc
#define NBT_FREE free
#define NBT_MEMCPY memcpy
#define NBT_MEMCMP memcmp
#endif

#ifndef NBT_NO_STDINT
#include <stdint.h>
#endif

#include <zlib.h>

#ifndef Z_DEFAULT_WINDOW_BITS
#define Z_DEFAULT_WINDOW_BITS 15
#endif

#ifndef NBT_BUFFER_SIZE
#define NBT_BUFFER_SIZE 32768
#endif

#define NBT_COMPRESSION_LEVEL 9

typedef enum {
    NBT_TYPE_END,
    NBT_TYPE_BYTE,
    NBT_TYPE_SHORT,
    NBT_TYPE_INT,
    NBT_TYPE_LONG,
    NBT_TYPE_FLOAT,
    NBT_TYPE_DOUBLE,
    NBT_TYPE_BYTE_ARRAY,
    NBT_TYPE_STRING,
    NBT_TYPE_LIST,
    NBT_TYPE_COMPOUND,
    NBT_TYPE_INT_ARRAY,
    NBT_TYPE_LONG_ARRAY,
    NBT_NO_OVERRIDE // Only used internally.
} nbt_tag_type_t;

typedef struct nbt_tag_t nbt_tag_t;

struct nbt_tag_t {

    nbt_tag_type_t type;

    char *name;
    size_t name_size;

    union {
        struct {
            int8_t value;
        } tag_byte;
        struct {
            int16_t value;
        } tag_short;
        struct {
            int32_t value;
        } tag_int;
        struct {
            int64_t value;
        } tag_long;
        struct {
            float value;
        } tag_float;
        struct {
            double value;
        } tag_double;
        struct {
            int8_t *value;
            size_t size;
        } tag_byte_array;
        struct {
            char *value;
            size_t size;
        } tag_string;
        struct {
            nbt_tag_t **value;
            nbt_tag_type_t type;
            size_t size;
        } tag_list;
        struct {
            nbt_tag_t **value;
            size_t size;
        } tag_compound;
        struct {
            int32_t *value;
            size_t size;
        } tag_int_array;
        struct {
            int64_t *value;
            size_t size;
        } tag_long_array;
    };
};

typedef struct {
    size_t (*read)(void *userdata, uint8_t *data, size_t size);
    void *userdata;
} nbt_reader_t;

typedef struct {
    size_t (*write)(void *userdata, uint8_t *data, size_t size);
    void *userdata;
} nbt_writer_t;

typedef enum {
    NBT_PARSE_FLAG_USE_GZIP = 1,
    NBT_PARSE_FLAG_USE_ZLIB = 2,
    NBT_PARSE_FLAG_USE_RAW = 3,
} nbt_parse_flags_t;

typedef enum {
    NBT_WRITE_FLAG_USE_GZIP = 1,
    NBT_WRITE_FLAG_USE_ZLIB = 2,
    NBT_WRITE_FLAG_USE_RAW = 3
} nbt_write_flags_t;

nbt_tag_t *nbt_parse(nbt_reader_t reader, int parse_flags);
void nbt_write(nbt_writer_t writer, nbt_tag_t *tag, int write_flags);

nbt_tag_t *nbt_new_tag_byte(int8_t value);
nbt_tag_t *nbt_new_tag_short(int16_t value);
nbt_tag_t *nbt_new_tag_int(int32_t value);
nbt_tag_t *nbt_new_tag_long(int64_t value);
nbt_tag_t *nbt_new_tag_float(float value);
nbt_tag_t *nbt_new_tag_double(double value);
nbt_tag_t *nbt_new_tag_byte_array(int8_t *value, size_t size);
nbt_tag_t *nbt_new_tag_string(const char *value, size_t size);
nbt_tag_t *nbt_new_tag_list(nbt_tag_type_t type);
nbt_tag_t *nbt_new_tag_compound(void);
nbt_tag_t *nbt_new_tag_int_array(int32_t *value, size_t size);
nbt_tag_t *nbt_new_tag_long_array(int64_t *value, size_t size);

void nbt_set_tag_name(nbt_tag_t *tag, const char *name, size_t size);

void nbt_tag_list_append(nbt_tag_t *list, nbt_tag_t *value);
nbt_tag_t *nbt_tag_list_get(nbt_tag_t *tag, size_t index);
void nbt_tag_compound_append(nbt_tag_t *compound, nbt_tag_t *value);
nbt_tag_t *nbt_tag_compound_get(nbt_tag_t *tag, const char *key);
nbt_tag_t *nbt_tag_compound_getidx(nbt_tag_t *tag, size_t index);

void nbt_free_tag(nbt_tag_t *tag);

#ifdef __cplusplus
}
#endif

#endif

#ifdef NBT_IMPLEMENTATION

typedef struct {
    uint8_t *buffer;
    size_t buffer_offset;
} nbt__read_stream_t;

static uint8_t nbt__get_byte(nbt__read_stream_t *stream) { return stream->buffer[stream->buffer_offset++]; }

static int16_t nbt__get_int16(nbt__read_stream_t *stream)
{
    uint8_t bytes[2];
    for (int i = 1; i >= 0; i--) {
        bytes[i] = nbt__get_byte(stream);
    }
    return *(int16_t *) (bytes);
}

static int32_t nbt__get_int32(nbt__read_stream_t *stream)
{
    uint8_t bytes[4];
    for (int i = 3; i >= 0; i--) {
        bytes[i] = nbt__get_byte(stream);
    }
    return *(int32_t *) (bytes);
}

static int64_t nbt__get_int64(nbt__read_stream_t *stream)
{
    uint8_t bytes[8];
    for (int i = 7; i >= 0; i--) {
        bytes[i] = nbt__get_byte(stream);
    }
    return *(int64_t *) (bytes);
}

static float nbt__get_float(nbt__read_stream_t *stream)
{
    uint8_t bytes[4];
    for (int i = 3; i >= 0; i--) {
        bytes[i] = nbt__get_byte(stream);
    }
    return *(float *) (bytes);
}

static double nbt__get_double(nbt__read_stream_t *stream)
{
    uint8_t bytes[8];
    for (int i = 7; i >= 0; i--) {
        bytes[i] = nbt__get_byte(stream);
    }
    return *(double *) (bytes);
}

static nbt_tag_t *nbt__parse(nbt__read_stream_t *stream, int parse_name, nbt_tag_type_t override_type)
{

    nbt_tag_t *tag = (nbt_tag_t *) NBT_MALLOC(sizeof(nbt_tag_t));

    if (override_type == NBT_NO_OVERRIDE) {
        tag->type = (nbt_tag_type_t) nbt__get_byte(stream);
    } else {
        tag->type = override_type;
    }

    if (parse_name && tag->type != NBT_TYPE_END) {
        tag->name_size = nbt__get_int16(stream);
        tag->name = (char *) NBT_MALLOC(tag->name_size + 1);
        for (size_t i = 0; i < tag->name_size; i++) {
            tag->name[i] = nbt__get_byte(stream);
        }
        tag->name[tag->name_size] = '\0';
    } else {
        tag->name = NULL;
        tag->name_size = 0;
    }

    switch (tag->type) {
    case NBT_TYPE_END: {
        // Don't do anything.
        break;
    }
    case NBT_TYPE_BYTE: {
        tag->tag_byte.value = nbt__get_byte(stream);
        break;
    }
    case NBT_TYPE_SHORT: {
        tag->tag_short.value = nbt__get_int16(stream);
        break;
    }
    case NBT_TYPE_INT: {
        tag->tag_int.value = nbt__get_int32(stream);
        break;
    }
    case NBT_TYPE_LONG: {
        tag->tag_long.value = nbt__get_int64(stream);
        break;
    }
    case NBT_TYPE_FLOAT: {
        tag->tag_float.value = nbt__get_float(stream);
        break;
    }
    case NBT_TYPE_DOUBLE: {
        tag->tag_double.value = nbt__get_double(stream);
        break;
    }
    case NBT_TYPE_BYTE_ARRAY: {
        tag->tag_byte_array.size = nbt__get_int32(stream);
        tag->tag_byte_array.value = (int8_t *) NBT_MALLOC(tag->tag_byte_array.size);
        for (size_t i = 0; i < tag->tag_byte_array.size; i++) {
            tag->tag_byte_array.value[i] = nbt__get_byte(stream);
        }
        break;
    }
    case NBT_TYPE_STRING: {
        tag->tag_string.size = nbt__get_int16(stream);
        tag->tag_string.value = (char *) NBT_MALLOC(tag->tag_string.size + 1);
        for (size_t i = 0; i < tag->tag_string.size; i++) {
            tag->tag_string.value[i] = nbt__get_byte(stream);
        }
        tag->tag_string.value[tag->tag_string.size] = '\0';
        break;
    }
    case NBT_TYPE_LIST: {
        tag->tag_list.type = (nbt_tag_type_t) nbt__get_byte(stream);
        tag->tag_list.size = nbt__get_int32(stream);
        tag->tag_list.value = (nbt_tag_t **) NBT_MALLOC(tag->tag_list.size * sizeof(nbt_tag_t *));
        for (size_t i = 0; i < tag->tag_list.size; i++) {
            tag->tag_list.value[i] = nbt__parse(stream, 0, tag->tag_list.type);
        }
        break;
    }
    case NBT_TYPE_COMPOUND: {
        tag->tag_compound.size = 0;
        tag->tag_compound.value = NULL;
        for (;;) {
            nbt_tag_t *inner_tag = nbt__parse(stream, 1, NBT_NO_OVERRIDE);

            if (inner_tag->type == NBT_TYPE_END) {
                nbt_free_tag(inner_tag);
                break;
            } else {
                tag->tag_compound.value = (nbt_tag_t **) NBT_REALLOC(tag->tag_compound.value, (tag->tag_compound.size + 1) * sizeof(nbt_tag_t *));
                tag->tag_compound.value[tag->tag_compound.size] = inner_tag;
                tag->tag_compound.size++;
            }
        }
        break;
    }
    case NBT_TYPE_INT_ARRAY: {
        tag->tag_int_array.size = nbt__get_int32(stream);
        tag->tag_int_array.value = (int32_t *) NBT_MALLOC(tag->tag_int_array.size * sizeof(int32_t));
        for (size_t i = 0; i < tag->tag_int_array.size; i++) {
            tag->tag_int_array.value[i] = nbt__get_int32(stream);
        }
        break;
    }
    case NBT_TYPE_LONG_ARRAY: {
        tag->tag_long_array.size = nbt__get_int32(stream);
        tag->tag_long_array.value = (int64_t *) NBT_MALLOC(tag->tag_long_array.size * sizeof(int64_t));
        for (size_t i = 0; i < tag->tag_long_array.size; i++) {
            tag->tag_long_array.value[i] = nbt__get_int64(stream);
        }
        break;
    }
    default: {
        NBT_FREE(tag);
        return NULL;
    }
    }

    return tag;
}

nbt_tag_t *nbt_parse(nbt_reader_t reader, int parse_flags)
{

    int compressed;
    int gzip_format;
    switch (parse_flags & 3) {
    case 0: { // Automatic detection (not yet implemented).
        compressed = 1;
        gzip_format = 1;
        break;
    }
    case 1: { // gzip
        compressed = 1;
        gzip_format = 1;
        break;
    }
    case 2: { // zlib
        compressed = 1;
        gzip_format = 0;
        break;
    }
    case 3: { // raw
        compressed = 0;
        gzip_format = 0;
        break;
    }
    }

    uint8_t *buffer = NULL;
    size_t buffer_size = 0;

    nbt__read_stream_t stream;

    if (compressed) {
        z_stream stream;
        stream.zalloc = Z_NULL;
        stream.zfree = Z_NULL;
        stream.opaque = Z_NULL;
        stream.avail_in = 0;
        stream.next_in = Z_NULL;

        if (gzip_format) {
            uint8_t header[10];
            reader.read(reader.userdata, header, 10);
            int fhcrc = header[3] & 2;
            int fextra = header[3] & 4;
            int fname = header[3] & 8;
            int fcomment = header[3] & 16;

            (void) fextra; // I don't think many files use this.

            if (fname) {
                uint8_t byte = 0;
                do {
                    reader.read(reader.userdata, &byte, 1);
                } while (byte != 0);
            }

            if (fcomment) {
                uint8_t byte = 0;
                do {
                    reader.read(reader.userdata, &byte, 1);
                } while (byte != 0);
            }

            uint16_t crc;
            if (fhcrc) {
                reader.read(reader.userdata, (uint8_t *) &crc, 2);
            }

            (void) crc;
        }

        int ret = inflateInit2(&stream, gzip_format ? -Z_DEFAULT_WINDOW_BITS : Z_DEFAULT_WINDOW_BITS);
        if (ret != Z_OK) {
            NBT_FREE(buffer);
            return NULL;
        }

        uint8_t in_buffer[NBT_BUFFER_SIZE];
        uint8_t out_buffer[NBT_BUFFER_SIZE];
        do {
            stream.avail_in = reader.read(reader.userdata, in_buffer, NBT_BUFFER_SIZE);
            stream.next_in = in_buffer;

            do {
                stream.avail_out = NBT_BUFFER_SIZE;
                stream.next_out = out_buffer;

                ret = inflate(&stream, Z_NO_FLUSH);

                size_t have = NBT_BUFFER_SIZE - stream.avail_out;
                buffer = (uint8_t *) NBT_REALLOC(buffer, buffer_size + have);
                NBT_MEMCPY(buffer + buffer_size, out_buffer, have);
                buffer_size += have;

            } while (stream.avail_out == 0);

        } while (ret != Z_STREAM_END);

        inflateEnd(&stream);

    } else {

        uint8_t in_buffer[NBT_BUFFER_SIZE];
        size_t bytes_read;
        do {
            bytes_read = reader.read(reader.userdata, in_buffer, NBT_BUFFER_SIZE);
            buffer = (uint8_t *) NBT_REALLOC(buffer, buffer_size + bytes_read);
            NBT_MEMCPY(buffer + buffer_size, in_buffer, bytes_read);
            buffer_size += bytes_read;
        } while (bytes_read == NBT_BUFFER_SIZE);
    }

    stream.buffer = buffer;
    stream.buffer_offset = 0;

    nbt_tag_t *tag = nbt__parse(&stream, 1, NBT_NO_OVERRIDE);

    NBT_FREE(buffer);

    return tag;
}

typedef struct {
    uint8_t *buffer;
    size_t offset;
    size_t size;
    size_t alloc_size;
} nbt__write_stream_t;

void nbt__put_byte(nbt__write_stream_t *stream, uint8_t value)
{
    if (stream->offset >= stream->alloc_size - 1) {
        stream->buffer = (uint8_t *) NBT_REALLOC(stream->buffer, stream->alloc_size * 2);
        stream->alloc_size *= 2;
    }

    stream->buffer[stream->offset++] = value;
    stream->size++;
}

void nbt__put_int16(nbt__write_stream_t *stream, int16_t value)
{
    uint8_t *value_array = (uint8_t *) &value;
    for (int i = 1; i >= 0; i--) {
        nbt__put_byte(stream, value_array[i]);
    }
}

void nbt__put_int32(nbt__write_stream_t *stream, int32_t value)
{
    uint8_t *value_array = (uint8_t *) &value;
    for (int i = 3; i >= 0; i--) {
        nbt__put_byte(stream, value_array[i]);
    }
}

void nbt__put_int64(nbt__write_stream_t *stream, int64_t value)
{
    uint8_t *value_array = (uint8_t *) &value;
    for (int i = 7; i >= 0; i--) {
        nbt__put_byte(stream, value_array[i]);
    }
}

void nbt__put_float(nbt__write_stream_t *stream, float value)
{
    uint8_t *value_array = (uint8_t *) &value;
    for (int i = 3; i >= 0; i--) {
        nbt__put_byte(stream, value_array[i]);
    }
}

void nbt__put_double(nbt__write_stream_t *stream, double value)
{
    uint8_t *value_array = (uint8_t *) &value;
    for (int i = 7; i >= 0; i--) {
        nbt__put_byte(stream, value_array[i]);
    }
}

void nbt__write_tag(nbt__write_stream_t *stream, nbt_tag_t *tag, int write_name, int write_type)
{

    if (write_type) {
        nbt__put_byte(stream, tag->type);
    }

    if (write_name && tag->type != NBT_TYPE_END) {
        nbt__put_int16(stream, tag->name_size);
        for (size_t i = 0; i < tag->name_size; i++) {
            nbt__put_byte(stream, tag->name[i]);
        }
    }

    switch (tag->type) {
    case NBT_TYPE_END: {
        // Do nothing.
        break;
    }
    case NBT_TYPE_BYTE: {
        nbt__put_byte(stream, tag->tag_byte.value);
        break;
    }
    case NBT_TYPE_SHORT: {
        nbt__put_int16(stream, tag->tag_short.value);
        break;
    }
    case NBT_TYPE_INT: {
        nbt__put_int32(stream, tag->tag_int.value);
        break;
    }
    case NBT_TYPE_LONG: {
        nbt__put_int64(stream, tag->tag_long.value);
        break;
    }
    case NBT_TYPE_FLOAT: {
        nbt__put_float(stream, tag->tag_float.value);
        break;
    }
    case NBT_TYPE_DOUBLE: {
        nbt__put_double(stream, tag->tag_double.value);
        break;
    }
    case NBT_TYPE_BYTE_ARRAY: {
        nbt__put_int32(stream, tag->tag_byte_array.size);
        for (size_t i = 0; i < tag->tag_byte_array.size; i++) {
            nbt__put_byte(stream, tag->tag_byte_array.value[i]);
        }
        break;
    }
    case NBT_TYPE_STRING: {
        nbt__put_int16(stream, tag->tag_string.size);
        for (size_t i = 0; i < tag->tag_string.size; i++) {
            nbt__put_byte(stream, tag->tag_string.value[i]);
        }
        break;
    }
    case NBT_TYPE_LIST: {
        nbt__put_byte(stream, tag->tag_list.type);
        nbt__put_int32(stream, tag->tag_list.size);
        for (size_t i = 0; i < tag->tag_list.size; i++) {
            nbt__write_tag(stream, tag->tag_list.value[i], 0, 0);
        }
        break;
    }
    case NBT_TYPE_COMPOUND: {
        for (size_t i = 0; i < tag->tag_compound.size; i++) {
            nbt__write_tag(stream, tag->tag_compound.value[i], 1, 1);
        }
        nbt__put_byte(stream, 0); // End tag.
        break;
    }
    case NBT_TYPE_INT_ARRAY: {
        nbt__put_int32(stream, tag->tag_int_array.size);
        for (size_t i = 0; i < tag->tag_int_array.size; i++) {
            nbt__put_int32(stream, tag->tag_int_array.value[i]);
        }
        break;
    }
    case NBT_TYPE_LONG_ARRAY: {
        nbt__put_int32(stream, tag->tag_long_array.size);
        for (size_t i = 0; i < tag->tag_long_array.size; i++) {
            nbt__put_int64(stream, tag->tag_long_array.value[i]);
        }
        break;
    }
    default: {
        break;
    }
    }
}

uint32_t nbt__crc_table[256];

int nbt__crc_table_computed = 0;

void nbt__make_crc_table(void)
{
    unsigned long c;
    int n, k;

    for (n = 0; n < 256; n++) {
        c = (uint32_t) n;
        for (k = 0; k < 8; k++) {
            if (c & 1) {
                c = 0xedb88320L ^ (c >> 1);
            } else {
                c = c >> 1;
            }
        }
        nbt__crc_table[n] = c;
    }
    nbt__crc_table_computed = 1;
}

static uint32_t nbt__update_crc(uint32_t crc, uint8_t *buf, size_t len)
{
    uint32_t c = crc ^ 0xffffffffL;
    size_t n;

    if (!nbt__crc_table_computed) {
        nbt__make_crc_table();
    }

    for (n = 0; n < len; n++) {
        c = nbt__crc_table[(c ^ buf[n]) & 0xff] ^ (c >> 8);
    }
    return c ^ 0xffffffffL;
}

void nbt_write(nbt_writer_t writer, nbt_tag_t *tag, int write_flags)
{

    int compressed = 0;
    int gzip_format = 0;

    switch (write_flags & 3) {
    case 1: { // gzip
        compressed = 1;
        gzip_format = 1;
        break;
    }
    case 2: { // zlib
        compressed = 1;
        gzip_format = 0;
        break;
    }
    case 3: { // raw
        compressed = 0;
        gzip_format = 0;
        break;
    }
    }

    nbt__write_stream_t write_stream;
    write_stream.buffer = (uint8_t *) NBT_MALLOC(NBT_BUFFER_SIZE);
    write_stream.offset = 0;
    write_stream.size = 0;
    write_stream.alloc_size = NBT_BUFFER_SIZE;

    nbt__write_tag(&write_stream, tag, 1, 1);

    if (compressed) {

        z_stream stream;
        stream.zalloc = Z_NULL;
        stream.zfree = Z_NULL;
        stream.opaque = Z_NULL;

        int window_bits = gzip_format ? -Z_DEFAULT_WINDOW_BITS : Z_DEFAULT_WINDOW_BITS;

        if (deflateInit2(&stream, NBT_COMPRESSION_LEVEL, Z_DEFLATED, window_bits, 8, Z_DEFAULT_STRATEGY) != Z_OK) {
            NBT_FREE(write_stream.buffer);
            return;
        }

        if (gzip_format) {
            uint8_t header[10] = {31, 139, 8, 0, 0, 0, 0, 0, 2, 255};
            writer.write(writer.userdata, header, 10);
        }

        uint8_t in_buffer[NBT_BUFFER_SIZE];
        uint8_t out_buffer[NBT_BUFFER_SIZE];
        int flush;
        uint32_t crc = 0;

        write_stream.offset = 0;

        do {

            flush = Z_NO_FLUSH;
            size_t bytes_read = 0;
            for (size_t i = 0; i < NBT_BUFFER_SIZE; i++) {

                in_buffer[i] = write_stream.buffer[write_stream.offset++];

                bytes_read++;

                if (write_stream.offset >= write_stream.size) {
                    flush = Z_FINISH;
                    break;
                }
            }

            stream.avail_in = bytes_read;
            stream.next_in = in_buffer;

            do {
                stream.avail_out = NBT_BUFFER_SIZE;
                stream.next_out = out_buffer;

                deflate(&stream, flush);

                size_t have = NBT_BUFFER_SIZE - stream.avail_out;
                writer.write(writer.userdata, out_buffer, have);

                crc = nbt__update_crc(crc, out_buffer, have);

            } while (stream.avail_out == 0);

        } while (flush != Z_FINISH);

        deflateEnd(&stream);

        if (gzip_format) {
            writer.write(writer.userdata, (uint8_t *) &crc, 4);
            writer.write(writer.userdata, (uint8_t *) &write_stream.size, 4);
        }

    } else {
        size_t bytes_left = write_stream.size;
        size_t offset = 0;
        while (bytes_left > 0) {
            size_t bytes_written = writer.write(writer.userdata, write_stream.buffer + offset, bytes_left);
            offset += bytes_written;
            bytes_left -= bytes_written;
        }
    }

    NBT_FREE(write_stream.buffer);
}

static nbt_tag_t *nbt__new_tag_base(void)
{
    nbt_tag_t *tag = (nbt_tag_t *) NBT_MALLOC(sizeof(nbt_tag_t));
    tag->name = NULL;
    tag->name_size = 0;

    return tag;
}

nbt_tag_t *nbt_new_tag_byte(int8_t value)
{
    nbt_tag_t *tag = nbt__new_tag_base();

    tag->type = NBT_TYPE_BYTE;
    tag->tag_byte.value = value;

    return tag;
}

nbt_tag_t *nbt_new_tag_short(int16_t value)
{
    nbt_tag_t *tag = nbt__new_tag_base();

    tag->type = NBT_TYPE_SHORT;
    tag->tag_short.value = value;

    return tag;
}

nbt_tag_t *nbt_new_tag_int(int32_t value)
{
    nbt_tag_t *tag = nbt__new_tag_base();

    tag->type = NBT_TYPE_INT;
    tag->tag_int.value = value;

    return tag;
}

nbt_tag_t *nbt_new_tag_long(int64_t value)
{
    nbt_tag_t *tag = nbt__new_tag_base();

    tag->type = NBT_TYPE_LONG;
    tag->tag_long.value = value;

    return tag;
}

nbt_tag_t *nbt_new_tag_float(float value)
{
    nbt_tag_t *tag = nbt__new_tag_base();

    tag->type = NBT_TYPE_FLOAT;
    tag->tag_float.value = value;

    return tag;
}

nbt_tag_t *nbt_new_tag_double(double value)
{
    nbt_tag_t *tag = nbt__new_tag_base();

    tag->type = NBT_TYPE_DOUBLE;
    tag->tag_double.value = value;

    return tag;
}

nbt_tag_t *nbt_new_tag_byte_array(int8_t *value, size_t size)
{
    nbt_tag_t *tag = nbt__new_tag_base();

    tag->type = NBT_TYPE_BYTE_ARRAY;
    tag->tag_byte_array.size = size;
    tag->tag_byte_array.value = (int8_t *) NBT_MALLOC(size);

    NBT_MEMCPY(tag->tag_byte_array.value, value, size);

    return tag;
}

nbt_tag_t *nbt_new_tag_string(const char *value, size_t size)
{
    nbt_tag_t *tag = nbt__new_tag_base();

    tag->type = NBT_TYPE_STRING;
    tag->tag_string.size = size;
    tag->tag_string.value = (char *) NBT_MALLOC(size + 1);

    NBT_MEMCPY(tag->tag_string.value, value, size);
    tag->tag_string.value[tag->tag_string.size] = '\0';

    return tag;
}

nbt_tag_t *nbt_new_tag_list(nbt_tag_type_t type)
{
    nbt_tag_t *tag = nbt__new_tag_base();

    tag->type = NBT_TYPE_LIST;
    tag->tag_list.type = type;
    tag->tag_list.size = 0;
    tag->tag_list.value = NULL;

    return tag;
}

nbt_tag_t *nbt_new_tag_compound(void)
{
    nbt_tag_t *tag = nbt__new_tag_base();

    tag->type = NBT_TYPE_COMPOUND;
    tag->tag_compound.size = 0;
    tag->tag_compound.value = NULL;

    return tag;
}

nbt_tag_t *nbt_new_tag_int_array(int32_t *value, size_t size)
{
    nbt_tag_t *tag = nbt__new_tag_base();

    tag->type = NBT_TYPE_INT_ARRAY;
    tag->tag_int_array.size = size;
    tag->tag_int_array.value = (int32_t *) NBT_MALLOC(size * sizeof(int32_t));

    NBT_MEMCPY(tag->tag_int_array.value, value, size * sizeof(int32_t));

    return tag;
}

nbt_tag_t *nbt_new_tag_long_array(int64_t *value, size_t size)
{
    nbt_tag_t *tag = nbt__new_tag_base();

    tag->type = NBT_TYPE_LONG_ARRAY;
    tag->tag_long_array.size = size;
    tag->tag_long_array.value = (int64_t *) NBT_MALLOC(size * sizeof(int64_t));

    NBT_MEMCPY(tag->tag_long_array.value, value, size * sizeof(int64_t));

    return tag;
}

void nbt_set_tag_name(nbt_tag_t *tag, const char *name, size_t size)
{
    if (tag->name) {
        NBT_FREE(tag->name);
    }
    tag->name_size = size;
    tag->name = (char *) NBT_MALLOC(size + 1);
    NBT_MEMCPY(tag->name, name, size);
    tag->name[tag->name_size] = '\0';
}

void nbt_tag_list_append(nbt_tag_t *list, nbt_tag_t *value)
{
    list->tag_list.value = (nbt_tag_t **) NBT_REALLOC(list->tag_list.value, (list->tag_list.size + 1) * sizeof(nbt_tag_t *));
    list->tag_list.value[list->tag_list.size] = value;
    list->tag_list.size++;
}

nbt_tag_t *nbt_tag_list_get(nbt_tag_t *tag, size_t index) { return tag->tag_list.value[index]; }

void nbt_tag_compound_append(nbt_tag_t *compound, nbt_tag_t *value)
{
    compound->tag_compound.value = (nbt_tag_t **) NBT_REALLOC(compound->tag_compound.value, (compound->tag_compound.size + 1) * sizeof(nbt_tag_t *));
    compound->tag_compound.value[compound->tag_compound.size] = value;
    compound->tag_compound.size++;
}

nbt_tag_t *nbt_tag_compound_get(nbt_tag_t *tag, const char *key)
{
    for (size_t i = 0; i < tag->tag_compound.size; i++) {
        nbt_tag_t *compare_tag = tag->tag_compound.value[i];

        if (NBT_MEMCMP(compare_tag->name, key, compare_tag->name_size) == 0) {
            return compare_tag;
        }
    }

    return NULL;
}

nbt_tag_t *nbt_tag_compound_getidx(nbt_tag_t *tag, size_t index) { return tag->tag_compound.value[index]; }

void nbt_free_tag(nbt_tag_t *tag)
{
    switch (tag->type) {
    case NBT_TYPE_BYTE_ARRAY: {
        NBT_FREE(tag->tag_byte_array.value);
        break;
    }
    case NBT_TYPE_STRING: {
        NBT_FREE(tag->tag_string.value);
        break;
    }
    case NBT_TYPE_LIST: {
        for (size_t i = 0; i < tag->tag_list.size; i++) {
            nbt_free_tag(tag->tag_list.value[i]);
        }
        NBT_FREE(tag->tag_list.value);
        break;
    }
    case NBT_TYPE_COMPOUND: {
        for (size_t i = 0; i < tag->tag_compound.size; i++) {
            nbt_free_tag(tag->tag_compound.value[i]);
        }
        NBT_FREE(tag->tag_compound.value);
        break;
    }
    case NBT_TYPE_INT_ARRAY: {
        NBT_FREE(tag->tag_int_array.value);
        break;
    }
    case NBT_TYPE_LONG_ARRAY: {
        NBT_FREE(tag->tag_long_array.value);
        break;
    }
    default: {
        break;
    }
    }

    if (tag->name) {
        NBT_FREE(tag->name);
    }

    NBT_FREE(tag);
}

#endif
