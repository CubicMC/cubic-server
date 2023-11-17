#ifndef OPTIONS_HPP
#define OPTIONS_HPP

#ifndef PROGRAM_NAME
#define PROGRAM_NAME "CubicServer-default"
#endif

#ifndef PROGRAM_VERSION
#define PROGRAM_VERSION "1.0.0-default"
#endif

#ifndef NODISCARD
#define NODISCARD [[nodiscard]]
#endif

#ifndef UNUSED
#define UNUSED [[maybe_unused]]
#endif

#if defined(_WIN32)
#define CBSRV_PLATFORM_WINDOWS
#elif defined(__unix__) && defined(__linux__)
#define CBSRV_PLATFORM_LINUX
#elif defined(__APPLE__)
#define CBSRV_PLATFORM_MACOS
#else
#warning "Unsupported platform"
#endif

#ifdef CBSRV_PLATFORM_WINDOWS
#define CBSRV_EXPORT __declspec(dllexport)
#define CBSRV_IMPORT __declspec(dllimport)
#else
#define CBSRV_EXPORT __attribute__((visibility("default")))
#define CBSRV_IMPORT __attribute__((visibility("default")))
#endif

#ifdef CBSRV_BUILDING
#define CBSRV_API CBSRV_EXPORT
#else
#define CBSRV_API CBSRV_IMPORT
#endif

#endif // OPTIONS_HPP
