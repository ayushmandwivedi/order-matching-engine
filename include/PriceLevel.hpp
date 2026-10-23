#pragma once

#include "Order.hpp"
#include <cstddef>

class PriceLevel {
public:
    explicit PriceLevel(Price price = 0)
        : price_(price), head_(nullptr), tail_(nullptr), totalVolume_(0), orderCount_(0) {}
    
    // Append an order to the back of the queue (Time Priority - FIFO)
    void push_back(Order* order){
        if(!order) return;

        order->next = nullptr;
        order->prev = tail_;

        if(tail_) {
            tail_->next = order;
        }
        else {
            head_ = order;
        }
        tail_ = order;

        totalVolume_ += order->quantity;
        ++orderCount_;
    }

    // Detach an order in O(1) time
    void remove(Order* order){
        if(!order) return;

        if(order->prev) {
            order->prev->next = order->next;
        }
        else {
            head_ = order->next;
        }

        if(order->next) {
            order->next->prev = order->prev;
        }
        else {
            tail_ = order->prev;
        }

        order->prev = nullptr;
        order->next = nullptr;

        totalVolume_ -= order->quantity;
        --orderCount_;
    }

    [[nodiscard]] bool empty() const noexcept {
        return head_ == nullptr;
    }

    [[nodiscard]] Order* head() const noexcept { return head_; }
    [[nodiscard]] Order* tail() const noexcept { return tail_; }
    [[nodiscard]] Price price() const noexcept { return price_; }
    [[nodiscard]] Quantity totalVolume() const noexcept { return totalVolume_; }
    [[nodiscard]] size_t orderCount() const noexcept { return orderCount_; }

private:
    Price price_{0};
    Order* head_{nullptr};
    Order* tail_{nullptr};
    Quantity totalVolume_{0};
    size_t orderCount_{0};
};