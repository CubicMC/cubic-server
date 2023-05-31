#include <cassert>
#include <cstring>
#include <logging/logging.hpp>

#include <mbedtls/sha1.h>

#include "Checksum.hpp"

Checksum::Checksum() noexcept:
    _isDone(false)
{
    mbedtls_sha1_starts(&_context);
}

Checksum::~Checksum() noexcept { mbedtls_sha1_free(&_context); }

void Checksum::update(const uint8_t *data, size_t length)
{
    assert(!_isDone);
    mbedtls_sha1_update(&_context, data, length);
}

void Checksum::finalize(uint8_t *data)
{
    assert(!_isDone);

    mbedtls_sha1_finish(&_context, data);
    _isDone = true;
}

std::string Checksum::digestToProtocol(const uint8_t *data)
{
    uint8_t digest[20];
    memcpy(digest, data, sizeof(digest));
    std::string result;

    bool isNegative = (digest[0] >= 0x80);
    if (isNegative) {
        bool carry = true;
        for (int i = 19; i >= 0; i--) {
            digest[i] = ~digest[i];
            if (carry) {
                carry = (digest[i] == 0xff);
                digest[i]++;
            }
        }
    }
    result.reserve(40);
    for (int i = 0; i < 20; i++) {
        result.append(fmt::format("{:02x}", digest[i]));
    }
    while ((result.length() > 0) && (result[0] == '0')) {
        result.erase(0, 1);
    }
    if (isNegative) {
        result.insert(0, "-");
    }
    return result;
}

void Checksum::reset()
{
    mbedtls_sha1_starts(&_context);
    _isDone = false;
}
