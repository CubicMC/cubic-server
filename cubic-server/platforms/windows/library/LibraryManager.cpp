#include "platforms/windows/library/LibraryManager.hpp"

Library *WindowsLibraryManager::load(const std::filesystem::path &path)
{
    HINSTANCE hinstLib;

    hinstLib = LoadLibrary(TEXT(path.string().c_str()));
    if (hinstLib == nullptr)
        return nullptr;
    return new WindowsLibrary(hinstLib);
}
