#include <cstdio>
#include "Vendor.h"
#include "Utils.h"

#define MIN_CUSTOMER_SERVE_TIME 200
#define MAX_CUSTOMER_SERVE_TIME 1000

Vendor::Vendor(Queue *queue, int index) : queue_(queue), index_(index) {
}

void Vendor::run() {
    while (!queue_->done()) {
        printf("Vendor %d is free\n", index_);

        auto customer = (Customer *) queue_->getCustomer();

        printf("Customer %d will be served by Vendor %d\n", customer->getIndex(), index_);

        // Serving customer
        Utils::sleep(Utils::randomNumber(MIN_CUSTOMER_SERVE_TIME, MAX_CUSTOMER_SERVE_TIME));

        // Customer served
        printf("Customer %d served by Vendor %d\n", customer->getIndex(), index_);
    }
}


