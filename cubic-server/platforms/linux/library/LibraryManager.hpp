#pragma once

#include "library/LibraryManager.hpp"
#include "logging/logging.hpp"
#include <dlfcn.h>

class LinuxLibraryManager {
public:
    static Library *load(const std::filesystem::path &path);
};
