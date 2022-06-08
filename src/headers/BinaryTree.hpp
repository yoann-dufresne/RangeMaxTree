#ifndef RANGEMAXTREE_BINARYTREE_HPP
#define RANGEMAXTREE_BINARYTREE_HPP

typedef struct NODE {
    int key;
    int value;
} NODE;

class BinaryTree {

public:
    BinaryTree* left = nullptr;
    BinaryTree* right = nullptr;


public:
    NODE node {0, 0};
    int update(int k , int val);
    void print(int indent = 0) ;
    static BinaryTree* buildFromLeaves(NODE sortedLeaves[], int start, int end);
    BinaryTree(BinaryTree* left, BinaryTree* right, NODE node);

    int RMaxQ(int l, int r);

};


#endif //RANGEMAXTREE_BINARYTREE_HPP
