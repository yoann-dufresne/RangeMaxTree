# RangeMaxTree

## Description
Tree to support log time range max queries and updates.<br>
It's a semi-dynamic structure, it does not support addition or deletion once built.

## Install

1. `git clone git@github.com:yoann-dufresne/RangeMaxTree.git`
2. `git submodule init`
3. `git submodule update`

## Compilation
To compile a CMake is at the root of the project.
Execute : 

- `cmake .`
- `make`

It should be ready to use.

## Main methods of the MaxRangeTree class

- `MaxRangeTree::buildFromLeaves(NODE sortedLeaves, int start, int end)`
- `MaxRangeTree.update(int key, int val)`

An example is available in Apps/main.cpp

## Testing 
Unit tests are available in the UnitTest directory.<br>
To run the unit tests from the root (after compilation) : `./UnitTest/UnitTest`

## Dependencies

1. lest for unit tests -> https://github.com/martinmoene/lest

## Bibliography
[1]. _Genome-Scale Algorithm Design_, VELI MÄKINEN, DJAMAL BELAZZOUGUI, FABIO CUNIAL, ALEXANDRU I.TOMESCU (page 20).
