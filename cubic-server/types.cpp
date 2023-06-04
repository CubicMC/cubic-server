#include "types.hpp"
#include <iterator>
#include <random>

std::string u128::toString() const
{
    std::stringstream uuidsstr;
    std::string uuidstr;

    uuidsstr << std::setfill('0') << std::setw(16) << std::hex << this->most << std::setfill('0') << std::setw(16) << this->least;
    uuidstr = uuidsstr.str();
    uuidstr.insert(8, "-");
    uuidstr.insert(13, "-");
    uuidstr.insert(18, "-");
    uuidstr.insert(23, "-");
    return uuidstr;
}

void u128::swapEndianness()
{
    // Yes I know this is terrible but it works really well
    this->most = ((this->most & 0xffffffff00000000) >> 32) | ((this->most & 0x00000000ffffffff) << 32);
    this->least = ((this->least & 0xffffffff00000000) >> 32) | ((this->least & 0x00000000ffffffff) << 32);
}

u128 u128::fromShortString(const std::string &str)
{
    auto it = str.begin();
    std::advance(it, 16);
    std::string first = std::string(str.begin(), it);
    std::string second = std::string(it, str.end());
    return u128({std::stoull(first, 0, 16), std::stoull(second, 0, 16)});
}

u128 u128::random()
{
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<uint64_t> dis(0, 0xffffffffffffffff);
    return u128({dis(gen), dis(gen)});
}
