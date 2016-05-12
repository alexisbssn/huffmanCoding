#include "DataStructures/TAD/SortedListNode.h"
#include "DataStructures/Huffman/HuffData.h"
#include "DataStructures/Huffman/HuffNode.h"

template <class T>
inline SortedListNode<T>::SortedListNode(T content):_content(content), _next(nullptr)
{
}

template <class T>
inline SortedListNode<T>::~SortedListNode()
{
    //dtor
}
template class SortedListNode<HuffData*>;
template class SortedListNode<HuffNode*>;
