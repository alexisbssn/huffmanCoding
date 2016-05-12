#include "Controllers/HuffmanCodecEngine.h"
#include "Controllers/RosettaCodeProvider.h"
#include <limits>
#include <bitset>
#include <iostream>
#include <sstream>

HuffmanCodecEngine::HuffmanCodecEngine(std::string inPath, std::string outPath)
:FileCodecEngine(inPath, outPath)
{
    _codeProvider = new RosettaCodeProvider();
}

HuffmanCodecEngine::~HuffmanCodecEngine()
{
    //dtor
}

void HuffmanCodecEngine::encode()
{
    char* toEncode = read();
    if(toEncode == nullptr){
        std::cout << "Could not read file";
        return;
    }
    _codeProvider->run(toEncode);
    std::string head = _codeProvider->getSerializedKey();
    std::string len = static_cast<std::ostringstream*>( &(std::ostringstream() << head.length()) )->str();
    head = len + ";" + head;
    // head should look like:
    // 114;asf5qe2d4tr...
    // ^length  ^head data
    writeHead(head.c_str());
    output = "";
    std::string data(toEncode);
    for(char c : data){
        pushBits(_codeProvider->getCodeForSymbol(c));
    }
    flushBitStream();
    writeBody(output.c_str());
}

void HuffmanCodecEngine::decode()
{
    // fill queue
    std::queue<char> inQueue;
    char* in = read();
    if(in == nullptr){
        std::cout << "Could not read file";
        return;
    }
    int i = 0;
    char c = in[i];
    while(c != '\0'){
        ++i;
        inQueue.push(c);
        c = in[i];
    }
    std::cout << "File read\n";

    // read head length
    int length;
    std::string siz = "";
    do{
        c = inQueue.front();
        siz += c;
        inQueue.pop();
    }while(c != ';');
    // string to int
    if (!(std::istringstream(siz) >> length)){
        length = 0;
    }

    // read head & build tree
    std::string head = "";
    for(int i = 0; i < length; ++i){
        head += inQueue.front();
        inQueue.pop();
    }
    _codeProvider->initFromSerializedString(head);
    writeHead("");
    std::cout << "Tree rebuilt from file\n";

    // read body & write to file
    std::string toDecode = "";//(in, length, inQueue.size());
    while(inQueue.size() != 0){
        toDecode += inQueue.front();
        inQueue.pop();
    }
    std::string bits = "";
    for(unsigned char c : toDecode){
        std::bitset<CHAR_BIT> cbits(c);
        bits += cbits.to_string();
    }
    writeBody(_codeProvider->getDataFromBits(bits).c_str());
    std::cout << "Decode finished";
}

void HuffmanCodecEngine::pushBits(std::string s)
{
    for(char c : s){
        bits.push(c);
        if(bits.size() == CHAR_BIT){
            flushBitStream();
        }
    }
}

void HuffmanCodecEngine::flushBitStream()
{
    while(bits.size() < CHAR_BIT){
        bits.push('0');
    }
    std::string s = "";
    for(int i = 0; i < CHAR_BIT; ++i){
        s += bits.front();
        bits.pop();
    }
    std::bitset<CHAR_BIT> aChar(s);
    unsigned long i = aChar.to_ulong();
    unsigned char c = static_cast<unsigned char>( i );
    output += c;
    if(output.length() == 100){
        writeBody(output.c_str());
        output = "";
    }
}
