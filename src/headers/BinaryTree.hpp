#ifndef RANGEMAXTREE_BINARYTREE_HPP
#define RANGEMAXTREE_BINARYTREE_HPP

typedef struct NODE {
    int key;
    int value;
} NODE;

class BinaryTree {

public:
    /// Attribute
    BinaryTree* left = nullptr;
    BinaryTree* right = nullptr;
    NODE node {0, 0};

    /// Constructor
    BinaryTree(BinaryTree* left, BinaryTree* right, NODE node);
    static BinaryTree* buildFromLeaves(NODE sortedLeaves[], int start, int end);

    ///Destructor
    ~BinaryTree();

    ///Method
    int update(int k , int val);
    int RMaxQ(int l, int r);
    void print(int indent = 0) ;
    int search(int k);



};


#endif //RANGEMAXTREE_BINARYTREE_HPP
