add_executable(UnitTest
        RangeTest.cpp)

target_link_libraries(UnitTest
        RangeMaxTree)

target_include_directories(UnitTest
        PUBLIC
        .
        "${PROJECT_SOURCE_DIR}/extern/lest/include/lest"
        "${PROJECT_SOURCE_DIR}/RangeMaxTree"
        )