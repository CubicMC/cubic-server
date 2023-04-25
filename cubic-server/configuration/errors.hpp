#ifndef CONFIGURATION_ERRORS_HPP
#define CONFIGURATION_ERRORS_HPP

#include "exceptions.hpp"

namespace configuration {

DEFINE_EXCEPTION(ConfigurationError);
DEFINE_EXCEPTION(BadFile);

} // namespace configuration

#endif // CONFIGURATION_ERRORS_HPP
