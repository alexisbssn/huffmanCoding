#include "Controllers/FileCodecEngine.h"

FileCodecEngine::~FileCodecEngine()
{
    //dtor
}

void FileCodecEngine::writeHead(const char* head)
{
    _outFile->overwrite(head);
}
void FileCodecEngine::writeBody(const char* body)
{
    _outFile->append(body);
}
char* FileCodecEngine::read()
{
    return _inFile->readFile();
}
