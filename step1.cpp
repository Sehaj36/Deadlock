#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex mtx1;
std::mutex mtx2;

void taskA() {
    std::cout << "Task A trying to lock mtx1..." << std::endl;
    mtx1.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    std::cout << "Task A locked mtx1. Trying to lock mtx2..." << std::endl;
    mtx2.lock();

    std::cout << "Task A locked both mutexes." << std::endl;

    mtx2.unlock();
    mtx1.unlock();
}

void taskB() {
    std::cout << "Task B trying to lock mtx1..." << std::endl;
    mtx1.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    std::cout << "Task B locked mtx1. Trying to lock mtx2..." << std::endl;
    mtx2.lock();

    std::cout << "Task B locked both mutexes." << std::endl;

    mtx2.unlock();
    mtx1.unlock();
}

int main() {
    std::cout << "No Deadlock Example (Consistent Lock Order)\n" << std::endl;

    std::thread t1(taskA);
    std::thread t2(taskB);

    t1.join();
    t2.join();

    std::cout << "\nBoth threads completed successfully." << std::endl;
    return 0;
}
