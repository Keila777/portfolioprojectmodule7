#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;  // Mutex for synchronization

void CountUp() {
    for (int i = 1; i <= 20; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Simulate work
        mtx.lock();
        std::cout << "Thread 1: Counting up - " << i << std::endl;
        mtx.unlock();
    }
}

void CountDown() {
    for (int i = 20; i >= 0; --i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Simulate work
        mtx.lock();
        std::cout << "Thread 2: Counting down - " << i << std::endl;
        mtx.unlock();
    }
}

int main() {
    std::thread t1(CountUp);
    std::thread t2(CountDown);

    t1.join();
    t2.join();

    return 0;
}