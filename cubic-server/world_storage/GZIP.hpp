//
// Created by toma- on 18/01/2023.
//

#ifndef CUBICSERVER_GZIP_HPP
#define CUBICSERVER_GZIP_HPP

#include <vector>
#include <cstdint>
#include <string>
#include <zlib.h>

class GZIP
{
public:
    GZIP() : _chunk(0x4000) {};
    ~GZIP() = default;

    [[nodiscard]] std::vector<uint8_t> getBuffer()
    {
        return _buffer;
    }

    [[nodiscard]] uint64_t getChunk()
    {
        return _chunk;
    }

    void setChunk(uint64_t chunk)
    {
        _chunk = chunk;
    }

    std::vector<uint8_t> compress(std::vector<uint8_t> in)
    {
        unsigned char out[_chunk];

        _buffer.clear();

        z_stream strm;

        strm.zalloc = Z_NULL;
        strm.zfree = Z_NULL;
        strm.opaque = Z_NULL;

        deflateInit2(&strm, Z_DEFAULT_COMPRESSION, Z_DEFLATED, 15 | 16, 8, Z_DEFAULT_STRATEGY);

        strm.next_in = in.data();
        strm.avail_in = in.size();

        do {
            strm.avail_out = _chunk;
            strm.next_out = out;
            deflate(&strm, Z_FINISH);
            for (int i = 0; i < _chunk - strm.avail_out; ++i) {
                _buffer.push_back(out[i]);
            }
        } while (strm.avail_out == 0);

        deflateEnd(&strm);
        return _buffer;
    }

    std::vector<uint8_t> compress(std::vector<uint8_t> in, const char *path)
    {
        FILE *file = fopen(path, "w");

        this->compress(in);

        if (file) {
            fwrite(_buffer.data(), 1, _buffer.size(), file);
            fclose(file);
        }
        return _buffer;
    }

private:
    std::vector<uint8_t> _buffer;
    uint64_t _chunk;
};

#endif //CUBICSERVER_GZIP_HPP
