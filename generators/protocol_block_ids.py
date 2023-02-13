import json
import argparse
import os
from num2words import num2words

# Variables for formatting the output
global indentation
indentation = 0
global is_switch
is_switch = 0
global formated
formated = True

# Variable for the number of protocol ids
global number_of_protocol_ids
number_of_protocol_ids = 0

# used to format the output
def writer(data, file):
    global indentation
    global is_switch
    global formated
    if formated:
        lines = data.splitlines()
        for line in lines:
            if line:
                if (line.startswith("switch")):
                    is_switch += 1
                if line[0] == "}" and is_switch == 0:
                    indentation -= 4
            file.write((" " * indentation if line else "") + line + "\n")
            if line:
                if line[-1] == "}" and is_switch > 0:
                    is_switch -= 1
                    if is_switch > 0:
                        indentation -= 4
                if line[-1] == ":" and line.startswith("case") and is_switch > 0:
                    indentation += 4
                if line[-1] == ";" and line.startswith("return") and is_switch > 0:
                    indentation -= 4
                if line[-1] == "{" and is_switch == 0:
                    indentation += 4
    else:
        file.write(data)

# used to add an element to a list of dict/tuple if it doesn't exist, and if it does, it replaces it
def change_item_in_list(list, elem):
    for i in range(len(list)):
        if list[i][0] == elem[0]:
            list[i] = elem
            return list
    list.append(elem)
    return list

# store the data of each block
class Block:
    # initialize the class aka get the data from the json file
    def __init__(self, name, data):
        valid = True
        self.name = name
        self.properties = data["properties"] if "properties" in data else [] # this stores the properties of the block and if it doesn't have any, it stores an empty list
        self.states = data["states"]
        # check if the block has a "short" property (and so a short state),
        # if it does, it renames it to "short_" and adds it to the list of properties (and to the states) cause short is a reserved keyword in c++
        for prop in self.properties:
            if prop == "short":
                valid = False
        if valid == False:
            new_properties = {}
            for prop in self.properties:
                if prop == "short":
                    new_properties["short_"] = self.properties[prop]
                else:
                    new_properties[prop] = self.properties[prop]
            self.properties = new_properties
            new_states = []
            for state in self.states:
                new_state = {}
                for prop in state["properties"]:
                    if prop == "short":
                        new_state["short_"] = state["properties"][prop]
                    else:
                        new_state[prop] = state["properties"][prop]
                new_states.append({"id": state["id"], "properties": new_state})
            self.states = new_states

    # get the protocol id of a specific state of the block
    def get_protocol_id_from_state(self, state):
        valid = False
        for each in self.states:
            for prop in state:
                if each["properties"][prop[0]] != prop[1]:
                    valid = False
                    break
                else:
                    valid = True
            if valid:
                return str(each["id"])
        return 0

    # print the switch statement of the toProtocol function (it's recursive)
    def print_switch(self, remaining_props, state, data):
        data += "switch (" + remaining_props[0] + ") {\n"
        for each in self.properties[remaining_props[0]]:
                data += "case Properties::" + remaining_props[0].capitalize() + "::" + (num2words(each).replace("-", "_").upper() if each.isdigit() else each.upper()) + ":\n"
                if len(remaining_props) > 1:
                    state = change_item_in_list(state, (remaining_props[0], each))
                    data = self.print_switch(remaining_props[1:], state, data)
                else:
                    state = change_item_in_list(state, (remaining_props[0], each))
                    data += "return " + self.get_protocol_id_from_state(state) + ";\n"
        data += "}\n"
        return data

    # print the different properties of the block in the header file as enums
    def Properties(self):
        data = ""
        if self.properties != []:
            data += "namespace Properties {\n"
            for prop in self.properties:
                data += "enum class " + prop.capitalize() + " {\n"
                for each in self.properties[prop]:
                    if each.isdigit():
                        data += num2words(each).replace("-", "_").upper() + ",\n"
                    else:
                        data += each.upper() + ",\n"
                data = data[:-2] + "\n};\n"
            data += "}\n"

        return data

    # print the toProtocol function in the header file
    def toProtocol(self):
        data = "constexpr BlockId toProtocol("
        if self.properties != []:
            for prop in self.properties:
                data += "Properties::" + prop.capitalize() + " " + prop + ", "
            data = data[:-2]
        data += ") {\n"
        if self.properties != []:
            all_props = []
            for prop in self.properties:
                all_props.append(prop)
            data = self.print_switch(all_props, [], data)
            data += "return 0;\n"
        else:
            data += "return " + str(self.states[0]["id"]) + ";\n"
        data += "}\n"

        return data

    # print the paletteToProtocol function in the header file
    def paletteToProtocol(self):
        data = "constexpr BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {\n"
        data += "if (properties.size() != " + str(len(self.properties)) + ")\n"
        data += "throw std::runtime_error(\"Invalid number of properties\");\n"
        if self.properties != []:
            for prop in self.properties:
                data += "Properties::" + prop.capitalize() + " " + prop + ";\n"
            data += "for (auto prop : properties) {\n"
            first_prop = True
            for prop in self.properties:
                first_value = True
                if first_prop:
                    data += "if (prop.first == \"" + prop + "\") {\n"
                    first_prop = False
                else:
                    data += "} else if (prop.first == \"" + prop + "\") {\n"
                for each in self.properties[prop]:
                    if first_value:
                        data += "if (prop.second == \"" + each + "\") {\n"
                        first_value = False
                    else:
                        data += "} else if (prop.second == \"" + each + "\") {\n"
                    # this line add to data the value of the property (for example "face")
                    # the enum of the property (for example "Face")
                    # the value of the property (for example "floor")
                    # if the value is a number it converts it to a string
                    # if the value contains a "-" it replaces it with "_"
                    data += prop + " = Properties::" + prop.capitalize() + "::" + (num2words(each).replace("-", "_").upper() if each.isdigit() else each.upper()) + ";\n"
                data += "} else {\n"
                data += "throw std::runtime_error(\"Invalid property \\\"" + prop + "\\\" value\");\n"
                data += "}\n"
            data += "} else {\n"
            data += "throw std::runtime_error(\"Invalid property name\");\n"
            data += "}\n"
            data += "}\n"
            data += "return toProtocol(" + ", ".join(self.properties) + ");\n"
        else:
            data += "return toProtocol();\n"
        data += "}\n"
        return data

    # print the namespace of the block in the header file and so all the things that are inside it
    def namespace(self):
        data = "namespace " + self.name.split(":")[1].title().replace("_", "") + " {\n"
        data += self.Properties()
        data += self.toProtocol()
        data += self.paletteToProtocol()
        data += "}\n"
        return data + "\n"

    # print the name of the block and the function that returns the protocol id of the block
    def nameToProtocolId(self):
        return "{\"" + self.name + "\", " + self.name.split(":")[1].title().replace("_", "") + "::paletteToProtocol},\n"

    # print the toName function that returns the name of the block and the properties of the block from the protocol id
    def toName(self):
        global number_of_protocol_ids
        data = ""
        for state in self.states:
            number_of_protocol_ids += 1
            data += "case " + str(state["id"]) + ":\n"
            data += "return {\"" + self.name + "\", {"
            if self.properties != []:
                for prop in self.properties:
                    data += "{\"" + prop + "\", \"" + state["properties"][prop] + "\"}, "
                data = data[:-2]
            data += "}};\n"
        return data

# load the json file
def load_json(filename):
    blocks = []
    with open(filename) as f:
        data = json.load(f)

    for block in data:
        blocks.append(Block(block, data[block]))
    return blocks

# write the header file
def write_header_file(filename, blocks):
    with open(filename + ".hpp", "w") as f:
        writer("#include <string>\n", f)
        writer("#include <cstdint>\n", f)
        writer("#include <vector>\n", f)
        writer("#include <stdexcept>\n", f)
        writer("#include <unordered_map>\n", f)
        writer("#include <functional>\n\n", f)

        writer("namespace Blocks {\n", f)
        writer("typedef int32_t BlockId;\n\n", f)

        writer("struct Block {", f)
        writer("std::string name;\n", f)
        writer("std::vector<std::pair<std::string, std::string>> properties;\n", f)
        writer("};\n\n", f)

        for block in blocks :
            writer(block.namespace(), f)

        writer("static const std::unordered_map<std::string, std::function<BlockId(std::vector<std::pair<std::string, std::string>>)>> nameToProtocolId {\n", f)
        for block in blocks :
            writer(block.nameToProtocolId(), f)
        writer("};\n\n", f)

        writer("BlockId fromNameToProtocolId(Block block);\n", f)
        writer("Block toName(BlockId id);\n", f)

        writer("constexpr int NUMBER_OF_PROTOCOL_IDS = " + str(number_of_protocol_ids) + ";\n", f)
        writer("}\n", f)

# write the source file
def write_source_file(filename, blocks):
    with open(filename + ".cpp", 'w') as f:
        writer("#include \"" + filename.split("/")[-1] + ".hpp\"\n\n", f)

        writer("namespace Blocks {\n", f)
        writer("BlockId fromNameToProtocolId(Block block) {\n", f)
        writer("return nameToProtocolId.at(block.name)(block.properties); // this may throw an exception\n", f)
        writer("}\n\n", f)

        writer("Block toName(BlockId id) {\n", f)
        writer("switch (id) {\n", f)
        for block in blocks :
            writer(block.toName(), f)
        writer("}\n", f)
        writer("return {\"minecraft:air\", {}};\n", f)
        writer("}\n", f)
        writer("}\n", f)

# get different option you can pass to the script
def parse_args(options):
    global formated
    parser = argparse.ArgumentParser()
    parser.add_argument("-i", "--input", help="input file", default=options["input"])
    parser.add_argument("-o", "--output", help="output file", default=options["output"])
    parser.add_argument("-f", "--format", help="format the code", action=argparse.BooleanOptionalAction)
    args = parser.parse_args()
    if args.input != "blocks.json":
        print("I hope you know what you are doing, cause for now the script only works with the blocks.json file")
    options["input"] = args.input
    options["output"] = args.output
    formated = args.format
    return options

def main():
    options = {"input": "blocks.json", "output": "generated/blocks"}
    options = parse_args(options)
    blocks = load_json(options["input"])
    os.makedirs(os.path.dirname(options["output"]), exist_ok=True)
    write_header_file(options["output"], blocks)
    write_source_file(options["output"], blocks)

if __name__ == "__main__":
    main()
