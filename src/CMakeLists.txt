add_library(RangeMaxTree
        MaxRangeTree.cpp)

target_include_directories(RangeMaxTree
        PUBLIC
        "${PROJECT_SOURCE_DIR}/src/headers/"
        )
