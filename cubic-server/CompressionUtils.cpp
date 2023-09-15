#include <cstddef>
#include <cstdint>
#include <unistd.h>
#include <vector>
#include <zlib.h>

#include "Server.hpp"

static void add_buffer_to_vector(std::vector<uint8_t> &vector, const uint8_t *buffer, size_t length)
{
    for (size_t character_index = 0; character_index < length; character_index++) {
        char current_character = buffer[character_index];
        vector.push_back(current_character);
    }
}

int compressVector(const std::vector<uint8_t> &source, std::vector<uint8_t> &destination)
{
    unsigned long source_length = source.size();
    size_t destination_length = compressBound(source_length);

    uint8_t *destination_data = (uint8_t *) malloc(destination_length);
    if (destination_data == nullptr) {
        return Z_MEM_ERROR;
    }

    Bytef *source_data = (Bytef *) source.data();
    int return_value = compress2((Bytef *) destination_data, &destination_length, source_data, source_length, CONFIG["compression-level"].as<int>());
    add_buffer_to_vector(destination, destination_data, destination_length);
    free(destination_data);
    return return_value;
}

// TODO(huntears): Optimize this HOLY SHIT
bool decompressVector(const std::vector<uint8_t> &compressedBytes, std::vector<uint8_t> &uncompressedBytes, uint32_t size)
{
    unsigned full_length = size;
    unsigned half_length = size / 2;

    unsigned uncompLength = full_length;
    char *uncomp = (char *) calloc(sizeof(char), uncompLength);

    z_stream strm;
    strm.next_in = (Bytef *) compressedBytes.data();
    strm.avail_in = size;
    strm.total_out = 0;
    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;

    bool done = false;

    if (inflateInit2(&strm, (16 + MAX_WBITS)) != Z_OK) {
        free(uncomp);
        return false;
    }

    while (!done) {
        // If our output buffer is too small
        if (strm.total_out >= uncompLength) {
            // Increase size of output buffer
            char *uncomp2 = (char *) calloc(sizeof(char), uncompLength + half_length);
            memcpy(uncomp2, uncomp, uncompLength);
            uncompLength += half_length;
            free(uncomp);
            uncomp = uncomp2;
        }

        strm.next_out = (Bytef *) (uncomp + strm.total_out);
        strm.avail_out = uncompLength - strm.total_out;

        // Inflate another chunk.
        int err = inflate(&strm, Z_SYNC_FLUSH);
        if (err == Z_STREAM_END)
            done = true;
        else if (err != Z_OK) {
            break;
        }
    }

    if (inflateEnd(&strm) != Z_OK) {
        free(uncomp);
        return false;
    }

    for (size_t i = 0; i < strm.total_out; ++i) {
        uncompressedBytes.push_back(uncomp[i]);
    }
    // uncompressedBytes.insert(uncompressedBytes.begin(), uncomp, uncomp + strm.total_out);
    free(uncomp);
    return true;
}