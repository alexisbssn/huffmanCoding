#ifndef CODEPROVIDER_H
#define CODEPROVIDER_H
#include <vector>
#include <string>
#include "DataStructures/TAD/HashTable.h"

class CodeProvider
{
    public:
        CodeProvider();
        virtual ~CodeProvider();
        virtual void run(char*) = 0;
        virtual std::string getCodeForSymbol(char symbol) = 0;
        virtual std::string getSerializedKey() = 0;
        virtual void initFromSerializedString(std::string) = 0;
        virtual std::string getDataFromBits(std::string) = 0;
    protected:

    private:
};

#endif // CODEPROVIDER_H
