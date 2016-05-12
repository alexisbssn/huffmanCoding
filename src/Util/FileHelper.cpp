#include "Util/FileHelper.h"
#include <fstream>

using namespace std;

FileHelper::~FileHelper()
{
    //dtor
}

char* FileHelper::readFile()
{
    streampos size;
    char * memblock;
    std::string path = _path;
    ifstream file(_path, ios::in|ios::binary|ios::ate);
    if (file.is_open())
    {
        size = file.tellg();
        memblock = new char [size];
        file.seekg (0, ios::beg);
        file.read (memblock, size);
        file.close();
        return memblock;
    }
    return nullptr;
}

void FileHelper::overwrite(const char* text)
{
    ofstream file;
    file.open (_path, ios::out | ios::trunc | ios::binary);
    if (file.is_open())
    {
        file << text;
        file.close();
    }
}

void FileHelper::append(const char* text)
{
    ofstream file;
    file.open (_path, ios::out | ios::app | ios::binary);
    if (file.is_open())
    {
        file << text;
        file.close();
    }
}
