#include "DataStructures/Huffman/HuffCodeTable.h"
#include <iostream>
using namespace std;

HuffCodeTable::HuffCodeTable():isSorted(false)
{
    //ctor
}

HuffCodeTable::~HuffCodeTable()
{
    //dtor
}

char HuffCodeTable::getSymbolForCode(std::string code)
{
    HuffData* data;
    for(size_t i=0; i < dataList.size(); i++){
        data = dataList.get(i);
        if(data->_huffCode == code){
            return data->_rawSymbol;
        }
    }
    return '\0';
}

std::string HuffCodeTable::getCodeForSymbol(char symbol)
{
    HuffData* data;
    for(size_t i=0; i < dataList.size(); i++){
        data = dataList.get(i);
        if(data->_rawSymbol == symbol){
            return data->_huffCode;
        }
    }
    return '\0';
}

void HuffCodeTable::setCodeForSymbol(std::string code, char symbol)
{
    HuffData* data;
    for(size_t i=0; i < dataList.size(); i++){
        data = dataList.get(i);
        if(data->_rawSymbol == symbol){
            data->_huffCode = code;
            return;
        }
    }
}

void HuffCodeTable::add(char toAdd)
{
    HuffData* data;
    for(size_t i=0; i < dataList.size(); i++){
        data = dataList.get(i);
        if(data->_rawSymbol == toAdd){
            data->_frequency++;
            return;
        }
    }
    if(isSorted){
        dataList.addWithSort(new HuffData(toAdd));
    }else{
        dataList.addWithoutSort(new HuffData(toAdd));
    }
}

HuffData* HuffCodeTable::pop()
{
    if(!isSorted){
        dataList.mergeSort();
        isSorted = true;
    }
    return dataList.remove(0);
}

HuffData* HuffCodeTable::get(size_t i)
{
    if(!isSorted){
        dataList.mergeSort();
        isSorted = true;
    }
    return dataList.get(i);
}
