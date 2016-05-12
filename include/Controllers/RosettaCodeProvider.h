#ifndef ROSETTACODEPROVIDER_H
#define ROSETTACODEPROVIDER_H
#include <vector>
#include "Util/FileHelper.h"
#include "DataStructures/Huffman/HuffData.h"
#include "Controllers/CodeProvider.h"
#include "DataStructures/Huffman/HuffCodeTable.h"
#include "DataStructures/Huffman/HuffTree.h"

class RosettaCodeProvider : public CodeProvider
{
    public:
        RosettaCodeProvider();
        virtual ~RosettaCodeProvider();
        void run(char* str);
        void initFromSerializedString(std::string str){_huffTree = new HuffTree(str);};
        std::string getSerializedKey(){return _huffTree->serialize();};
        std::string huffTableToDebugString();
        std::string getDataFromBits(std::string);
        std::string getCodeForSymbol(char symbol){return _huffCodeTable->getCodeForSymbol(symbol);};
    protected:

    private:
        HuffCodeTable* _huffCodeTable;
        HuffTree* _huffTree;

        void buildHuffTable(char* str);
        void buildHuffTree();
        void fillTableWithHuffCodes();
};

#endif // ROSETTACODEPROVIDER_H
