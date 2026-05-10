#include <gtest/gtest.h>

#include "lob/order_type.hh"
#include "lob/order.hh"

TEST(CoreClasses, Order) {
    Order o = Order{1, 1, 10, 30, OrderType::BUY, "SPY"};
    EXPECT_EQ(o.getOrderId(), 1);
}