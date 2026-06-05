add_executable(
    lob_tests
    test_order.cc
    test_orderbook.cc
)

target_link_libraries(
    lob_tests
    PRIVATE
    lob_core
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(lob_tests)