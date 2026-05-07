#pragma once

#include <iostream>
#include <unordered_map>
#include <vector>

#include "order.hh"
#include "orderbook.hh"

class MatchingEngine{
    public:
        MatchineEngine();
        const char& PlaceOrder(const Order& order);
        bool CancelOrder(const char& orderId);

        std::vector<std::string> ListInstruments();

    private:
        std::unordered_map<std::string, OrderBook> order_books;
};