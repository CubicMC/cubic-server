#pragma once

#include "library/Library.hpp"
#include "logging/logging.hpp"

class LinuxLibrary : public Library {
public:
    LinuxLibrary(void *handle);
    ~LinuxLibrary() override;

protected:
    void *_getSymbol(const std::string_view &name) override;

private:
    void *_handle;
};
