#ifndef HUFFMANCODECENGINE_H
#define HUFFMANCODECENGINE_H

#include "Controllers/FileCodecEngine.h"
#include <queue>

class HuffmanCodecEngine : public FileCodecEngine
{
    public:
        HuffmanCodecEngine(std::string inPath, std::string outPath);
        virtual ~HuffmanCodecEngine();
        void encode();
        void decode();

    protected:

    private:
        void pushBits(std::string);
        void flushBitStream();
        std::queue<char> bits;
        std::string output;
};

#endif // HUFFMANCODECENGINE_H
