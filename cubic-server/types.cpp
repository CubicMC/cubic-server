#include "types.hpp"
#include "utility/PseudoRandomGenerator.hpp"
#include <iterator>
#include <mbedtls/md5.h>
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

std::vector<int32_t> u128::toVector() const
{
    u128 result(*this);
    result.swapEndianness();
    return std::vector<int32_t> {
        (int32_t) ((result.most & 0xffffffff00000000) >> 32),
        (int32_t) (result.most & 0x00000000ffffffff),
        (int32_t) ((result.least & 0xffffffff00000000) >> 32),
        (int32_t) (result.least & 0x00000000ffffffff),
    };
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
    return u128(
        {utility::PseudoRandomGenerator::getInstance()->generateNumber<long unsigned int>(0, 0xffffffffffffffff),
         utility::PseudoRandomGenerator::getInstance()->generateNumber<long unsigned int>(0, 0xffffffffffffffff)}
    );
}

u128 u128::fromOfflinePlayerName(const std::string &name)
{
    std::string playername = "OfflinePlayer:" + name;
    unsigned char result[16];
    uint64_t most = 0;
    mbedtls_md5((const unsigned char *) playername.c_str(), playername.size(), result);
    uint64_t least = 0;
    for (int i = 0; i < 8; i++)
        most = (most << 8) | result[i];
    for (int i = 8; i < 16; i++)
        least = (least << 8) | result[i];
    return {most, least};
}

bool u128::operator==(const u128 &other) const { return this->most == other.most && this->least == other.least; }

Position::valueType Position::manhattanDistance(const Position &other) const { return std::abs(x - other.x) + std::abs(y - other.y) + std::abs(z - other.z); }

std::string Tps::toString() const
{
    std::stringstream sstr;
    sstr << "Tps: " << this->oneMinTps << " " << this->fiveMinTps << " " << this->fifteenMinTps;
    return sstr.str();
}

std::string MSPTInfos::toString() const
{
    std::stringstream sstr;
    sstr << "MSPT: " << this->min << " " << this->mean << " " << this->max;
    return sstr.str();
}
