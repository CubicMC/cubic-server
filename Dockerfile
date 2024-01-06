FROM alpine:3.19 AS builder

RUN apk add --no-cache \
    git \
    make \
    cmake \
    python3 \
    zlib-dev \
    curl-dev \
    clang \
    boost-dev

WORKDIR /home/cubic-server

COPY CMakeLists.txt .
COPY cubic-server cubic-server
COPY generators generators
COPY blocks.cmake .
COPY boost.cmake .
COPY c_flag_overrides.cmake .
COPY cxx_flag_overrides.cmake .

RUN cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -DUSE_CLANG=true -DNO_GUI=true

RUN cmake --build build -j`nproc --ignore=1`

FROM alpine:3.19 AS runner

# curl is needed because the library is not linked statically
RUN apk add --no-cache \
    libstdc++ \
    curl

WORKDIR /home/cubic-server

COPY --from=builder /home/cubic-server/build/CubicServer ./
COPY --from=builder /home/cubic-server/build/blocks-*.json ./
COPY --from=builder /home/cubic-server/build/registries-*.json ./
COPY --from=builder /home/cubic-server/build/assets ./

ENTRYPOINT [ "./CubicServer" ]
