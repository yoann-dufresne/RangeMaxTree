#include <iostream>
#include <fstream>
#include <vector>

#include "BinaryTree.hpp"
#include "lest.hpp"


using namespace std;
using namespace lest;

const test building[] = {
        /// Test buildFromLeaves
        CASE("2 leaves : ") {
            cout << "building : " << endl;
            NODE leaf2_0 = {1, 6};
            NODE leaf2_1 = {2, 5};
            NODE sortedLeaves2[] = {leaf2_0, leaf2_1};

            BinaryTree* leftTree = new BinaryTree(nullptr, nullptr, leaf2_0);
            BinaryTree* rightTree = new BinaryTree(nullptr, nullptr, leaf2_1);
            BinaryTree* ref2 = new BinaryTree(leftTree, rightTree, {2, 6});
            ref2->print(1);

            BinaryTree* tree2 = BinaryTree::buildFromLeaves(sortedLeaves2, 0, 2);

            EXPECT(*ref2 == *tree2);

            delete tree2;
            delete ref2;
        },
            CASE("4 leaves : ") {
            cout << "building : " << endl;
            NODE leaf4_0 = {1, 18};
            NODE leaf4_1 = {4, 5};
            NODE leaf4_2 = {7, 13};
            NODE leaf4_3 = {10, 11};
            NODE sortedLeaves4[] = {leaf4_0, leaf4_1, leaf4_2, leaf4_3};

            BinaryTree* ll = new BinaryTree(nullptr, nullptr, leaf4_0);
            BinaryTree* lr = new BinaryTree(nullptr, nullptr, leaf4_1);
            BinaryTree* l = new BinaryTree(ll, lr, {4, 18});
            BinaryTree* rl = new BinaryTree(nullptr, nullptr, leaf4_2);
            BinaryTree* rr = new BinaryTree(nullptr, nullptr, leaf4_3);
            BinaryTree* r = new BinaryTree(rl, rr, {10, 13});
            BinaryTree* ref4 = new BinaryTree(l, r, {10, 18});
            ref4->print(1);

            BinaryTree* tree4 = BinaryTree::buildFromLeaves(sortedLeaves4, 0, 4);

            EXPECT(*ref4 == *tree4);
            delete tree4;
            delete ref4;
        },
            CASE("8 leaves : ") {
            cout << "building : " << endl;
            NODE leaf8_0 = {5, 29};
            NODE leaf8_1 = {8, 5};
            NODE leaf8_2 = {11, 21};
            NODE leaf8_3 = {14, 24};
            NODE leaf8_4 = {22, 11};
            NODE leaf8_5 = {35, 15};
            NODE leaf8_6 = {42, 11};
            NODE leaf8_7 = {51, 36};
            NODE sortedLeaves8[] = {leaf8_0, leaf8_1, leaf8_2, leaf8_3,
                                    leaf8_4, leaf8_5, leaf8_6, leaf8_7};

            BinaryTree* lll = new BinaryTree(nullptr, nullptr, leaf8_0);
            BinaryTree* llr = new BinaryTree(nullptr, nullptr, leaf8_1);
            BinaryTree* ll = new BinaryTree(lll, llr, {8, 29});
            BinaryTree* lrl = new BinaryTree(nullptr, nullptr, leaf8_2);
            BinaryTree* lrr = new BinaryTree(nullptr, nullptr, leaf8_3);
            BinaryTree* lr = new BinaryTree(lrl, lrr, {14, 24});
            BinaryTree* l = new BinaryTree(ll, lr, {14, 29});
            BinaryTree* rll = new BinaryTree(nullptr, nullptr, leaf8_4);
            BinaryTree* rlr = new BinaryTree(nullptr, nullptr, leaf8_5);
            BinaryTree* rl = new BinaryTree(rll, rlr, {35, 15});
            BinaryTree* rrl = new BinaryTree(nullptr, nullptr, leaf8_6);
            BinaryTree* rrr = new BinaryTree(nullptr, nullptr, leaf8_7);
            BinaryTree* rr = new BinaryTree(rrl, rrr, {51, 36});
            BinaryTree* r = new BinaryTree(rl, rr, {51, 36});
            BinaryTree* ref8 = new BinaryTree(l, r, {51, 36});
            ref8->print(1);

            BinaryTree* tree8 = BinaryTree::buildFromLeaves(sortedLeaves8, 0, 8);

            EXPECT(*ref8 == *tree8);
            delete ref8;
            delete tree8;
        },

        CASE("16 leaves : ") {
            cout << "building : " << endl;
            NODE leaf16_0 = {5, 72};
            NODE leaf16_1 = {9, 40};
            NODE leaf16_2 = {10, 30};
            NODE leaf16_3 = {11, 28};
            NODE leaf16_4 = {14, 97};
            NODE leaf16_5 = {17, 34};
            NODE leaf16_6 = {18, 27};
            NODE leaf16_7 = {24, 85};
            NODE leaf16_8 = {26, 95};
            NODE leaf16_9 = {30, 47};
            NODE leaf16_10 = {35, 77};
            NODE leaf16_11 = {37, 19};
            NODE leaf16_12 = {39, 77};
            NODE leaf16_13 = {42, 39};
            NODE leaf16_14 = {59, 10};
            NODE leaf16_15 = {63, 91};

            NODE sortedLeave16[] = {leaf16_0, leaf16_1, leaf16_2, leaf16_3, leaf16_4,leaf16_5,
                                    leaf16_6,leaf16_7, leaf16_8, leaf16_9,leaf16_10,
                                    leaf16_11, leaf16_12,leaf16_13,leaf16_14, leaf16_15};

            BinaryTree* llll = new BinaryTree(nullptr, nullptr, leaf16_0);
            BinaryTree* lllr = new BinaryTree(nullptr, nullptr, leaf16_1);
            BinaryTree* lll = new BinaryTree(llll, lllr, {9, 72});
            BinaryTree* llrl = new BinaryTree(nullptr, nullptr, leaf16_2);
            BinaryTree* llrr = new BinaryTree(nullptr, nullptr, leaf16_3);
            BinaryTree* llr = new BinaryTree(llrl, llrr, {11, 30});
            BinaryTree* ll = new BinaryTree(lll, llr, {11, 72});
            BinaryTree* lrll = new BinaryTree(nullptr, nullptr, leaf16_4);
            BinaryTree* lrlr = new BinaryTree(nullptr, nullptr, leaf16_5);
            BinaryTree* lrl = new BinaryTree(lrll, lrlr, {17, 97});
            BinaryTree* lrrl = new BinaryTree(nullptr, nullptr, leaf16_6);
            BinaryTree* lrrr = new BinaryTree(nullptr, nullptr, leaf16_7);
            BinaryTree* lrr = new BinaryTree(lrrl, lrrr, {24, 85});
            BinaryTree* lr = new BinaryTree(lrl, lrr, {24, 97});
            BinaryTree* l = new BinaryTree(ll, lr, {24, 97});
            BinaryTree* rlll = new BinaryTree(nullptr, nullptr, leaf16_8);
            BinaryTree* rllr = new BinaryTree(nullptr, nullptr, leaf16_9);
            BinaryTree* rll = new BinaryTree(rlll, rllr, {30, 95});
            BinaryTree* rlrl = new BinaryTree(nullptr, nullptr, leaf16_10);
            BinaryTree* rlrr = new BinaryTree(nullptr, nullptr, leaf16_11);
            BinaryTree* rlr = new BinaryTree(rlrl, rlrr, {37, 77});
            BinaryTree* rl = new BinaryTree(rll, rlr, {37, 95});
            BinaryTree* rrll = new BinaryTree(nullptr, nullptr, leaf16_12);
            BinaryTree* rrlr = new BinaryTree(nullptr, nullptr, leaf16_13);
            BinaryTree* rrl = new BinaryTree(rrll, rrlr, {42, 77});
            BinaryTree* rrrl = new BinaryTree(nullptr, nullptr, leaf16_14);
            BinaryTree* rrrr = new BinaryTree(nullptr, nullptr, leaf16_15);
            BinaryTree* rrr = new BinaryTree(rrrl, rrrr, {63, 91});
            BinaryTree* rr = new BinaryTree(rrl, rrr, {63, 91});
            BinaryTree* r = new BinaryTree(rl, rr, {63, 95});
            BinaryTree* ref16 = new BinaryTree(l, r, {63, 97});
            ref16->print(1);

            BinaryTree* tree16 = BinaryTree::buildFromLeaves(sortedLeave16, 0, 16);
            EXPECT(*ref16 == *tree16);
            delete tree16;
            delete ref16;

        }
};

const test update[] {
    CASE("2 leaves found : ") {
            NODE leaf2_0 = {1, 6};
            NODE leaf2_1 = {2, 5};
            NODE leaf2_1_mod = {2, 10};
            NODE sortedLeaves2[] = {leaf2_0, leaf2_1};
            NODE sortedLeaves2Mod[] = {leaf2_0, leaf2_1_mod};
            BinaryTree* ref2 = BinaryTree::buildFromLeaves(sortedLeaves2Mod, 0, 2);
            BinaryTree* tree2 = BinaryTree::buildFromLeaves(sortedLeaves2, 0, 2);
            tree2->update(2, 10);
            EXPECT(*ref2 == *tree2);
            delete ref2;
            delete tree2;
        },

        CASE("2 leaves not found : ") {
            NODE leaf2_0 = {1, 6};
            NODE leaf2_1 = {2, 5};
            NODE sortedLeaves2[] = {leaf2_0, leaf2_1};
            BinaryTree* tree2 = BinaryTree::buildFromLeaves(sortedLeaves2, 0, 2);
            tree2->update(5, 10);
                    EXPECT(*tree2 == *BinaryTree::buildFromLeaves(sortedLeaves2, 0, 2));
            delete tree2;
    },

        CASE("16 leaves found : ") {
            NODE leaf16_0 = {5, 72};
            NODE leaf16_1 = {9, 40};
            NODE leaf16_2 = {10, 30};
            NODE leaf16_3 = {11, 28};
            NODE leaf16_4 = {14, 97};
            NODE leaf16_5 = {17, 34};
            NODE leaf16_6 = {18, 27};
            NODE leaf16_7 = {24, 85};
            NODE leaf16_8 = {26, 95};
            NODE leaf16_9 = {30, 47};
            NODE leaf16_10 = {35, 77};
            NODE leaf16_11 = {37, 19};
            NODE leaf16_12 = {39, 77};
            NODE leaf16_13 = {42, 39};
            NODE leaf16_14 = {59, 10};
            NODE leaf16_15 = {63, 91};
            NODE leaf16_6_mod = {18, 99};

            NODE sortedLeaves16[] = {leaf16_0, leaf16_1, leaf16_2, leaf16_3, leaf16_4,leaf16_5,
                                    leaf16_6,leaf16_7, leaf16_8, leaf16_9,leaf16_10,
                                    leaf16_11, leaf16_12,leaf16_13,leaf16_14, leaf16_15};
            NODE sortedLeaves16Mod[] = {leaf16_0, leaf16_1, leaf16_2, leaf16_3, leaf16_4,leaf16_5,
                                    leaf16_6_mod,leaf16_7, leaf16_8, leaf16_9,leaf16_10,
                                    leaf16_11, leaf16_12,leaf16_13,leaf16_14, leaf16_15};

            BinaryTree* ref16 = BinaryTree::buildFromLeaves(sortedLeaves16Mod, 0, 2);
            BinaryTree* tree16 = BinaryTree::buildFromLeaves(sortedLeaves16, 0, 2);
            tree16->update(18, 99);
                    EXPECT(*ref16 == *tree16);
            delete ref16;
            delete tree16;
    },
        CASE("16 leaves not found : ") {
            NODE leaf16_0 = {5, 72};
            NODE leaf16_1 = {9, 40};
            NODE leaf16_2 = {10, 30};
            NODE leaf16_3 = {11, 28};
            NODE leaf16_4 = {14, 97};
            NODE leaf16_5 = {17, 34};
            NODE leaf16_6 = {18, 27};
            NODE leaf16_7 = {24, 85};
            NODE leaf16_8 = {26, 95};
            NODE leaf16_9 = {30, 47};
            NODE leaf16_10 = {35, 77};
            NODE leaf16_11 = {37, 19};
            NODE leaf16_12 = {39, 77};
            NODE leaf16_13 = {42, 39};
            NODE leaf16_14 = {59, 10};
            NODE leaf16_15 = {63, 91};
            NODE sortedLeaves16[] = {leaf16_0, leaf16_1, leaf16_2, leaf16_3, leaf16_4,leaf16_5,
                                     leaf16_6,leaf16_7, leaf16_8, leaf16_9,leaf16_10,
                                     leaf16_11, leaf16_12,leaf16_13,leaf16_14, leaf16_15};
            BinaryTree* tree16 = BinaryTree::buildFromLeaves(sortedLeaves16, 0, 16);
            tree16->update(31, 100);
                    EXPECT(*tree16 == *BinaryTree::buildFromLeaves(sortedLeaves16, 0, 16));
            delete tree16;
    }
};

const test rangeMaxQuery[] {
    CASE("16 leaves : ") {
            NODE leaf16_0 = {5, 72};
            NODE leaf16_1 = {9, 40};
            NODE leaf16_2 = {10, 30};
            NODE leaf16_3 = {11, 28};
            NODE leaf16_4 = {14, 97};
            NODE leaf16_5 = {17, 34};
            NODE leaf16_6 = {18, 27};
            NODE leaf16_7 = {24, 85};
            NODE leaf16_8 = {26, 95};
            NODE leaf16_9 = {30, 47};
            NODE leaf16_10 = {35, 77};
            NODE leaf16_11 = {37, 19};
            NODE leaf16_12 = {39, 77};
            NODE leaf16_13 = {42, 39};
            NODE leaf16_14 = {59, 10};
            NODE leaf16_15 = {63, 91};
            NODE sortedLeaves16[] = {leaf16_0, leaf16_1, leaf16_2, leaf16_3, leaf16_4,leaf16_5,
                                     leaf16_6,leaf16_7, leaf16_8, leaf16_9,leaf16_10,
                                     leaf16_11, leaf16_12,leaf16_13,leaf16_14, leaf16_15};
            BinaryTree* tree16 = BinaryTree::buildFromLeaves(sortedLeaves16, 0, 16);
            EXPECT(tree16->RMaxQ(0, 15) == 97);
            EXPECT(tree16->RMaxQ(0, 4) == -1);
            EXPECT(tree16->RMaxQ(-10, 5) == 72);
            EXPECT(tree16->RMaxQ(-20, -10) == -1);
            EXPECT(tree16->RMaxQ(63, 100) == 91);
            EXPECT(tree16->RMaxQ(100, 200) == -1);
            EXPECT(tree16->RMaxQ(4, 6) == 72);
            EXPECT(tree16->RMaxQ(10, 11) == 30);
            EXPECT(tree16->RMaxQ(50, 100) == 91);
            EXPECT(tree16->RMaxQ(-50, 20) == 97);
            EXPECT(tree16->RMaxQ(37, 63) == 91);
            EXPECT(tree16->RMaxQ(0, 100) == 97);
            EXPECT(tree16->RMaxQ(42, 42) == 39);
            EXPECT(tree16->RMaxQ(15, 25) == 85);
            EXPECT(tree16->RMaxQ(15, 26) == 95);
            delete tree16;
    }
};

int main() {
    int failures(0);
    cout << "*** First test : buildFromLeaves ***" << endl;
    if((failures = run(building))){  //run building test
        return failures;
    }
    cout << "*** Passed ***" << endl;
    cout << "*** Second test : update ***" << endl;
    if ((failures = run(update))) { //run update test
        return failures;
    }
    cout << "*** Passed ***" << endl;
    cout << "*** Third test : RMaxQ ***" << endl;
    if ((failures = run(rangeMaxQuery))) { //run rangeMaxQuery test
        return failures;
    }
    cout << "*** Passed ***" << endl;
    return EXIT_SUCCESS;
}
