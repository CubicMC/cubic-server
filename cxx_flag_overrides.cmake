set(CMAKE_CXX_FLAGS_INIT "-Wall -Wextra -Wpedantic -Wno-unknown-pragmas -Wno-missing-field-initializers")
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-ggdb3")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-O3 -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO_INIT "-O2 -ggdb3 -fno-omit-frame-pointer -fsanitize=address -fsanitize=null")

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-array-bounds -Wno-stringop-overflow")
elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
# elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
else()
    message(FATAL_ERROR "Unsupported compiler: ${CMAKE_CXX_COMPILER_ID}")
endif()

