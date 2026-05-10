#include <gtest/gtest.h>

#include "lob/order_type.hh"
#include "lob/order.hh"

TEST(CoreClasses, Order) {
    Order o = Order{1, 1, 10, 30, OrderType::BUY, "SPY"};
    EXPECT_EQ(o.getOrderId(), 1);
    EXPECT_EQ(o.getCustomerId(), 1);
    EXPECT_EQ(o.getAmount(), 10);
    EXPECT_EQ(o.getPricePerUnit(), 30);
    EXPECT_EQ(o.getType(), OrderType::BUY);
    EXPECT_EQ(o.getInstrument(), "SPY");
}