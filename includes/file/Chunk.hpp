/*
** SWPacker , 2023
** ChunkHeader.hpp
*/

#ifndef SW_PACKER_CHUNK_HPP
#define SW_PACKER_CHUNK_HPP

namespace sw
{
    /// \brief Define all data type supported. Few for now
    /// but will add more later
    enum resourceDataType {
        DATA_NULL = 0,
        DATA_RAW = 1,
    };

    /// \brief Define all data in the header for a single chunk.
    /// \b comp and \b nextOffset will be added later
    struct chunkHeader {
        unsigned char   type[4];    // chunk type
        unsigned int    id;         // chunk identifier
      //unsigned char   comp;       // compression algorithm
        unsigned int    sizePack;   // compressed size
        unsigned int    sizeBase;   // base size
      //unsigned int    nextOffset; // next resource chunk
        unsigned int    crc32;      // data crc32
    };

    /// \brief Define all data needed un a chunk.
    /// \b Props is useless a the moment but useful later
    /// \b Path is useful only for a DEVPACK
    struct chunkData {
        unsigned int propsCount;    // Number of props uin the chunk
        unsigned int pathCount;     // Length of the path
        unsigned int *props;        // List of props
        char *path;                 // Path
        void *data;                 // Raw data
    };

    /// \brief Structure for a chunk, composed of one header and one data
    struct resourceChunk {
        chunkHeader header;
        chunkData data;
    };
}

#endif //SW_PACKER_CHUNK_HPP
