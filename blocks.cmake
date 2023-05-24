function(download_and_check_file URL OUTPUT_FILE WORK_DIR)
    execute_process(COMMAND wget --verbose --show-progress ${URL} -O ${OUTPUT_FILE} WORKING_DIRECTORY ${WORK_DIR})
    execute_process(COMMAND wget --verbose --show-progress ${URL}.sha256 -O ${OUTPUT_FILE}.sha256 WORKING_DIRECTORY ${WORK_DIR})
    execute_process(COMMAND sha256sum --check ${OUTPUT_FILE}.sha256 COMMAND_ERROR_IS_FATAL ANY WORKING_DIRECTORY ${WORK_DIR})
endfunction()

set(Blocks_SOURCE_DIR ${CMAKE_BINARY_DIR}/blocks)

download_and_check_file(
    "https://cdn.cubic-mc.com/${MINECRAFT_VERSION}/blocks-${MINECRAFT_VERSION}.json"
    "${CMAKE_BINARY_DIR}/blocks-${MINECRAFT_VERSION}.json"
    ${CMAKE_BINARY_DIR}
)
download_and_check_file(
    "https://cdn.cubic-mc.com/${MINECRAFT_VERSION}/registries-${MINECRAFT_VERSION}.json"
    "${CMAKE_BINARY_DIR}/registries-${MINECRAFT_VERSION}.json"
    ${CMAKE_BINARY_DIR}
)

find_package (Python3 REQUIRED)

execute_process(
    COMMAND python3 -m venv "${CMAKE_BINARY_DIR}/../generators/.venv"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/../generators
    COMMAND_ERROR_IS_FATAL ANY
)

execute_process(
    COMMAND .venv/bin/pip install -r requirements.txt
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/../generators
    COMMAND_ERROR_IS_FATAL ANY
)

execute_process(
    COMMAND .venv/bin/python protocol_block_ids.py -i ${CMAKE_BINARY_DIR}/blocks-1.19.3.json --get-generated-files
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/../generators
    COMMAND_ERROR_IS_FATAL ANY
    OUTPUT_VARIABLE BLOCKS_SRC
)

execute_process(
    COMMAND .venv/bin/python protocol_block_ids.py -i ${CMAKE_BINARY_DIR}/blocks-1.19.3.json -o ${Blocks_SOURCE_DIR}/ --format
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/../generators
    COMMAND_ERROR_IS_FATAL ANY
)

list(TRANSFORM BLOCKS_SRC PREPEND "${Blocks_SOURCE_DIR}/")

add_library(Blocks STATIC ${BLOCKS_SRC} ${Blocks_SOURCE_DIR}/blocks.hpp)
