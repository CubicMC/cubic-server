function(download_and_check_file URL OUTPUT_FILE WORK_DIR)
    cmake_path(APPEND FILE_PATH ${WORK_DIR} ${OUTPUT_FILE})
    cmake_path(GET FILE_PATH FILENAME FILE_NAME)

    find_file(FOUND ${OUTPUT_FILE} HINTS ${WORK_DIR} NO_CACHE)
    find_file(FOUND_SHA256 "${OUTPUT_FILE}.sha256" HINTS ${WORK_DIR} NO_CACHE)

    if (FOUND AND FOUND_SHA256)
        message(STATUS "File ${FILE_PATH} already exists, checking sha256sum")
        file(SHA256 ${FILE_PATH} SHA256SUM)
        file(READ ${FILE_PATH}.sha256 SHA256SUM_EXPECTED)
        string(REPLACE "  ${FILE_NAME}\n" "" SHA256SUM_EXPECTED ${SHA256SUM_EXPECTED})
        if (NOT ${SHA256SUM} STREQUAL ${SHA256SUM_EXPECTED})
            message(STATUS "File ${OUTPUT_FILE} is corrupted, redownloading")
        else()
            message(STATUS "File ${OUTPUT_FILE} already exists and is not corrupted, skipping download")
            return()
        endif()
    else()
        message(STATUS "Downloading ${URL} to ${OUTPUT_FILE}")
    endif()

    file(REMOVE ${FILE_PATH} ${FILE_PATH}.sha256)

    file(DOWNLOAD ${URL} ${FILE_PATH} SHOW_PROGRESS)
    file(DOWNLOAD ${URL}.sha256 ${FILE_PATH}.sha256 SHOW_PROGRESS)

    file(SHA256 ${FILE_PATH} SHA256SUM)
    file(READ ${FILE_PATH}.sha256 SHA256SUM_EXPECTED)

    string(REPLACE "  ${FILE_NAME}\n" "" SHA256SUM_EXPECTED ${SHA256SUM_EXPECTED})

    if (NOT ${SHA256SUM} STREQUAL ${SHA256SUM_EXPECTED})
        message(FATAL_ERROR "File ${OUTPUT_FILE} is corrupted, sha256sum does not match")
    endif()
endfunction()

set(Blocks_SOURCE_DIR ${CMAKE_BINARY_DIR}/blocks)

download_and_check_file(
    "https://cdn.cubic-mc.com/${MINECRAFT_VERSION}/blocks-${MINECRAFT_VERSION}.json"
    blocks-${MINECRAFT_VERSION}.json
    ${CMAKE_BINARY_DIR}
)
download_and_check_file(
    "https://cdn.cubic-mc.com/${MINECRAFT_VERSION}/registries-${MINECRAFT_VERSION}.json"
    registries-${MINECRAFT_VERSION}.json
    ${CMAKE_BINARY_DIR}
)
download_and_check_file(
    "https://cdn.cubic-mc.com/${MINECRAFT_VERSION}/blocks-data-${MINECRAFT_VERSION}.json"
    blocks-data-${MINECRAFT_VERSION}.json
    ${CMAKE_CURRENT_BINARY_DIR}
)

find_package (Python3 REQUIRED Interpreter)

execute_process(
    COMMAND ${Python3_EXECUTABLE} protocol_block_ids.py -i ${CMAKE_BINARY_DIR}/blocks-1.19.3.json --get-generated-files
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/../generators
    COMMAND_ERROR_IS_FATAL ANY
    OUTPUT_VARIABLE BLOCKS_SRC
)

list(TRANSFORM BLOCKS_SRC PREPEND "${Blocks_SOURCE_DIR}/")
list(APPEND BLOCKS_SRC ${Blocks_SOURCE_DIR}/blocks.hpp)

add_custom_command(
    OUTPUT ${BLOCKS_SRC}
    COMMAND ${Python3_EXECUTABLE} protocol_block_ids.py -i ${CMAKE_BINARY_DIR}/blocks-1.19.3.json -o ${Blocks_SOURCE_DIR}/ --format
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/../generators
    DEPENDS ${CMAKE_BINARY_DIR}/../generators/protocol_block_ids.py
    MAIN_DEPENDENCY ${CMAKE_BINARY_DIR}/blocks-1.19.3.json
    VERBATIM
)

add_library(Blocks STATIC ${BLOCKS_SRC})
