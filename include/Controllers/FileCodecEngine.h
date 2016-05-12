#ifndef FILECODECENGINE_H
#define FILECODECENGINE_H

#include "Controllers/CodecEngine.h"
#include "Util/FileHelper.h"
#include "Controllers/CodeProvider.h"


class FileCodecEngine : public CodecEngine
{
    public:
        FileCodecEngine(std::string inPath, std::string outPath):_inFile(new FileHelper(inPath)), _outFile(new FileHelper(outPath)){};
        virtual ~FileCodecEngine();
    protected:
        void writeHead(const char* head);
        void writeBody(const char* body);
        char* read();
        FileHelper* _inFile;
        FileHelper* _outFile;
        CodeProvider* _codeProvider;

    private:

};

#endif // FILECODECENGINE_H
