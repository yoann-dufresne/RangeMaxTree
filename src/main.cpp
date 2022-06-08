#include <iostream>

#include "headers/BinaryTree.hpp"

using namespace std;

int main() {
    NODE node1 = {1, 4};
    NODE node2 = {2, 3};
    NODE node3 = {3, 2};
    NODE node4 = {4, 1};

    NODE array[] = {node1, node2, node3, node4};

    BinaryTree* t = BinaryTree::buildFromLeaves(array, 0, 4);
    //t.print();
    t->print();

    return 0;
}