#include <stdexcept>
#include <vector>

#include <mbedtls/pk.h>

#include "RSAEncryptionHandler.hpp"
#include "logging/logging.hpp"
#include "mbedtls/rsa.h"

constexpr auto keySizeBits = 1024;
#define CHECK_SUS(x)                                                                        \
    if (x != 0) {                                                                           \
        throw std::runtime_error("Something went wrong here: " + std::to_string(__LINE__)); \
    }

RSAEncryptionHandler::RSAEncryptionHandler()
{
    mbedtls_rsa_init(&_context);
    mbedtls_entropy_init(&_entropy);
    mbedtls_ctr_drbg_init(&_ctrDrbgContext);
    CHECK_SUS(mbedtls_ctr_drbg_seed(&_ctrDrbgContext, mbedtls_entropy_func, &_entropy, nullptr, 0))
}

RSAEncryptionHandler::~RSAEncryptionHandler()
{
    mbedtls_rsa_free(&_context);
    mbedtls_entropy_free(&_entropy);
    mbedtls_ctr_drbg_free(&_ctrDrbgContext);
}

void RSAEncryptionHandler::generate()
{
    int ret = mbedtls_rsa_gen_key(&_context, mbedtls_ctr_drbg_random, &_ctrDrbgContext, keySizeBits, 65537);
    if (ret != 0) {
        LFATAL("Could not generate RSA private key");
        throw std::runtime_error("Could not genereate RSA private key");
    }
}

std::vector<uint8_t> RSAEncryptionHandler::getPublicKey()
{
    mbedtls_pk_context key;

    mbedtls_pk_init(&key);
    if (mbedtls_pk_setup(&key, mbedtls_pk_info_from_type(MBEDTLS_PK_RSA)) != 0)
        throw std::runtime_error("Could not initialize PK context");
    if (mbedtls_rsa_copy(mbedtls_pk_rsa(key), &_context) != 0)
        throw std::runtime_error("Could not copy PK to context");
    unsigned char buf[4096];
    int length = mbedtls_pk_write_pubkey_der(&key, (unsigned char *) buf, sizeof(buf));
    if (length < 0)
        throw std::runtime_error("Could not get public key from private key");
    mbedtls_pk_free(&key);
    return std::vector<uint8_t>(buf + sizeof(buf) - length, buf + sizeof(buf));
}

int RSAEncryptionHandler::decrypt(const std::vector<uint8_t> &encryptedData, uint8_t *decryptedData, size_t decryptedMaxSize)
{
    const auto keyLength = mbedtls_rsa_get_len(&_context);
    if (keyLength > encryptedData.size()) {
        LERROR("Encrypted data of size {} too small for key of size {}", encryptedData.size(), keyLength);
        return -1;
    }
    if (keyLength > decryptedMaxSize) {
        LERROR("Max decryption size ({}) too small for key of size {}", decryptedMaxSize, keyLength);
        return -1;
    }
    size_t toRet = 0;
    int ret = mbedtls_rsa_pkcs1_decrypt(
        &_context, mbedtls_ctr_drbg_random, &_ctrDrbgContext, &toRet, reinterpret_cast<const unsigned char *>(encryptedData.data()), decryptedData, decryptedMaxSize
    );
    return !ret ? (int) (toRet) : -1;
}
