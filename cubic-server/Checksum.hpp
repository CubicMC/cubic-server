#ifndef A736F989_95E7_4420_868A_B5FC7A16DF06
#define A736F989_95E7_4420_868A_B5FC7A16DF06

#include <string>

#include <mbedtls/sha1.h>

#include "options.hpp"

class Checksum {
public:
    Checksum() noexcept;
    ~Checksum() noexcept;
    void update(const uint8_t *data, size_t length);
    void finalize(uint8_t *data);
    static std::string digestToProtocol(const uint8_t *data);
    void reset();

    NODISCARD inline bool isDone() const { return _isDone; }

private:
    bool _isDone;
    mbedtls_sha1_context _context;
};

#endif /* A736F989_95E7_4420_868A_B5FC7A16DF06 */
