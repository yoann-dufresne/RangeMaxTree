add_library(RangeMaxTree
        BinaryTree.cpp)

target_include_directories(RangeMaxTree
        PUBLIC
        "${PROJECT_SOURCE_DIR}/src/headers/"
        )
