#pragma once

#include <iostream>
#include <string>
#include <ctime>

#include "lob/order_type.hh"

class Order {
    private:
        const unsigned int orderId;
        const unsigned int customerId;
        const unsigned float amount;
        const unsigned float pricePerUnit;
        const OrderType type;
        const std::string instrument;
        time_t timestamp;

    public:
        Order(unsigned int orderId, unsigned int customerId, unsigned int amount, unsigned int pricePerUnit, OrderType type, const std::string& instrument);

        unsigned int getOrderId() const;
        unsigned int getCustomerId() const;
        unsigned int getAmount() const;
        unsigned int getPricePerUnit() const;
        OrderType getType() const;
        std::string getInstrument() const;
        time_t getTimestamp() const;
};
