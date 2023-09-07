/*
** ShipWreck Engine , 2023
** ChunkHeader.hpp
*/

#ifndef SW_PACKER_CHUNK_HPP
#define SW_PACKER_CHUNK_HPP

namespace sw
{
    enum resourceDataType {
        DATA_NULL = 0,
        DATA_RAW = 1,
    };

    struct chunkHeader {
        unsigned char   type[4];    // chunk type
        unsigned int    id;         // chunk identifier
        //unsigned char   comp;       // compression algorithm
        unsigned int    sizePack;   // compressed size
        unsigned int    sizeBase;   // base size
        //unsigned int    nextOffset; // next resource chunk
        unsigned int    crc32;      // data crc32
    };

    struct chunkData {
        char *path;
        unsigned int propsCount;
        unsigned int *props;
        void *data;
    };

    struct chunkResourceChunk {
        chunkHeader header;
        chunkData data;
    };
}

#endif //SW_PACKER_CHUNK_HPP
