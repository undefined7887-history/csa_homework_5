#include <random>
#include <thread>
#include "Utils.h"

int Utils::randomNumber(int min, int max) {
    static std::random_device device;
    static std::mt19937 engine(device());

    std::uniform_int_distribution<int> random(min, max);
    return random(engine);
}

void Utils::sleep(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}
