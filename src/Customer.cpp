#include "Utils.h"
#include "Customer.h"

#define MIN_CUSTOMER_BUYING_TIME 500
#define MAX_CUSTOMER_BUYING_TIME 2000

Customer::Customer(Queue *queue, int index) : queue_(queue), index_(index) {
}

void Customer::run() {
    printf("Customer %d came to the shop\n", index_);

    // Choosing products to buy
    Utils::sleep(Utils::randomNumber(MIN_CUSTOMER_BUYING_TIME, MAX_CUSTOMER_BUYING_TIME));

    printf("Customer %d entered the queue\n", index_);

    // Customer enters the queue_
    queue_->appendCustomer(this);
}

int Customer::getIndex() const {
    return this->index_;
}
