#include "lob/orderbook.hh"


const std::string& OrderBook::GetInstrumentName() const
{
    return this->instrument_;
}

void OrderBook::InsertOrder(const Order& order)
{
    if (order.getType() == OrderType::BUY)
    {
        auto levelIt = this->bids_.try_emplace(order.getPricePerUnit()).first;
        levelIt->second.push_back(order);
        auto orderIt = std::prev(levelIt->second.end());

        orderMap.emplace(order.getOrderId(), OrderHandle{
            order.getType(),
            levelIt,
            orderIt
        });
    }
    else
    {
        auto levelIt = this->asks_.try_emplace(order.getPricePerUnit()).first;
        levelIt->second.push_back(order);
        auto orderIt = std::prev(levelIt->second.end());

        orderMap.emplace(order.getOrderId(), OrderHandle{
            order.getType(),
            levelIt,
            orderIt
        });
    }
}

const bool OrderBook::DeleteOrder(const unsigned int orderId)
{
    //fetch the orderMap iterator to get the OrderHandle
    auto orderHandleIt = this->orderMap.find(orderId);

    if (orderHandleIt == this->orderMap.end())
        return false;

    //fetch the dlist that is the level of the order
    auto& level = orderHandleIt->second.levelIt->second;

    //erase from price level
    level.erase(orderHandleIt->second.orderIt);

    //erase the price level if empty after deletion
    if (level.empty())
    {
        if (orderHandleIt->second.side == OrderType::BUY)
            this->bids_.erase(orderHandleIt->second.levelIt);
        else
            this->asks_.erase(orderHandleIt->second.levelIt);
    }

    this->orderMap.erase(orderHandleIt);
    return true;
}

const BidBook& OrderBook::GetBids() const
{
    return this->bids_;
}

const AskBook& OrderBook::GetAsks() const
{
    return this->asks_;
}