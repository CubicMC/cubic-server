template = """#ifndef WORLD_STORAGE_GLOBAL_PALETTE_TEMP_HPP
#define WORLD_STORAGE_GLOBAL_PALETTE_TEMP_HPP

// TODO: generate this file LOL

#include "Block.hpp"

namespace world_storage
{{

constexpr uint32_t getGlobalPaletteIdFromBlockName(const std::string &name)
{{
    if (name == "minecraft:air") return 0;
{getGlobalPaletteIdFromBlockName}

    // Default
    return 0;
}}

uint32_t getGlobalPaletteIdFromBlock(const Block &block)
{{
    return getGlobalPaletteIdFromBlockName(block.toString());
}}

constexpr std::string getBlockFromGlobalPaletteId(uint32_t id)
{{
    if (id == 0) return "minecraft:air";
{getBlockFromGlobalPaletteId}

    return "minecraft:air";
}}

}} // namespace world_storage

#endif // WORLD_STORAGE_GLOBAL_PALETTE_TEMP_HPP
"""

import os
import sys
import json

def toBlockTest(name, id):
    return f"    else if (name == \"{name}\") return {id};"

def toIdTest(name, id):
    return f"    else if (id == {id}) return \"{name}\";"

def main():
    if len(sys.argv) != 2:
        print(f"{sys.argv[0]} registry-blocks.json")
        exit(1)

    file = open(sys.argv[1], 'r')

    registry = json.load(file)

    idsTests = []
    blocksTests = []

    for name in registry:
        block = registry[name]

        for state in block["states"]:
            if "default" in state and state["default"] == True:
                blocksTests.append(toBlockTest(name, state["id"]))
                idsTests.append(toIdTest(name, state["id"]))

            if "properties" in state:
                propertiesArray = []
                for key, value in state["properties"].items():
                    propertiesArray.append(f"{key}={value}")
                propertiesStr = ','.join(propertiesArray)

                blocksTests.append(toBlockTest(f"{name}[{propertiesStr}]", state["id"]))
                idsTests.append(toIdTest(f"{name}[{propertiesStr}]", state["id"]))

    outputStr = template.format(
        getGlobalPaletteIdFromBlockName = "\n".join(blocksTests),
        getBlockFromGlobalPaletteId = "\n".join(idsTests)
    )

    with open("generated.hpp", 'w') as output:
        output.write(outputStr)

    file.close()

if __name__ == "__main__":
    main()
