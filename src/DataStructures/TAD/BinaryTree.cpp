#include "DataStructures/TAD/BinaryTree.h"

using namespace std;

template <typename T>
BinaryTree<T>::BinaryTree()
{
    //ctor
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
    //dtor
}

template <typename T>
bool BinaryTree<T>::add(T item)
{
    return add(item, rootNode);
}

template <typename T>
bool BinaryTree<T>::add(T item, BinaryNode<T>* node)
{
    if(*(node->_value) == *item){
        return false;
    }else if(*(node->_value) > *item){
        if(node->_leftChild == nullptr){
            node ->_leftChild = new BinaryNode<T>(item);
            return true;
        }else{
            return add(item, node->_leftChild);
        }
    }else{
        if(node->_rightChild == nullptr){
            node ->_rightChild = new BinaryNode<T>(item);
            return true;
        }else{
            return add(item, node->_rightChild);
        }
    }
    //return add(item, );
}

template <typename T>
vector<T>* BinaryTree<T>::depthFirst()
{
    vector<T>* vec = new vector<T>;
    return depthFirst(rootNode, vec);
}

template <typename T>
vector<T>* BinaryTree<T>::depthFirst(BinaryNode<T>* node, vector<T>* vec)
{
    if(node->_leftChild != nullptr){
        depthFirst(node, vec);
    }
    vec->push_back(node->_value);
    if(node->_rightChild != nullptr){
        depthFirst(node, vec);
    }
    return vec;
}
template class BinaryTree<int*>;
