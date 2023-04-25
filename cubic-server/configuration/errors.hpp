#ifndef CONFIGURATION_ERRORS_HPP
#define CONFIGURATION_ERRORS_HPP

#include "exceptions.hpp"

namespace configuration {

DEFINE_EXCEPTION(ConfigurationError);
DEFINE_EXCEPTION_FROM(BadFile, ConfigurationError);

} // namespace configuration

#endif // CONFIGURATION_ERRORS_HPP
