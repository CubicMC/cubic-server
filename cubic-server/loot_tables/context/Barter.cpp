#include "Barter.hpp"

namespace LootTable {
namespace Context {
Barter::Barter(const Entity &barterer):
    LootContext("minecraft:barter"),
    barterer(barterer)
{
}
}
}
