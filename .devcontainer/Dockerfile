FROM mcr.microsoft.com/devcontainers/cpp:0-ubuntu-22.04

ARG REINSTALL_CMAKE_VERSION_FROM_SOURCE="none"

# Optionally install the cmake for vcpkg
COPY ./reinstall-cmake.sh /tmp/

RUN if [ "${REINSTALL_CMAKE_VERSION_FROM_SOURCE}" != "none" ]; then \
    chmod +x /tmp/reinstall-cmake.sh && /tmp/reinstall-cmake.sh ${REINSTALL_CMAKE_VERSION_FROM_SOURCE}; \
    fi \
    && rm -f /tmp/reinstall-cmake.sh

# [Optional] Uncomment this section to install additional vcpkg ports.
# RUN su vscode -c "${VCPKG_ROOT}/vcpkg install <your-port-name-here>"

# [Optional] Uncomment this section to install additional packages.
# RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
#     && apt-get -y install --no-install-recommends <your-package-list-here>
RUN echo "deb http://apt.llvm.org/jammy/ llvm-toolchain-jammy-15 main" | sudo tee -a /etc/apt/sources.list

RUN echo "deb-src http://apt.llvm.org/jammy/ llvm-toolchain-jammy-15 main" | sudo tee -a /etc/apt/sources.list

RUN wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | sudo apt-key add -

RUN sudo apt-get update

RUN sudo apt-get install -y gcc-12 g++-12 cmake pkg-config gtkmm-3.0 clang-15 clangd clang-format-15

RUN echo 'export CC=/usr/bin/gcc-12' >> ~/.bashrc

RUN echo 'export CXX=/usr/bin/g++-12' >> ~/.bashrc

RUN echo 'alias format-all="find cubic-server/ -iname *.hpp -o -iname *.cpp | xargs clang-format-15 --style=file -i"' >> ~/.bashrc
