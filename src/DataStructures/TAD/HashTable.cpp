#include "DataStructures/TAD/HashTable.h"
#include <string>

template <class K, class V>
inline HashTable<K,V>::HashTable(size_t size):_size(size), _list(size)
{
}

template <class K, class V>
HashTable<K,V>::~HashTable()
{
    //dtor
}

template <class K, class V>
V HashTable<K,V>::getValue(K code)
{
    size_t index = hash(code);
    HashNode<K,V>* node = _list[index];
    while(node->getKey() != code){
        node = node->getNext();
        if(node == nullptr){
            return nullptr;
        }
    }
    return node->getValue();
}

template <class K, class V>
bool HashTable<K,V>::insert(K key, V value)
{
    size_t index = hash(key);
    HashNode<K,V>* node = new HashNode<K,V>(key,value);
    if(_list[index] == nullptr){
        _list[index] = node;
        return true;
    }else{
        return _list[index]->append(node);
    }
}

template <class K, class V>
void HashTable<K,V>::remove(K code)
{
    size_t index = hash(code);
    HashNode<K,V>* previous;
    HashNode<K,V>* node = _list[index];
    while(node->getKey() != code){
        previous = node;
        node = node->getNext();
        if(node == nullptr){
            return;
        }
    }
    previous->dropNext();
    previous->append(node->getNext());
}

template <class K, class V>
size_t HashTable<K,V>::hash(K key)
{
    return (key % _size);
}

template class HashTable<int, std::string>;
