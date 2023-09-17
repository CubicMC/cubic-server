#ifndef COMPRESSION_UTILS_HPP_
#define COMPRESSION_UTILS_HPP_

#include <cstdint>
#include <vector>

/**
 * @brief Compresses a vector using zlib
 *
 * @param source Vector to compress
 * @param destination Destion vector containing compressed data
 * @return int Whatever zlib returns when compressing
 * @todo Needs to be checked for lags
 */
int compressVector(const std::vector<uint8_t> &source, std::vector<uint8_t> &destination);

/**
 * @brief Decompresses a vector using zlib
 *
 * @param compressedBytes Vector to decompress
 * @param uncompressedBytes Destination vector with decompressed data
 * @param size The size of the destination vector to expect
 * @return int Whatever zlib return when uncompressing
 * @todo Needs to be heavily optimized, so much weird code
 */
int decompressVector(const std::vector<uint8_t> &compressedBytes, std::vector<uint8_t> &uncompressedBytes, uint32_t size);

#endif // COMPRESSION_UTILS_HPP_
