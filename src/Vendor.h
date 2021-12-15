#ifndef CSA_HOMEWORK_5_VENDOR_H
#define CSA_HOMEWORK_5_VENDOR_H

#include "Queue.h"
#include "Customer.h"

class Vendor {
    Queue *queue_;
    int index_;

public:
    Vendor(Queue *queue, int index);

    void run();
};


#endif //CSA_HOMEWORK_5_VENDOR_H
