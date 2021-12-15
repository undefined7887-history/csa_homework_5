#include <iostream>
#include <thread>
#include "Queue.h"
#include "Customer.h"
#include "Vendor.h"

#define VENDORS_COUNT 3

#define MIN_CUSTOMERS_COUNT 1
#define MAX_CUSTOMERS_COUNT 50

int getCustomersCount() {
    int result = 0;

    std::cout << "Enter the number of customers: ";
    std::cin >> result;

    while (result < MIN_CUSTOMERS_COUNT || result > MAX_CUSTOMERS_COUNT) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Wrong input, enter the number between "
                  << MIN_CUSTOMERS_COUNT << " and " << MAX_CUSTOMERS_COUNT << " : ";

        std::cin >> result;
    }

    return result;
}

std::vector<Customer> getCustomers(Queue *queue, int count) {
    std::vector<Customer> customers;
    customers.reserve(count);

    for (int i = 0; i < count; i++) {
        customers.emplace_back(queue, i);
    }

    return customers;
}


std::vector<Vendor> getVendors(Queue *queue, int count) {
    std::vector<Vendor> vendors;
    vendors.reserve(count);

    for (int i = 0; i < count; i++) {
        vendors.emplace_back(queue, i);
    }

    return vendors;
}

int main() {
    int customers_count = getCustomersCount();
    auto queue = new Queue(customers_count);

    std::vector<std::thread> vendor_threads;

    auto vendors = getVendors(queue, VENDORS_COUNT);
    auto customers = getCustomers(queue, customers_count);

    for (auto &vendor: vendors) {
        std::thread th([&vendor]() {
            vendor.run();
        });

        vendor_threads.push_back(std::move(th));
    }

    for (auto &customer: customers) {
        std::thread th([&customer]() {
            customer.run();
        });

        th.detach();
    }

    for (auto &vendor_thread: vendor_threads) {
        vendor_thread.join();
    }

    std::cout << "All customers served" << std::endl;
}
