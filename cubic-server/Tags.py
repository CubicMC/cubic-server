from sys import exit

def main(prefix: bool, name : bool, json: bool):
    content = []
    with open("Tags.txt", "r") as f:
        lines = f.readlines()
    for line in lines:
        element = {}
        line = line.replace("\n", "").replace("\t", " ")
        element["id"] = line.split(" ")[0]
        line = line[line.find(" ") + 1:]
        element["name"] = ("minecraft:" if prefix else "") + line.split(" ")[0]
        element["texture"] = ("minecraft:" if prefix else "") + line[line.find(" ") + 1:].lower().replace(" ", "_")
        content.append(element)

    json = False

    if json:
        with open("Tags.json", "w") as f:
            f.write("[\n")
            for element in content:
                element["texture"] = element["texture"].replace("'", "$")
                if (name == False):
                    element["name"] = ""
                s = str(element).replace("'", "\"")
                f.write("\t" + s.replace("$", "'") + ",\n")
            f.write("]\n")
    else:
        with open("Tags.hpp", "w") as f:
            for element in content:
                if (name == True):
                    f.write("\"" + element["id"] + "\" \"" + element["name"] + "\" \"" + element["texture"] + "\"\n")
                else:
                    f.write("\"" + element["id"] + "\" \"" + element["texture"] + "\"\n")

main(False, False, True)
