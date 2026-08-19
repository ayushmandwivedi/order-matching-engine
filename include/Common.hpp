#pragma once

#include <cstdint>

enum class Side : uint8_t {
    BUY,
    SELL
};

enum class OrderType : uint8_t {
    LIMIT,
    MARKET
};

using OrderId = uint64_t;
using Price = uint64_t;      // Represented in integer ticks/cents
using Quantity = uint32_t;
using Timestamp = uint64_t;  // Nanoseconds since epoch