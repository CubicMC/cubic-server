#pragma once

#include "library/LibraryManager.hpp"
#include "platforms/windows/library/Library.hpp"
#include <windows.h>

class WindowsLibraryManager {
public:
    WindowsLibraryManager() = delete;
    static Library *load(const std::filesystem::path &path);
};
