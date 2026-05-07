add_library(
    lob_core
    order.cc
    orderbook.cc
)

target_include_directories(
    lob_core
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)