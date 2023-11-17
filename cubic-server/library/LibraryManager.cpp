#include "LibraryManager.hpp"

Library *LibraryManager::load(const std::filesystem::path &path)
{
#if defined(CBSRV_PLATFORM_LINUX) || defined(CBSRV_PLATFORM_MACOS)
    return LinuxLibraryManager::load(path);
#elif defined(CBSRV_PLATFORM_WINDOWS)
    return WindowsLibraryManager::load(path);
#else
#error "Unsupported platform"
#endif
}

std::string_view LibraryManager::extension()
{
#if defined(CBSRV_PLATFORM_LINUX) || defined(CBSRV_PLATFORM_MACOS)
    return ".so";
#elif defined(CBSRV_PLATFORM_WINDOWS)
    return ".dll";
#else
#warning "Unknown platform, assuming .so extension"
    return ".so";
#endif
}
