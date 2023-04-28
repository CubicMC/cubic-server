#ifndef OPTIONS_HPP
#define OPTIONS_HPP

#ifndef PROGRAM_NAME
#warning "PROGRAM_NAME is not defined, defaulting to CubicServer"
#define PROGRAM_NAME "CubicServer"
#endif

#ifndef PROGRAM_VERSION
#warning "PROGRAM_VERSION is not defined, defaulting to '1.0.0'"
#define PROGRAM_VERSION "1.0.0"
#endif

#ifndef NODISCARD
#define NODISCARD [[nodiscard]]
#endif

#ifndef UNUSED
#define UNUSED [[maybe_unused]]
#endif

#endif // OPTIONS_HPP
