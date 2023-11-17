#pragma once

#include "Library.hpp"
#include "options.hpp"
#include <filesystem>
#include <functional>

class LibraryManager {
public:
    LibraryManager() = delete;
    static Library *load(const std::filesystem::path &path);
    static std::string_view extension();
};

#if defined(CBSRV_PLATFORM_LINUX) || defined(CBSRV_PLATFORM_MACOS)
#include "platforms/linux/library/LibraryManager.hpp"
#elif defined(CBSRV_PLATFORM_WINDOWS)
#include "platforms/windows/library/LibraryManager.hpp"
#endif
