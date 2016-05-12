#ifndef BINARYNODE_H
#define BINARYNODE_H


template <typename T>
class BinaryNode
{
    public:
        BinaryNode(T);
        virtual ~BinaryNode();

        T _value;
        BinaryNode<T>* _leftChild;
        BinaryNode<T>* _rightChild;

    protected:

    private:
};
#endif // BINARYNODE_H
