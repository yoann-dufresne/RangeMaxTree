#include <iostream>

#include "BinaryTree.hpp"

using namespace std;

int main() {
    NODE node1 = {1, 10};
    NODE node2 = {2, 5};
    NODE node3 = {3, 9};
    NODE node4 = {4, 11};
    NODE node5 = {5, 3};
    NODE node6 = {6, 15};
    NODE node7 = {7, 1};
    NODE node8 = {8, 13};
    NODE node9 = {9, 7};
    NODE node10 = {10, 16};
    NODE node11 = {11, 13};
    NODE node12 = {12, 12};
    NODE node13 = {13, 6};
    NODE node14 = {14, 8};
    NODE node15 = {15, 2};
    NODE node16 = {16, 14};

    NODE array[] = {node1, node2, node3, node4, node5, node6, node7, node8, node9,
                    node10, node11, node12, node13, node14, node15, node16};

    BinaryTree* t = BinaryTree::buildFromLeaves(array, 0, 2);
    t->print();

    BinaryTree* t1 = BinaryTree::buildFromLeaves(array, 0, 16);
    cout << (*t == *t1) << endl;
    t1->print();
//
//
    delete t;
    delete t1;

    return 0;
}