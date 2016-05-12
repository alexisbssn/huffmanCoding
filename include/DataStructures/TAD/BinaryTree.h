#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <vector>
#include "BinaryNode.h"

template <typename T>
class BinaryTree
{
    public:
        BinaryTree();
        virtual ~BinaryTree();
        bool add(T);
        std::vector<T>* depthFirst();
        std::vector<T>* breadthFirst();
        BinaryNode<T>* findByValue(T);
        bool removeByValue(T);
    protected:

    private:
        BinaryNode<T>* rootNode;
        bool add(T, BinaryNode<T>*);
        std::vector<T>* depthFirst(BinaryNode<T>*, std::vector<T>*);
        std::vector<T>* breadthFirst(BinaryNode<T>*, std::vector<T>*);
};

#endif // BINARYTREE_H
