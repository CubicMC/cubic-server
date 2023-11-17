#include "platforms/windows/library/Library.hpp"
#include "logging/logging.hpp"

WindowsLibrary::WindowsLibrary(HINSTANCE handle):
    _handle(handle)
{
}

WindowsLibrary::~WindowsLibrary()
{
    if (_handle == nullptr)
        return;
    if (!FreeLibrary(_handle))
        LERROR("Failed to unload library");
}

void *WindowsLibrary::_getSymbol(const std::string_view &name) { return reinterpret_cast<void *>(GetProcAddress(_handle, name.data())); }
