#ifndef CSA_HOMEWORK_5_CUSTOMER_H
#define CSA_HOMEWORK_5_CUSTOMER_H

#include "Queue.h"

class Customer {
    Queue *queue_;
    int index_;

public:
    Customer(Queue *queue, int index);

    void run();

    int getIndex() const;
};

#endif //CSA_HOMEWORK_5_CUSTOMER_H
