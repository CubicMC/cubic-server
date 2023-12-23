#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <unistd.h>
#include <vector>
#include <zlib.h>

#include "Server.hpp"

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
    destination.insert(destination.end(), destination_data, destination_data + destination_length);
    free(destination_data);
    return return_value;
}

int decompressVector(const std::vector<uint8_t> &compressedBytes, std::vector<uint8_t> &uncompressedBytes, uint32_t size)
{
    Bytef *dest = (Bytef *) malloc(sizeof(char) * size);
    uLongf maxSize = size;
    int return_value = uncompress(dest, &maxSize, (const Bytef *) compressedBytes.data(), (uLong) compressedBytes.size());
    uncompressedBytes.insert(uncompressedBytes.end(), dest, dest + maxSize);
    free(dest);
    return return_value;
}
