add_library(
    lob_core
    order.cc
    orderbook.cc
    matching_engine.cc
    parser.cc
    reporter.cc
)

target_include_directories(
    lob_core
    PUBLIC ${CMAKE_SOURCE_DIR}/include
)