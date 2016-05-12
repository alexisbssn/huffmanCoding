#ifndef HUFFCODETABLE_H
#define HUFFCODETABLE_H

#include <string>
#include "DataStructures/TAD/HashTable.h"
#include "DataStructures/Huffman/HuffData.h"
#include "DataStructures/TAD/SortedList.h"

class HuffCodeTable
{
    public:
        HuffCodeTable();
        virtual ~HuffCodeTable();
        char getSymbolForCode(std::string code);
        std::string getCodeForSymbol(char symbol);
        void setCodeForSymbol(std::string code, char symbol);
        void add(char);
        //const std::vector<HuffData*>& getData(){return _table;}
        HuffData* pop();
        HuffData* get(size_t i);
    protected:

    private:
        SortedList<HuffData*> dataList;
        bool isSorted;
};

#endif // HUFFCODETABLE_H
