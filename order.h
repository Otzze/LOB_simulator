#pragma once

#include <iostream>
#include <string>
#include <ctime>

class Order {
    public:
        enum OrderType {
            BUY,
            SELL
        };

    private:
        const unsigned int orderId;
        const unsigned int customerId;
        const unsigned int amount;
        const unsigned int pricePerUnit;
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
