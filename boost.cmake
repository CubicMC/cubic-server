
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

set(BOOST_INCLUDE_LIBRARIES asio system container lockfree circular_buffer)
set(BOOST_ENABLE_CMAKE ON)
