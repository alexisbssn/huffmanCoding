#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <vector>
#include <string>
#include "HuffNode.h"
#include "HuffData.h"

class HuffTree
{
    public:
        HuffTree();
        HuffTree(HuffNode* root):rootNode(root){};
        HuffTree(std::string serializedString);
        virtual ~HuffTree();
        bool add(HuffData*); //useless with current implementation
        void depthFirst();
        std::string serialize();
        HuffNode* getRoot(){return rootNode;};
        //std::vector<HuffData>* breadthFirst();
        //HuffNode* findByValue(HuffData*);
        //bool removeByValue(HuffData*);
    protected:

    private:
        static const unsigned char separator = 1;
        static const unsigned char dummyNode = 2;
        HuffNode* rootNode;
        bool add(HuffData*, HuffNode*);
        void depthFirstAddCode(HuffNode*, std::string);
        std::string depthFirstSerialize(HuffNode*, std::string);
        //std::vector<HuffData*>* breadthFirst(HuffNode<HuffData*>*, std::vector<HuffData*>*);
};

#endif // BINARYTREE_H
