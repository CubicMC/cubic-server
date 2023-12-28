FROM alpine:latest

RUN apk add --no-cache \
    curl \
    libstdc++

WORKDIR /home/cubic-server

RUN curl -sSf https://raw.githubusercontent.com/CubicMC/cubic-server/master/bootstrap.sh | sh

EXPOSE 25565

ENTRYPOINT [ "./CubicServer_x86-64_MUSLLinux_0.3.0-beta" ]
