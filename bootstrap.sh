#!/bin/sh

set -e

Help()
{
   # Display Help
   echo "Add description of the script functions here."
   echo
   echo "Syntax: scriptTemplate [-h|--help|-v|--version|-m|--minecraft-version|-f|--file|-s|--server-version]"
   echo "options:"
   echo -e "-h | --help\t\t\tPrint this Help."
   echo -e "-v | --version\t\t\tPrint bootstrap.sh version."
   echo -e "-m | --minecraft-version\tChoose the Minecraft version."
   echo -e "-f | --file\t\t\tChoose a file to download."
   echo -e "-s | --server-version\t\tSelect a CubicServer release."
   echo
}

DownloadFiles=true
ExtractFiles=false
ToExtract=""
MinecraftVersion="1.19.3"
ServerVersion="0.3.0-beta"
OperatingSystem="GNULinux"

if ldd /bin/ls | grep -oq musl; then
    OperatingSystem="MUSLLinux"
else
    OperatingSystem="GNULinux"
fi

while true; do
  case "$1" in
    -h | --help ) # display help
        Help;
        exit;;
    -v | --version ) # Print the version of this script
        echo "0.0.1";
        exit;;
    -m | --minecraft-version ) # Choose the Minecraft version
        MinecraftVersion="$2";
        shift 2 ;;
    -f | --file ) # Choose a file to download
        ToExtract="$2";
        ExtractFiles=true;
        shift 2 ;;
    -s | --server-version ) # Select a CubicServer release
        ServerVersion="$2";
        shift 2;;
    -- ) shift; break ;;
    * ) break ;;
  esac
done

if [ $ExtractFiles == true]; then
    case $ToExtract in
    loot_tables) # download loot_tables
        wget https://cdn.cubic-mc.com/$MinecraftVersion/loot_tables.tar.gz
        wget https://cdn.cubic-mc.com/$MinecraftVersion/loot_tables.tar.gz.sha256
        sha256sum --check loot_tables.tar.gz.sha256
        mkdir -p assets
        tar xf loot_tables.tar.gz --directory=assets/;;
    recipes) # download recipes
        mkdir -p assets
        wget https://cdn.cubic-mc.com/$MinecraftVersion/recipes.tar.gz
        wget https://cdn.cubic-mc.com/$MinecraftVersion/recipes.tar.gz.sha256
        sha256sum --check recipes.tar.gz.sha256
        mkdir -p assets
        tar xf recipes.tar.gz --directory=assets/;;
    blocks.json) # download blocks.json
        wget https://cdn.cubic-mc.com/$MinecraftVersion/blocks-$MinecraftVersion.json
        wget https://cdn.cubic-mc.com/$MinecraftVersion/blocks-$MinecraftVersion.json.sha256
        sha256sum --check blocks-$MinecraftVersion.json.sha256;;
    registries.json) # download registries.json
        wget https://cdn.cubic-mc.com/$MinecraftVersion/registries-$MinecraftVersion.json
        wget https://cdn.cubic-mc.com/$MinecraftVersion/registries-$MinecraftVersion.json.sha256
        sha256sum --check registries-$MinecraftVersion.json.sha256;;
    CubicServer) # download CubicServer
        wget https://github.com/CubicMC/cubic-server/releases/download/$ServerVersion/CubicServer_x86-64_GNULinux_dev;;
    \?) # file does not exist on the cdn
        echo "Error: file does not exist"
        exit 1
    esac
else
    wget https://cdn.cubic-mc.com/$MinecraftVersion/loot_tables.tar.gz
    wget https://cdn.cubic-mc.com/$MinecraftVersion/loot_tables.tar.gz.sha256
    sha256sum -c loot_tables.tar.gz.sha256
    rm loot_tables.tar.gz.sha256

    wget https://cdn.cubic-mc.com/$MinecraftVersion/recipes.tar.gz
    wget https://cdn.cubic-mc.com/$MinecraftVersion/recipes.tar.gz.sha256
    sha256sum -c recipes.tar.gz.sha256
    rm recipes.tar.gz.sha256

    wget https://cdn.cubic-mc.com/$MinecraftVersion/blocks-$MinecraftVersion.json
    wget https://cdn.cubic-mc.com/$MinecraftVersion/blocks-$MinecraftVersion.json.sha256
    sha256sum -c blocks-$MinecraftVersion.json.sha256
    rm blocks-$MinecraftVersion.json.sha256

    wget https://cdn.cubic-mc.com/$MinecraftVersion/registries-$MinecraftVersion.json
    wget https://cdn.cubic-mc.com/$MinecraftVersion/registries-$MinecraftVersion.json.sha256
    sha256sum -c registries-$MinecraftVersion.json.sha256
    rm registries-$MinecraftVersion.json.sha256

    wget https://github.com/CubicMC/cubic-server/releases/download/$ServerVersion/CubicServer_x86-64_${OperatingSystem}_$ServerVersion
    chmod +x CubicServer_x86-64_${OperatingSystem}_$ServerVersion
    mkdir -p assets
    tar xf loot_tables.tar.gz --directory=assets/
    tar xf recipes.tar.gz --directory=assets/
    rm loot_tables.tar.gz
    rm recipes.tar.gz
fi
