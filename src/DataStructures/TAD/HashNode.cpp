#include "DataStructures/TAD/HashNode.h"
#include <string>

template <class K, class V>
inline HashNode<K,V>::HashNode(K key, V value):_key(key), _value(value), _next(nullptr)
{
}

template <class K, class V>
HashNode<K,V>::~HashNode()
{
    //dtor
}
template <class K, class V>
HashNode<K,V>* HashNode<K,V>::getNext()
{
    return _next;
}

template <class K, class V>
bool HashNode<K,V>::append(HashNode<K, V>* node)
{
    if(_key == node->getKey()){
        return false;
    }
    if(_next == nullptr){
        _next = node;
    }else{
        _next->append(node);
    }
    return true;
}

template <class K, class V>
V HashNode<K,V>::getValue()
{
    return _value;
}

template <class K, class V>
const K HashNode<K,V>::getKey()
{
    return _key;
}

template class HashNode<int, std::string>;
