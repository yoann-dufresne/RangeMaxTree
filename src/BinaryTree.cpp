#include <cstdio>
#include <string>
#include <iostream>
#include "BinaryTree.hpp"

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
                                , (leftTree->node.value < rightTree->node.value)?rightTree->node.value:leftTree->node.value};
            return new BinaryTree (leftTree, rightTree, currentNode);
        }
        else
        {
            return new BinaryTree(nullptr, nullptr, sortedLeaves[start]);
        }
    }
}

/**
 * Update a leaf value in the BinaryTree
 * @param k the key of the leaf to update
 * @param val the new value
 * @return 0 if there is no leaf k else 1
 */
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
        node.value = (left->node.value > right->node.value)? left->node.value : right->node.value;
    }
    return found;
}

/**
 * Print a BinaryTree
 * @param indent the level of indentation to use
 */
void BinaryTree::print(int indent) {
    for (int i = 0; i < indent; i++) std::cout << '\t';
    printf("Node(%d, %d\n", node.key, node.value);
    if (left != nullptr && right != nullptr) {
        left->print(indent + 1);
        right->print(indent + 1);
    }
    for (int i = 0; i < indent; i++) std::cout << '\t';
    std::cout << ")" << std::endl;
}

/**
 * RangeMaxQuery
 * @param l the left of the range (included)
 * @param r the right of the range (included)
 * @return the max value in the specified range
 */
int BinaryTree::RMaxQ(const int l, const int r) {
    /// Particular cases
    if (l == r) return search(l);
    if (l > r) { // Invalid search
        return -1;
    }

    /// Find the last node v on the same path
    BinaryTree* current = this;
    while (true) {
        if (current->left == nullptr) {
            if (current->node.key > r || current->node.key < l) {
                return -1; // Out of key range
            } else {
                return current->node.value;
            }
        }
        int nextLeftKey = current->left->node.key;
        if (nextLeftKey < l && nextLeftKey < r) {
            current = current->right;
            continue;
        }
        if (nextLeftKey >= l && nextLeftKey >= r) {
            current = current->left;
            continue;
        }
        break;
    }
    /// Find the max at the left of v
    int maxLeft = -1;
    BinaryTree* currentLeft = current->left;
    while(currentLeft->left != nullptr) { // At a node
        if (currentLeft->left->node.key < l) { // Going right
            currentLeft = currentLeft->right;
        } else { // Going left
            maxLeft = (maxLeft < currentLeft->right->node.value)? currentLeft->right->node.value : maxLeft;
            currentLeft = currentLeft->left;
        }
    }
    if (currentLeft->node.key >= l) maxLeft = (maxLeft < currentLeft->node.value)? currentLeft->node.value : maxLeft;

    /// Find the max at the right of v
    int maxRight = -1;
    BinaryTree* currentRight = current->right;
    while(currentRight->left != nullptr) { // At a node
        if (currentRight->left->node.key < r) { // Going right
            maxRight = (maxRight < currentRight->left->node.value)? currentRight->left->node.value : maxRight;
            currentRight = currentRight->right;
        } else { // Going left
            currentRight = currentRight->left;
        }
    }
    if (currentRight->node.key <= r) maxRight = (maxRight < currentRight->node.value)? currentRight->node.value : maxRight;

    return (maxRight < maxLeft)? maxLeft : maxRight;
}

/**
 * Destructor for a BinaryTree
 */
BinaryTree::~BinaryTree() {
    if (left == nullptr) return;
    delete left;
    delete right;
}

/**
 * Search the wanted leaf's value
 * @param k the key of the wanted leaf
 * @return -1 if no such leaf found else the value of the found leaf
 */
int BinaryTree::search(int k) {
    BinaryTree* current = this;
    while (current->left != nullptr) {
        if (current->left->node.key < k) { //Going right
            current = current->right;
        } else { //Going left
            current = current->left;
        }
    }
    if (current->node.key == k) {
        return current->node.value;
    } else {
        return -1;
    }
}






