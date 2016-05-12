#ifndef HASHNODE_H
#define HASHNODE_H

template <class K, class V>
class HashNode
{
    public:
        HashNode(K,V);
        virtual ~HashNode();
        HashNode<K,V>* getNext();
        void dropNext(){_next = nullptr;};
        bool append(HashNode<K,V>*);
        V getValue();
        const K getKey();
    protected:

    private:
        K _key;
        V _value;
        HashNode<K,V>* _next;
};

#endif // HASHNODE_H
