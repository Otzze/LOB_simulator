#include "orderbook.hh"


const std::string& Orderbook::GetInstrumentName() const
{
    return this->instrument_;
}

void OrderBook::InsertOrder(const Order& order)
{
    auto& book = (order.type == OrderType::BUY) ? this->bids_ : this->asks_;

    auto LevelIt = book.try_emplace(order.price).first;
    LevelIt->second.push_back(order);

    auto orderIt = std::prev(levelIt->second.end());

    orderMap[order.id] = {
        order.side,
        levelIt,
        orderIt
    };
}

const bool OrderBook::DeleteOrder(const unsigned int orderId);
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
            this->bids_.erase(orderHandleIt.second.levelIt);
        else
            this->asks_.erase(orderHandleIt.second.levelIt);
    }
}