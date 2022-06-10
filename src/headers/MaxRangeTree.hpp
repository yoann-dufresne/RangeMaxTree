#ifndef RANGEMAXTREE_MAXRANGETREE_HPP
#define RANGEMAXTREE_MAXRANGETREE_HPP

typedef struct NODE {
    int key;
    int value;
} NODE;

class MaxRangeTree {

public:
    /// Attribute
    MaxRangeTree* left = nullptr;
    MaxRangeTree* right = nullptr;
    NODE node {0, 0};

    /// Constructor
    MaxRangeTree(MaxRangeTree* left, MaxRangeTree* right, NODE node);
    static MaxRangeTree* buildFromLeaves(NODE sortedLeaves[], int start, int end);

    ///Destructor
    ~MaxRangeTree();

    ///Method
    int update(int k , int val);
    int RMaxQ(int l, int r);
    void print(int indent = 0) ;
    int search(int k);

    ///Operator overloading
    bool operator==(const MaxRangeTree& toTest) const {
        if(left == nullptr && toTest.left == nullptr) {
            return node.value == toTest.node.value && node.key == toTest.node.key;
        } else {
            return node.value == toTest.node.value && node.key == toTest.node.key
                    && *left==*toTest.left
                    && *right==*toTest.right;
        }
    }

};


#endif //RANGEMAXTREE_MAXRANGETREE_HPP
