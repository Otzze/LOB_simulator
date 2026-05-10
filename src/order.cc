#include "lob/order.hh"
#include <ctime>

Order::Order(unsigned int orderId, unsigned int customerId, float amount, float pricePerUnit, OrderType type, const std::string& instrument)
    : orderId(orderId), customerId(customerId), amount(amount), pricePerUnit(pricePerUnit), type(type), instrument(instrument){
        timestamp = time(&timestamp);
    };

unsigned int Order::getOrderId() const {
    return orderId;
}

unsigned int Order::getCustomerId() const {
    return customerId;
}

float Order::getAmount() const {
    return amount;
}

float Order::getPricePerUnit() const {
    return pricePerUnit;
}

OrderType Order::getType() const {
    return type;
}

std::string Order::getInstrument() const {
    return instrument;
}

time_t Order::getTimestamp() const {
    return timestamp;
}
