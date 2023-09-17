#include "PseudoRandomGenerator.hpp"

utility::PseudoRandomGenerator::PseudoRandomGenerator():
    _engine(_seeder())
{
}

utility::PseudoRandomGenerator::~PseudoRandomGenerator() { }
