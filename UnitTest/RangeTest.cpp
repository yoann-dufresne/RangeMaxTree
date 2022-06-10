#include <iostream>
#include <fstream>
#include <vector>

#include "MaxRangeTree.hpp"
#include "lest.hpp"


using namespace std;
using namespace lest;

const test building[] = {
        /// Test buildFromLeaves
        CASE({"2 leaves : ") {
            cout << "building : " << endl;
            NODE leaf2_0 = {1, 6};
            NODE leaf2_1 = {2, 5};
            NODE sortedLeaves2[] = {leaf2_0, leaf2_1};

            MaxRangeTree* leftTree = new MaxRangeTree(nullptr, nullptr, leaf2_0);
            MaxRangeTree* rightTree = new MaxRangeTree(nullptr, nullptr, leaf2_1);
            MaxRangeTree* ref2 = new MaxRangeTree(leftTree, rightTree, {2, 6});
            ref2->print(1);

            MaxRangeTree* tree2 = MaxRangeTree::buildFromLeaves(sortedLeaves2, 0, 2);

            EXPECT(*ref2 == *tree2);

            delete tree2;
            delete ref2;
        }},
            CASE({"4 leaves : ") {
            cout << "building : " << endl;
            NODE leaf4_0 = {1, 18};
            NODE leaf4_1 = {4, 5};
            NODE leaf4_2 = {7, 13};
            NODE leaf4_3 = {10, 11};
            NODE sortedLeaves4[] = {leaf4_0, leaf4_1, leaf4_2, leaf4_3};

            MaxRangeTree* ll = new MaxRangeTree(nullptr, nullptr, leaf4_0);
            MaxRangeTree* lr = new MaxRangeTree(nullptr, nullptr, leaf4_1);
            MaxRangeTree* l = new MaxRangeTree(ll, lr, {4, 18});
            MaxRangeTree* rl = new MaxRangeTree(nullptr, nullptr, leaf4_2);
            MaxRangeTree* rr = new MaxRangeTree(nullptr, nullptr, leaf4_3);
            MaxRangeTree* r = new MaxRangeTree(rl, rr, {10, 13});
            MaxRangeTree* ref4 = new MaxRangeTree(l, r, {10, 18});
            ref4->print(1);

            MaxRangeTree* tree4 = MaxRangeTree::buildFromLeaves(sortedLeaves4, 0, 4);

            EXPECT(*ref4 == *tree4);
            delete tree4;
            delete ref4;
        }},
            CASE({"8 leaves : ") {
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

            MaxRangeTree* lll = new MaxRangeTree(nullptr, nullptr, leaf8_0);
            MaxRangeTree* llr = new MaxRangeTree(nullptr, nullptr, leaf8_1);
            MaxRangeTree* ll = new MaxRangeTree(lll, llr, {8, 29});
            MaxRangeTree* lrl = new MaxRangeTree(nullptr, nullptr, leaf8_2);
            MaxRangeTree* lrr = new MaxRangeTree(nullptr, nullptr, leaf8_3);
            MaxRangeTree* lr = new MaxRangeTree(lrl, lrr, {14, 24});
            MaxRangeTree* l = new MaxRangeTree(ll, lr, {14, 29});
            MaxRangeTree* rll = new MaxRangeTree(nullptr, nullptr, leaf8_4);
            MaxRangeTree* rlr = new MaxRangeTree(nullptr, nullptr, leaf8_5);
            MaxRangeTree* rl = new MaxRangeTree(rll, rlr, {35, 15});
            MaxRangeTree* rrl = new MaxRangeTree(nullptr, nullptr, leaf8_6);
            MaxRangeTree* rrr = new MaxRangeTree(nullptr, nullptr, leaf8_7);
            MaxRangeTree* rr = new MaxRangeTree(rrl, rrr, {51, 36});
            MaxRangeTree* r = new MaxRangeTree(rl, rr, {51, 36});
            MaxRangeTree* ref8 = new MaxRangeTree(l, r, {51, 36});
            ref8->print(1);

            MaxRangeTree* tree8 = MaxRangeTree::buildFromLeaves(sortedLeaves8, 0, 8);

            EXPECT(*ref8 == *tree8);
            delete ref8;
            delete tree8;
        }},

        CASE({"16 leaves : ") {
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

            MaxRangeTree* llll = new MaxRangeTree(nullptr, nullptr, leaf16_0);
            MaxRangeTree* lllr = new MaxRangeTree(nullptr, nullptr, leaf16_1);
            MaxRangeTree* lll = new MaxRangeTree(llll, lllr, {9, 72});
            MaxRangeTree* llrl = new MaxRangeTree(nullptr, nullptr, leaf16_2);
            MaxRangeTree* llrr = new MaxRangeTree(nullptr, nullptr, leaf16_3);
            MaxRangeTree* llr = new MaxRangeTree(llrl, llrr, {11, 30});
            MaxRangeTree* ll = new MaxRangeTree(lll, llr, {11, 72});
            MaxRangeTree* lrll = new MaxRangeTree(nullptr, nullptr, leaf16_4);
            MaxRangeTree* lrlr = new MaxRangeTree(nullptr, nullptr, leaf16_5);
            MaxRangeTree* lrl = new MaxRangeTree(lrll, lrlr, {17, 97});
            MaxRangeTree* lrrl = new MaxRangeTree(nullptr, nullptr, leaf16_6);
            MaxRangeTree* lrrr = new MaxRangeTree(nullptr, nullptr, leaf16_7);
            MaxRangeTree* lrr = new MaxRangeTree(lrrl, lrrr, {24, 85});
            MaxRangeTree* lr = new MaxRangeTree(lrl, lrr, {24, 97});
            MaxRangeTree* l = new MaxRangeTree(ll, lr, {24, 97});
            MaxRangeTree* rlll = new MaxRangeTree(nullptr, nullptr, leaf16_8);
            MaxRangeTree* rllr = new MaxRangeTree(nullptr, nullptr, leaf16_9);
            MaxRangeTree* rll = new MaxRangeTree(rlll, rllr, {30, 95});
            MaxRangeTree* rlrl = new MaxRangeTree(nullptr, nullptr, leaf16_10);
            MaxRangeTree* rlrr = new MaxRangeTree(nullptr, nullptr, leaf16_11);
            MaxRangeTree* rlr = new MaxRangeTree(rlrl, rlrr, {37, 77});
            MaxRangeTree* rl = new MaxRangeTree(rll, rlr, {37, 95});
            MaxRangeTree* rrll = new MaxRangeTree(nullptr, nullptr, leaf16_12);
            MaxRangeTree* rrlr = new MaxRangeTree(nullptr, nullptr, leaf16_13);
            MaxRangeTree* rrl = new MaxRangeTree(rrll, rrlr, {42, 77});
            MaxRangeTree* rrrl = new MaxRangeTree(nullptr, nullptr, leaf16_14);
            MaxRangeTree* rrrr = new MaxRangeTree(nullptr, nullptr, leaf16_15);
            MaxRangeTree* rrr = new MaxRangeTree(rrrl, rrrr, {63, 91});
            MaxRangeTree* rr = new MaxRangeTree(rrl, rrr, {63, 91});
            MaxRangeTree* r = new MaxRangeTree(rl, rr, {63, 95});
            MaxRangeTree* ref16 = new MaxRangeTree(l, r, {63, 97});
            ref16->print(1);

            MaxRangeTree* tree16 = MaxRangeTree::buildFromLeaves(sortedLeave16, 0, 16);
            EXPECT(*ref16 == *tree16);
            delete tree16;
            delete ref16;

        }}
};

const test update[] {
    CASE({"2 leaves found : ") {
            NODE leaf2_0 = {1, 6};
            NODE leaf2_1 = {2, 5};
            NODE leaf2_1_mod = {2, 10};
            NODE sortedLeaves2[] = {leaf2_0, leaf2_1};
            NODE sortedLeaves2Mod[] = {leaf2_0, leaf2_1_mod};
            MaxRangeTree* ref2 = MaxRangeTree::buildFromLeaves(sortedLeaves2Mod, 0, 2);
            MaxRangeTree* tree2 = MaxRangeTree::buildFromLeaves(sortedLeaves2, 0, 2);
            tree2->update(2, 10);
            EXPECT(*ref2 == *tree2);
            delete ref2;
            delete tree2;
        }},

        CASE({"2 leaves not found : ") {
            NODE leaf2_0 = {1, 6};
            NODE leaf2_1 = {2, 5};
            NODE sortedLeaves2[] = {leaf2_0, leaf2_1};
            MaxRangeTree* tree2 = MaxRangeTree::buildFromLeaves(sortedLeaves2, 0, 2);
            tree2->update(5, 10);
            MaxRangeTree* ref2 = MaxRangeTree::buildFromLeaves(sortedLeaves2, 0, 2);
            EXPECT(*tree2 == *ref2);
            delete ref2;
            delete tree2;
    }},

        CASE({"16 leaves found : ") {
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

            MaxRangeTree* ref16 = MaxRangeTree::buildFromLeaves(sortedLeaves16Mod, 0, 2);
            MaxRangeTree* tree16 = MaxRangeTree::buildFromLeaves(sortedLeaves16, 0, 2);
            tree16->update(18, 99);
                    EXPECT(*ref16 == *tree16);
            delete ref16;
            delete tree16;
    }},
        CASE({"16 leaves not found : ") {
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
            MaxRangeTree* tree16 = MaxRangeTree::buildFromLeaves(sortedLeaves16, 0, 16);
            tree16->update(31, 100);
            MaxRangeTree* ref16 = MaxRangeTree::buildFromLeaves(sortedLeaves16, 0, 16);
            EXPECT(*tree16 == *ref16);
            delete ref16;
            delete tree16;
    }}
};

const test rangeMaxQuery[] {
    CASE({"16 leaves : ") {
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
            MaxRangeTree* tree16 = MaxRangeTree::buildFromLeaves(sortedLeaves16, 0, 16);
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
    }}
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
