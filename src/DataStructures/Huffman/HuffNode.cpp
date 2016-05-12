#include "DataStructures/Huffman/HuffNode.h"

HuffNode::HuffNode(HuffData* value) : _value(value), _leftChild(nullptr), _rightChild(nullptr)
{
    //ctor
}

HuffNode::~HuffNode()
{
    if(_leftChild != nullptr)
        delete _leftChild;
    if(_rightChild != nullptr)
        delete _rightChild;
    if(_value != nullptr)
        delete _value;
}

unsigned HuffNode::getFrequency()
{
    if(_value != nullptr){

            return _value->_frequency;
    }
    return _virtualFrequency;
}
