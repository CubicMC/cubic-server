import json
import sys
from num2words import num2words

def change_item_in_list(list, elem):
    for i in range(len(list)):
        if list[i][0] == elem[0]:
            list[i] = elem
            return list
    list.append(elem)
    return list

class Block:
    def __init__(self, name, data):
        valid = True
        self.name = name
        self.properties = data["properties"] if "properties" in data else []
        self.states = data["states"]
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

    def toProtocol(self):
        data = "constexpr Block toProtocol("
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

    def paletteToProtocol(self):
        data = ""
        return data

    def namespace(self):
        data = "namespace " + self.name.split(":")[1].title().replace("_", "") + " {\n"
        data += self.Properties()
        data += self.toProtocol()
        data += self.paletteToProtocol()
        data += "}\n"
        return data + "\n"

    def fromNameToProtocolId(self):
        data = ""
        return data

    def toName(self):
        data = ""
        for state in self.states:
            data += "case " + str(state["id"]) + ":\n"
        data += "return \"" + self.name + "\";\n"
        return data

blocks = []
with open(sys.argv[1]) as f:
    data = json.load(f)

for block in data:
    blocks.append(Block(block, data[block]))

with open("generated.hpp", "w") as f:
    f.write("""#include <string>
#include <cstdint>
#include <vector>
#include <stdexcept>

typedef uint16_t Block;

namespace Blocks {\n""")
    for block in blocks :
        f.write(block.namespace())

    f.write("constexpr Block fromNameToProtocolId(std::string name, std::vector<std::pair<std::string, std::string>> properties) {\n")
    for block in blocks :
        f.write(block.fromNameToProtocolId())
    f.write("return 0;\n")
    f.write("}\n")

    f.write("constexpr std::string toName(Block id) {\n" +
        "switch (id) {\n")
    for block in blocks :
        f.write(block.toName())
    f.write("}\n" +
        "return nullptr;\n" +
        "}\n")
    f.write("}\n")
