#ifndef BINARYNODE_H
#define BINARYNODE_H
#include "HuffData.h"
class HuffNode
{
    public:
        HuffNode(HuffData*);
        HuffNode(unsigned virtualFrequency):_value(nullptr), _leftChild(nullptr), _rightChild(nullptr),  _virtualFrequency(virtualFrequency){};
        virtual ~HuffNode();

        HuffData* _value;
        HuffNode* _leftChild;
        HuffNode* _rightChild;
        unsigned _virtualFrequency; //means there is no HuffData, empty node

        HuffData* getData(){return _value;};
        unsigned getFrequency();

        bool operator<(HuffNode &other){return getFrequency() < other.getFrequency();};
        bool operator>(HuffNode &other){return getFrequency() > other.getFrequency();};
        bool operator==(HuffNode &other){return getFrequency() == other.getFrequency();};

    protected:

    private:
};
#endif // BINARYNODE_H
