#pragma once

#include "library/LibraryManager.hpp"
#include <windows.h>

class WindowsLibrary : public Library {
public:
    WindowsLibrary(HINSTANCE handle);
    ~WindowsLibrary() override;

protected:
    void *_getSymbol(const std::string_view &name) override;

private:
    HINSTANCE _handle;
};
