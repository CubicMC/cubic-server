#include "platforms/linux/library/LibraryManager.hpp"
#include "platforms/linux/library/Library.hpp"

Library *LinuxLibraryManager::load(const std::filesystem::path &path)
{
    dlerror();
    void *handle = dlopen(path.c_str(), RTLD_LAZY);
    auto error = dlerror();
    if (error) {
        LERROR("Failed to load library: {}", error);
        return nullptr;
    }
    if (!handle)
        return nullptr;
    return new LinuxLibrary(handle);
}
