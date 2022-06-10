#include <iostream>

#include "RangeMaxTree.hpp"

int main() {

    /// A few nodes to make an example
    NODE leaf8_0 = {5, 29};
    NODE leaf8_1 = {8, 36};
    NODE leaf8_2 = {11, 21};
    NODE leaf8_3 = {14, 24};
    NODE leaf8_4 = {22, 11};
    NODE leaf8_5 = {35, 15};
    NODE leaf8_6 = {42, 11};
    NODE leaf8_7 = {51, 4};

    /// Sort your nodes by key with your favorite sort
    NODE sortedLeaves8[] = {leaf8_0, leaf8_1, leaf8_2, leaf8_3,
                            leaf8_4, leaf8_5, leaf8_6, leaf8_7};

    /// Build a MaxRangeTree from a sorted list of leaves with a static constructor
    MaxRangeTree* firstExample = MaxRangeTree::buildFromLeaves(sortedLeaves8, 0, 8); // end is excluded

    firstExample->print(); // To have a look on your tree;
    std::cout << "MaxRangeQuery from 14 to 34 = " << firstExample->RMaxQ(14, 34) << std::endl; // To query the max value between the key 13 and 34 (both included)
    std::cout << "Update leaf of key 8 with 23 (1 if found leaf of key 8, else -1) = "
        << firstExample->update(8, 23) << std::endl;
    firstExample->print(); // Let's look at the update

    MaxRangeTree* toCompare = MaxRangeTree::buildFromLeaves(sortedLeaves8, 2, 6);
    std::cout << "We can compare them : " << (*toCompare == *firstExample) << std::endl;

    /// Don't forget to delete
    delete firstExample;
    delete toCompare;

    return EXIT_SUCCESS;
}