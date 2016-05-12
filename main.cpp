#include <iostream>
#include "Controllers/HuffmanCodecEngine.h"
using namespace std;

int main(/*int argc, char *argv[]*/)
{
    int argc = 4;
    char *argv[] = {"huffman.exe","encode","C:\\Users\\alexis\\Downloads\\test.txt","C:\\Users\\alexis\\Downloads\\test.huff"};
    //char *argv[] = {"huffman.exe","decode","C:\\Users\\alexis\\Downloads\\test.huff","C:\\Users\\alexis\\Downloads\\test.decode"};
    if(argc != 4){
        return 1;
    }

    CodecEngine *ce = new HuffmanCodecEngine(argv[2],argv[3]);
    if(argv[1] == "encode"){
        ce->encode();
        return 0;
    }else if(argv[1] == "decode"){
        ce->decode();
        return 0;
    }
}
