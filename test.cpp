#include "order.h"
#include <iostream>

int main() {
    Order order1(1, 100, 50, 10, Order::BUY, "AAPL");
    std::cout << "Order ID: " << order1.getOrderId() << std::endl;
    std::cout << "Customer ID: " << order1.getCustomerId() << std::endl;
    std::cout << "Amount: " << order1.getAmount() << std::endl;
    std::cout << "Price per Unit: " << order1.getPricePerUnit() << std::endl;
    std::cout << "Type: " << (order1.getType() == Order::BUY ? "BUY" : "SELL") << std::endl;
    std::cout << "Instrument: " << order1.getInstrument() << std::endl;
    std::cout << "Timestamp: " << order1.getTimestamp() << std::endl;

    return 0;
};