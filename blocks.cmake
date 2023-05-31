function(download_and_check_file URL OUTPUT_FILE WORK_DIR)
    find_file(FOUND ${OUTPUT_FILE} PATHS ${WORK_DIR})

    if (FOUND)
        execute_process(COMMAND sha256sum --quiet -c ${OUTPUT_FILE}.sha256 WORKING_DIRECTORY ${WORK_DIR} RESULT_VARIABLE SHA256_RESULT)
        if (NOT ${SHA256_RESULT} EQUAL 0)
            message(STATUS "File ${OUTPUT_FILE} is corrupted, redownloading")
            execute_process(COMMAND rm -f ${OUTPUT_FILE} WORKING_DIRECTORY ${WORK_DIR})
            execute_process(COMMAND rm -f ${OUTPUT_FILE}.sha256 WORKING_DIRECTORY ${WORK_DIR})
        else()
            message(STATUS "File ${OUTPUT_FILE} already exists and is not corrupted, skipping download")
            return()
        endif()
    else()
        message(STATUS "Downloading ${URL} to ${OUTPUT_FILE}")
    endif()

    execute_process(COMMAND wget -q ${URL} -O ${OUTPUT_FILE} WORKING_DIRECTORY ${WORK_DIR})
    execute_process(COMMAND wget -q ${URL}.sha256 -O ${OUTPUT_FILE}.sha256 WORKING_DIRECTORY ${WORK_DIR})
    execute_process(COMMAND sha256sum --quiet -c ${OUTPUT_FILE}.sha256 WORKING_DIRECTORY ${WORK_DIR} COMMAND_ERROR_IS_FATAL ANY)
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

find_package (Python3 REQUIRED Interpreter)

# execute_process(
#     COMMAND python3 -m venv .venv
#     WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/../generators
#     COMMAND_ERROR_IS_FATAL ANY
# )

# execute_process(
#     COMMAND .venv/bin/pip install -r requirements.txt
#     WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/../generators
#     COMMAND_ERROR_IS_FATAL ANY
# )

execute_process(
    COMMAND ${Python3_EXECUTABLE} protocol_block_ids.py -i ${CMAKE_BINARY_DIR}/blocks-1.19.3.json --get-generated-files
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/../generators
    COMMAND_ERROR_IS_FATAL ANY
    OUTPUT_VARIABLE BLOCKS_SRC
)
list(TRANSFORM BLOCKS_SRC PREPEND "${Blocks_SOURCE_DIR}/")
list(APPEND BLOCKS_SRC ${Blocks_SOURCE_DIR}/blocks.hpp)

# execute_process(
#     COMMAND .venv/bin/python protocol_block_ids.py -i ${CMAKE_BINARY_DIR}/blocks-1.19.3.json -o ${Blocks_SOURCE_DIR}/ --format
#     WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/../generators
#     COMMAND_ERROR_IS_FATAL ANY
# )

add_custom_command(
    OUTPUT ${BLOCKS_SRC}
    COMMAND ${Python3_EXECUTABLE} protocol_block_ids.py -i ${CMAKE_BINARY_DIR}/blocks-1.19.3.json -o ${Blocks_SOURCE_DIR}/ --format
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/../generators
    DEPENDS ${CMAKE_BINARY_DIR}/../generators/protocol_block_ids.py
    MAIN_DEPENDENCY ${CMAKE_BINARY_DIR}/blocks-1.19.3.json
    VERBATIM
)

add_library(Blocks STATIC ${BLOCKS_SRC})
