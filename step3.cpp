#include <iostream>
#include <mutex>

std::mutex mtx;

void selfLock() {
    mtx.lock();
    mtx.lock();
    std::cout << "Anyone there?" << std::endl;

    mtx.unlock();
    mtx.unlock();
}

int main() {
    selfLock();
    std::cout << "Program finished." << std::endl;
    return 0;
}
