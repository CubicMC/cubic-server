set(BOOST_VERSION 1.78.0)

set(BOOST_INCLUDE_LIBRARIES asio system container lockfree circular_buffer)
set(BOOST_ENABLE_CMAKE ON)

find_package(Boost ${BOOST_VERSION} COMPONENTS system container)

if (NOT Boost_FOUND)
    message(STATUS "Boost not found, downloading...")
    # Build only the required boost libraries
    list(APPEND BOOST_REQD_SUBMODULES
        # Asio
        "asio"
            "align"
            "array"
            "assert"
            "bind"
                "chrono"
                    "typeof"
                    "ratio"
                        "rational"
            "config"
            "core"
            "coroutine"
                "context"
                    "pool"
            "date_time"
                "tokenizer"
                "numeric/conversion"
                "lexical_cast"
                "algorithm"
                    "unordered"
                    "range"
                    "exception"
            "function"
                "type_index"
            "regex"
            "smart_ptr"
            "system"
            "throw_exception"
            "type_traits"
            "utility"
                "io"

        # Container
        "container"
            "intrusive"
                "container_hash"
                    "describe"
            "move"
            "static_assert"

        # System
        "system"
            "variant2"
                "mp11"
            "winapi"

        # Lock Free
        "lockfree"
            "atomic"
                "preprocessor"
            "integer"
            "iterator"
                "detail"
                "conversion"
            "mpl"
            "parameter"
                "optional"
                "fusion"
                    "functional"
                    "function_types"
            "predef"
            "tuple"
        "lockfree"

        # Circular Buffer
        "circular_buffer"
            "concept_check"
    )
    list(TRANSFORM BOOST_REQD_SUBMODULES PREPEND "libs/")

    list(APPEND BOOST_REQD_SUBMODULES
        "tools/build"
        "tools/cmake"
    )

    FetchContent_Declare(
        boost
        GIT_REPOSITORY https://github.com/boostorg/boost.git
        GIT_TAG boost-${BOOST_VERSION}
        GIT_PROGRESS TRUE
        GIT_SUBMODULES ${BOOST_REQD_SUBMODULES}
        GIT_SHALLOW TRUE
    )

    FetchContent_MakeAvailable(boost)
endif()
