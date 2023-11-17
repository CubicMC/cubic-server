#pragma once

#include "options.hpp"

#if defined(CBSRV_PLATFORM_LINUX) || defined(CBSRV_PLATFORM_MACOS)
#include "platforms/linux/poll/poll.hpp"
#elif defined(CBSRV_PLATFORM_WINDOWS)
#include "platforms/windows/poll/poll.hpp"
#else
#warning "Unknown platform, defaulting to linux style poll"
#include "platforms/linux/poll/poll.hpp"
#endif
