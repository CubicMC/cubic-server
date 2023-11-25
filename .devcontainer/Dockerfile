FROM mcr.microsoft.com/devcontainers/cpp:0-ubuntu-22.04

RUN echo "deb http://apt.llvm.org/jammy/ llvm-toolchain-jammy-16 main" | sudo tee -a /etc/apt/sources.list

RUN echo "deb-src http://apt.llvm.org/jammy/ llvm-toolchain-jammy-16 main" | sudo tee -a /etc/apt/sources.list

RUN wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | sudo apt-key add -

RUN sudo apt-get update

RUN sudo apt-get install -y gcc-12 g++-12 cmake pkg-config gtkmm-3.0 clang-16 clangd clang-format-16 python3.10-venv

RUN wget https://boostorg.jfrog.io/artifactory/main/release/1.82.0/source/boost_1_82_0.tar.gz

RUN tar xvf boost_1_82_0.tar.gz

WORKDIR boost_1_82_0

RUN ./bootstrap.sh --prefix=/usr/

RUN sudo ./b2 install -j$((`nproc`-1))

WORKDIR /

RUN sudo rm -rf boost_1_82_0*

RUN sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-12 12

RUN sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-12 12

RUN sudo update-alternatives --install /usr/bin/clang clang /usr/bin/clang-16 16

RUN sudo update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-16 16

RUN echo 'alias format-all="find cubic-server/ -iname *.hpp -o -iname *.cpp | xargs clang-format-16 --style=file -i"' >> /home/vscode/.bashrc
