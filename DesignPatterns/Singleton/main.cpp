
#include <iostream>
#include <thread>

#include "NaiveSingleton.hpp"
#include "ThreadSafeSingleton.hpp"

void ThreadFoo() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    auto singleton{NaiveSingleton::GetInstance("FOO")};
    std::cout << singleton->getVal() << '\n';
}

void ThreadBar() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    auto singleton{NaiveSingleton::GetInstance("Bar")};
    std::cout << singleton->getVal() << '\n';
}

void ThreadSafeFoo() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    auto singleton{ThreadSafeSingleton::GetInstance("Foo Safe")};
    std::cout << singleton.getValue() << '\n';
}

void ThreadSafeBar() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    auto singleton{ThreadSafeSingleton::GetInstance("Bar Safe")};
    std::cout << singleton.getValue() << '\n';
}


int main() {
    {
        std::thread t1(ThreadFoo);
        std::thread t2(ThreadBar);
        t1.join();
        t2.join();
    }
    {
        std::thread t1(ThreadSafeFoo);
        std::thread t2(ThreadSafeBar);
        t1.join();
        t2.join();
    }
    return 0;
}
