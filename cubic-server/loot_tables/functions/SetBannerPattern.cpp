#include "SetBannerPattern.hpp"

namespace LootTable {
namespace Function {
SetBannerPattern::SetBannerPattern(const nlohmann::json &function):
    Function(function)
{
    this->setValidity(true);
}

void SetBannerPattern::apply(const LootContext &context) { (void) context; }

std::unique_ptr<Function> SetBannerPattern::create(const nlohmann::json &function) { return (std::make_unique<SetBannerPattern>(function)); }
};
};
