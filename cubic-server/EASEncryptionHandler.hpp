#ifndef C76FB0E7_89F8_4F6B_B240_196A146838AA
#define C76FB0E7_89F8_4F6B_B240_196A146838AA

#include <array>
#include <mutex>
#include <vector>

#include <mbedtls/aes.h>

class EASEncryptionHandler {
public:
    EASEncryptionHandler();
    ~EASEncryptionHandler();
    void initialize(const std::array<uint8_t, 16> &key, const std::array<uint8_t, 16> &initialVector);
    void encrypt(std::vector<uint8_t> &data);
    void decrypt(uint8_t *data, size_t size);
    inline bool isInitialized() const { return _isInitialized; }

private:
    mbedtls_aes_context _context;
    std::array<uint8_t, 16> _initialVectorEncrypt;
    std::array<uint8_t, 16> _initialVectorDecrypt;
    bool _isInitialized;
    std::mutex _lock;
};

#endif /* C76FB0E7_89F8_4F6B_B240_196A146838AA */
