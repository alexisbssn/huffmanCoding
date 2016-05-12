#include "DataStructures/Huffman/HuffTree.h"
#include <stack>
#include <iostream>
using namespace std;

HuffTree::HuffTree()
{
    //ctor
}

HuffTree::~HuffTree()
{
    //dtor
}

bool HuffTree::add(HuffData* item)
{
    if(rootNode == nullptr){
        rootNode = new HuffNode(item);
        return true;
    }
    return add(item, rootNode);
}

bool HuffTree::add(HuffData* item, HuffNode* node)
{
    if(*(node->_value) == *item){
        return false;
    }else if(*(node->_value) > *item){
        if(node->_leftChild == nullptr){
            node ->_leftChild = new HuffNode(item);
            return true;
        }else{
            return add(item, node->_leftChild);
        }
    }else{
        if(node->_rightChild == nullptr){
            node ->_rightChild = new HuffNode(item);
            return true;
        }else{
            return add(item, node->_rightChild);
        }
    }
}

void HuffTree::depthFirst()
{
    return depthFirstAddCode(rootNode, "");
}

void HuffTree::depthFirstAddCode(HuffNode* node, std::string code)
{
    if(node->_leftChild != nullptr){
        depthFirstAddCode(node->_leftChild, code + "0");
    }
    if(node->_value != nullptr){
        node->_value->_huffCode = code;
    }
    if(node->_rightChild != nullptr){
        depthFirstAddCode(node->_rightChild, code + "1");
    }
}

std::string HuffTree::serialize(){
    // \uFFFF is going to be my separator.
    std::string str = "";
    return depthFirstSerialize(rootNode, str);
}

std::string HuffTree::depthFirstSerialize(HuffNode* node, std::string code)
{
    if(node->_value != nullptr){
        code += node->_value->_rawSymbol;
    }else{
        code += dummyNode;
    }
    if(node->_leftChild != nullptr){
        code = depthFirstSerialize(node->_leftChild, code);
    }
    if(node->_rightChild != nullptr){
        code = depthFirstSerialize(node->_rightChild, code);
    }
    code += separator;
    return code;
}

HuffTree::HuffTree(std::string serializedString)
{
    std::stack<HuffNode*> stack;
    for(char c : serializedString){
        if(stack.size() == 0){
            rootNode = new HuffNode(1);
            stack.push(rootNode);
        }else{
            if(c == separator){
                stack.pop();
            }else{
                HuffNode* node;
                if(c == dummyNode){
                    node = new HuffNode(1);
                }else{
                    node = new HuffNode(new HuffData(c));
                }
                if(stack.top()->_leftChild == nullptr){
                    stack.top()->_leftChild = node;
                }else{
                    stack.top()->_rightChild = node;
                }
                stack.push(node);
            }
        }
    }
}

