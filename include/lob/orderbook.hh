#pragma once

#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <list>

#include "lob/order.hh"
#include "lob/order_type.hh"

using OrderList = std::list<Order>;
using BidBook = std::map<const float, OrderList, std::greater<float>>;
using AskBook = std::map<const float, OrderList>;

class OrderBook {
    public:
        //Handler for an order containing:
        // - the order side
        // - the iterator to the doubly linked list
        // - the iterator to the Order inside the dlist
        struct OrderHandle{
            const OrderType side;
            std::map<const float, OrderList>::iterator levelIt;
            OrderList::iterator orderIt;
        };
    
        OrderBook(const std::string& instrument):
            instrument_(instrument)
        {}

        const std::string& GetInstrumentName() const;

        void InsertOrder(const Order& order);
        const bool DeleteOrder(const unsigned int orderId);

        const BidBook& GetBids() const;
        const AskBook& GetAsks() const;
    
    private:
        //Instrument name for OB
        std::string instrument_;

        //Maps of price levels -> doubly linked lists for fast modification
        //These lists are used as FIFO queues
        BidBook bids_;
        AskBook asks_;

        //Map of OrderId -> OrderHandle for lookup
        std::unordered_map<unsigned int, OrderHandle> orderMap;
};