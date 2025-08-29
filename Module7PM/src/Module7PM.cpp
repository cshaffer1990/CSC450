#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>

std::mutex m;
std::condition_variable cv;
bool up_finished = false;

void count_up() {
    for (int i = 0; i <= 20; ++i) {
        { std::lock_guard<std::mutex> lock(m);
          std::cout << "[up]   " << i << '\n';
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(80));
    }
    { std::lock_guard<std::mutex> lock(m);
      up_finished = true;
    }
    cv.notify_one();
}

void count_down() {
    std::unique_lock<std::mutex> lock(m);
    cv.wait(lock, [] { return up_finished; });
    lock.unlock();

    for (int i = 20; i >= 0; --i) {
        { std::lock_guard<std::mutex> lock2(m);
          std::cout << "[down] " << i << '\n';
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(80));
    }
}

int main() {
    std::thread t1(count_up);
    std::thread t2(count_down);
    t1.join();
    t2.join();
    std::cout << "Done.\n";
    return 0;
}
