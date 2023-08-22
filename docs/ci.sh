#!/bin/bash

# DO NOT USE THAT SCRIPT IF YOU ARE A HUMAN
# AND IF YOU CAN READ THIS YOU MOST LIKELY ARE

cd docs
mkdir -pv $HOME/tmp
pushd $HOME/tmp
wget https://github.com/doxygen/doxygen/releases/download/Release_1_9_6/doxygen-1.9.6.linux.bin.tar.gz
tar -zxf doxygen-1.9.6.linux.bin.tar.gz
export PATH=$HOME/tmp/doxygen-1.9.6/bin:$PATH
popd

doxygen Doxyfile
