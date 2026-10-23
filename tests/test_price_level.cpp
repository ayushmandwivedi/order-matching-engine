#include <iostream>
#include <cassert>
#include "PriceLevel.hpp"

int main() {
    std::cout << "Testing Order and PriceLevel intrusive list..." << std::endl;

    PriceLevel level(10050); // $100.50

    Order o1(1, 101, Side::BUY, OrderType::LIMIT, 10050, 10, 1000);
    Order o2(2, 102, Side::BUY, OrderType::LIMIT, 10050, 20, 1005);
    Order o3(3, 103, Side::BUY, OrderType::LIMIT, 10050, 15, 1010);

    // Test FIFO Insertion
    level.push_back(&o1);
    level.push_back(&o2);
    level.push_back(&o3);

    assert(level.orderCount() == 3);
    assert(level.totalVolume() == 45);
    assert(level.head() == &o1);
    assert(level.tail() == &o3);

    // Test Middle Removal (O(1))
    level.remove(&o2);
    assert(level.orderCount() == 2);
    assert(level.totalVolume() == 25);
    assert(o1.next == &o3);
    assert(o3.prev == &o1);

    // Test Head Removal
    level.remove(&o1);
    assert(level.head() == &o3);
    assert(level.tail() == &o3);

    // Test Tail Removal (Becomes Empty)
    level.remove(&o3);
    assert(level.empty());
    assert(level.orderCount() == 0);
    assert(level.totalVolume() == 0);

    std::cout << "All Phase 1 PriceLevel assertions passed successfully!" << std::endl;
    return 0;
}