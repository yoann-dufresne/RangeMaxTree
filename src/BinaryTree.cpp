#include <cstring>
#include <cstdio>
#include <string>
#include <iostream>
#include "headers/BinaryTree.hpp"

using namespace std;

/**
 * Default constructor for a binary tree
 * @param left the left subtree (nullptr if empty)
 * @param right the right subtree (nullptr if empty)
 * @param node the key and value of the root
 */
BinaryTree::BinaryTree(BinaryTree *left, BinaryTree *right, NODE node) {
    this->left = left;
    this->right = right;
    this->node = node;
}

/**
 * Constructor for the BinaryTree class from a sorted array of leaves ( [start, end) )
 * @param sortedLeaves a sorted array of NODE representing leaves
 * @param start the start of the wanted range of teh array (included)
 * @param end the end of the wanted range of the array (excluded)
 * @return a build BinaryTree
 */
BinaryTree* BinaryTree::buildFromLeaves(NODE *sortedLeaves, int start, int end) {
    {
        if (end-start > 1)
        {
            int mid = (start+end)>>1;
            BinaryTree* leftTree = BinaryTree::buildFromLeaves(sortedLeaves, start, mid);
            BinaryTree* rightTree = BinaryTree::buildFromLeaves(sortedLeaves, mid, end);
            NODE currentNode = {(leftTree->node.key < rightTree->node.key)?rightTree->node.key:leftTree->node.key
                                , (leftTree->node.value > rightTree->node.value)?rightTree->node.value:leftTree->node.value};
            return new BinaryTree (leftTree, rightTree, currentNode);
        }
        else
        {
            return new BinaryTree(nullptr, nullptr, sortedLeaves[start]);
        }
    }
}


int BinaryTree::update(const int k, const int val) {
    if (left == nullptr) { // At a leaf
        if (k == node.key) {
            node.value = val;
            return 1;
        }
        return 0;
    }
    // At a node
    int found;
    if (left->node.key < k) { // Going right
        found = right->update(k, val);
    } else { // Going left
        found = left->update(k, val);
    }
    if (found) {
        node.value = (left->node.value < right->node.value)? left->node.value : right->node.value;
    }
    return found;
}

void BinaryTree::print(int indent) {
    for (int i = 0; i < indent; i++) cout << '\t';
    printf("Node(%d, %d\n", node.key, node.value);
    if (left != nullptr && right != nullptr) {
        left->print(indent + 1);
        right->print(indent + 1);
    }
    for (int i = 0; i < indent; i++) cout << '\t';
    cout << ")" << endl;
}




