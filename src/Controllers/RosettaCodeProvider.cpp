#include "Controllers/RosettaCodeProvider.h"
#include <bitset>
#include <iostream>

using namespace std;
RosettaCodeProvider::RosettaCodeProvider() :
    _huffCodeTable(nullptr),
    _huffTree(nullptr)
{
    //ctor
}

RosettaCodeProvider::~RosettaCodeProvider()
{
    //dtor
}

void RosettaCodeProvider::run(char* str)
{
    cout << "run started" << endl;
    buildHuffTable(str);
    cout << "table built" << endl;
    buildHuffTree();
    cout << "tree built" << endl;
    fillTableWithHuffCodes();
    cout << "table filled" << endl;
}

/*HashTable* RosettaCodeProvider::getHashTable()
{
    return _huffCodeTable;
}*/

void RosettaCodeProvider::buildHuffTable(char* str)
{
    if(_huffCodeTable != nullptr){
        delete _huffCodeTable;
    }
    _huffCodeTable = new HuffCodeTable();
    for(char* it = str; *it; ++it) {
        //increments count if same char
        _huffCodeTable->add(*it);
    }
}

void RosettaCodeProvider::buildHuffTree()
{
    //build Node list from HuffCodeTable, no need to sort (already done on get call)
    SortedList<HuffNode*> nodeList;
    int i = 0;
    HuffData* iterate = _huffCodeTable->get(i);
    while(iterate != nullptr){
        ++i;
        nodeList.addWithoutSort(new HuffNode(iterate));
        iterate = _huffCodeTable->get(i);
    }
    //merge nodes together
    while(nodeList.size() >= 2){
        HuffNode* one = nodeList.remove(0);
        HuffNode* two = nodeList.remove(0);
        unsigned sum = one->getFrequency() + two->getFrequency();
        HuffNode* three = new HuffNode(sum);
        if(*one < *two){
            three->_leftChild = one;
            three->_rightChild = two;
        }else{
            three->_leftChild = two;
            three->_rightChild = one;
        }
        nodeList.addWithSort(three);
    }
    if(nodeList.size() == 0){
        //something went wrong
        //nothing in codeTable to start with?
        return;
    }
    if(nodeList.size() == 1){
        _huffTree = new HuffTree(nodeList.remove(0));
    }
}

void RosettaCodeProvider::fillTableWithHuffCodes()
{
    _huffTree->depthFirst();
}

string RosettaCodeProvider::huffTableToDebugString(){
    string s = "";
    int i = 0;
    HuffData* iterate = _huffCodeTable->get(i);
    while(iterate != nullptr){
        ++i;
        s = s + iterate->_rawSymbol + " : " + iterate->_huffCode + "\n";
        iterate = _huffCodeTable->get(i);
    }
    return s;
}

string RosettaCodeProvider::getDataFromBits(string input)
{
    string output = "";
    HuffNode* node = _huffTree->getRoot();
    for(char c : input){
        if(node->_value != nullptr){
            output += node->_value->_rawSymbol; //yuck, I know
            node = _huffTree->getRoot();
        }
        if(c == '0'){
            node = node->_leftChild;
        }else if(c == '1'){
            node = node->_rightChild;
        }
    }
    if(node->_value != nullptr){
        output += node->_value->_rawSymbol;
        node = _huffTree->getRoot();
    }
    return output;
}
