#ifndef FILEHELPER_H
#define FILEHELPER_H
#include <string>

class FileHelper
{
    public:
        FileHelper(std::string path):_path(path){};
        virtual ~FileHelper();
        char* readFile();
        void overwrite(const char*);
        void append(const char*);

    protected:

    private:
        std::string _path;
};

#endif // FILEHELPER_H
