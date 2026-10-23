#pragma once

#include "Common.hpp"

struct Order {
    OrderId id{0};
    uint64_t userId{0};
    Side side{Side::BUY};
    OrderType type{OrderType::LIMIT};
    Price price{0};
    Quantity quantity{0};
    Timestamp timestamp{0};
    Order* prev{nullptr};
    Order* next{nullptr};

    Order() = default;

    Order(OrderId id, uint64_t userId, Side side, OrderType type, Price price, Quantity quantity, Timestamp timestamp)
    : id(id),
      userId(userId),
      side(side),
      type(type),
      price(price),
      quantity(quantity),
      timestamp(timestamp),
      prev(nullptr),
      next(nullptr){}
};