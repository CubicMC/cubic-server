#include <cassert>
#include <cstring>
#include <mutex>
#include <vector>

#include "EASEncryptionHandler.hpp"
#include "logging/logging.hpp"

void EASEncryptionHandler::encrypt(std::vector<uint8_t> &data)
{
    std::lock_guard _(_lock);
    assert(_isInitialized);
    if (mbedtls_aes_crypt_cfb8(&_context, MBEDTLS_AES_ENCRYPT, data.size(), _initialVectorEncrypt.data(), data.data(), data.data())) {
        LERROR("Encryption error");
    }
}

void EASEncryptionHandler::decrypt(uint8_t *data, size_t size)
{
    std::lock_guard _(_lock);
    assert(_isInitialized);
    if (mbedtls_aes_crypt_cfb8(&_context, MBEDTLS_AES_DECRYPT, size, _initialVectorDecrypt.data(), data, data)) {
        LERROR("Decryption error");
    }
}

void EASEncryptionHandler::initialize(const std::array<uint8_t, 16> &key, const std::array<uint8_t, 16> &initialVector)
{
    assert(!_isInitialized);

    memcpy(_initialVectorEncrypt.data(), initialVector.data(), 16);
    memcpy(_initialVectorDecrypt.data(), initialVector.data(), 16);
    mbedtls_aes_setkey_enc(&_context, key.data(), 128);
    _isInitialized = true;
}

EASEncryptionHandler::EASEncryptionHandler():
    _isInitialized(false)
{
    mbedtls_aes_init(&_context);
}

EASEncryptionHandler::~EASEncryptionHandler() { mbedtls_aes_free(&_context); }
