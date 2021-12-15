#ifndef CSA_HOMEWORK_5_QUEUE_H
#define CSA_HOMEWORK_5_QUEUE_H

#include <vector>
#include <mutex>
#include <condition_variable>

class Queue {
    int customers_count_;

    std::mutex mutex_;
    std::condition_variable condition_;

    std::vector<void *> customers_;

public:
    explicit Queue(int customers_count);

    void *getCustomer();

    void appendCustomer(void *customer);

    bool done();
};

#endif //CSA_HOMEWORK_5_QUEUE_H
