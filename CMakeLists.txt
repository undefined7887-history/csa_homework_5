cmake_minimum_required(VERSION 3.21)
project(csa_homework_5)

set(CMAKE_CXX_STANDARD 14)

find_package(Threads REQUIRED)

add_executable(csa_homework_5
        src/main.cpp
        src/Customer.cpp
        src/Customer.h
        src/Queue.cpp
        src/Queue.h
        src/Utils.cpp
        src/Utils.h
        src/Vendor.cpp
        src/Vendor.h)

target_link_libraries(csa_homework_5 PRIVATE Threads::Threads)
