#ifndef A7432D14_95C4_43B4_841E_FD2E95B3847C
#define A7432D14_95C4_43B4_841E_FD2E95B3847C

#include <array>
#include <vector>

#include <mbedtls/ctr_drbg.h>
#include <mbedtls/entropy.h>
#include <mbedtls/rsa.h>

class RSAEncryptionHandler {
public:
    RSAEncryptionHandler();
    ~RSAEncryptionHandler();
    void generate();
    int decrypt(const std::vector<uint8_t> &encryptedData, uint8_t *decryptedData, size_t decryptedMaxSize);
    std::vector<uint8_t> getPublicKey();

private:
    mbedtls_rsa_context _context;

    mbedtls_entropy_context _entropy;
    mbedtls_ctr_drbg_context _ctrDrbgContext;
};

#endif /* A7432D14_95C4_43B4_841E_FD2E95B3847C */
