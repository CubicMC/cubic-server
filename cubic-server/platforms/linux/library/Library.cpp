#include "platforms/linux/library/Library.hpp"
#include <dlfcn.h>

LinuxLibrary::LinuxLibrary(void *handle):
    _handle(handle)
{
}

LinuxLibrary::~LinuxLibrary() { dlclose(_handle); }

void *LinuxLibrary::_getSymbol(const std::string_view &name)
{
    dlerror();
    void *symbol = dlsym(_handle, name.data());
    auto error = dlerror();
    if (error) {
        LERROR("Failed to load symbol: {}", error);
        return nullptr;
    }
    return symbol;
}
