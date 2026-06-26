#include <gtest/gtest.h>

#include "lob/order_type.hh"
#include "lob/order.hh"
#include "lob/orderbook.hh"

TEST(CoreClasses, OrderBook) {
    OrderBook OB = OrderBook("SPY");
    EXPECT_EQ(OB.GetInstrumentName(), "SPY");
}

TEST(CoreClasses, OrderBookAdd) {
    OrderBook OB = OrderBook("SPY");
    Order o = Order{1, 1, 10, 30, OrderType::BUY, "SPY"};
    OB.InsertOrder(o);
    EXPECT_EQ(OB.GetBids, )
}