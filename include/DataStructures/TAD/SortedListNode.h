#ifndef SORTEDLISTNODE_H
#define SORTEDLISTNODE_H

template <class T>
class SortedListNode
{
    public:
        SortedListNode(T);
        virtual ~SortedListNode();
        T _content;
        SortedListNode<T>* _next;
    protected:

    private:
};

#endif // SORTEDLISTNODE_H
