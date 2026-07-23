enable_testing()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(tests)

target_sources(tests
    PRIVATE
        ops_test.cpp
        types_test.cpp

)

target_link_libraries(tests
    PRIVATE
        linalg
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)