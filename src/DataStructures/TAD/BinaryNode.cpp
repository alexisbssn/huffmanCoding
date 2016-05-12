#include "DataStructures/TAD/BinaryNode.h"

template <typename T>
BinaryNode<T>::BinaryNode(T value) : _value(value)
{
    //ctor
}

template <typename T>
BinaryNode<T>::~BinaryNode()
{
    //dtor
}

template class BinaryNode<int*>;
