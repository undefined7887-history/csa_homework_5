#include <mutex>
#include <iostream>
#include "Queue.h"

Queue::Queue(int customers_count) : customers_count_(customers_count) {
}

void Queue::appendCustomer(void *customer) {
    std::lock_guard<std::mutex> lock(mutex_);

    if (customers_count_ == 0) {
        return;
    }

    // Adding customer to queue
    customers_count_--;
    customers_.push_back(customer);

    // Notifying vendors that new customer is ready
    condition_.notify_one();
}

void *Queue::getCustomer() {
    std::unique_lock<std::mutex> lock(mutex_);
    while (customers_.empty()) {
        condition_.wait(lock);
    }

    auto customer = customers_.back();
    customers_.pop_back();

    return customer;
}

bool Queue::done() {
    std::lock_guard<std::mutex> lock(mutex_);

    // No more customers expected
    return customers_count_ == 0;
}