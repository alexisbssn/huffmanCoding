#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "DataStructures/TAD/HashNode.h"
#include "DataStructures/TAD/List.h"

template <class K, class V>
class HashTable
{
    public:
        HashTable(size_t size);
        virtual ~HashTable();
        V getValue(K code);
        bool insert(K key, V value);
        void remove(K);
        V operator[](K &key){return getValue(key);};

    protected:

    private:
        size_t _size;
        size_t hash(K);
        List<HashNode<K,V>*> _list;

};

#endif // CODETABLE_H
