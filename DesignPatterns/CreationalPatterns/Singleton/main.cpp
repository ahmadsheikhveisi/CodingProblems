
#include <iostream>
#include <thread>

#include "NaiveSingleton.hpp"
#include "ThreadSafeSingleton.hpp"
#include "ZeroHandle.hpp"
#include "MeyerSingleton.hpp"

void ThreadFoo() {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    auto singleton{NaiveSingleton::GetInstance("FOO")};
    std::cout << singleton->getVal() << '\n';
}

void ThreadBar() {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    auto singleton{NaiveSingleton::GetInstance("Bar")};
    std::cout << singleton->getVal() << '\n';
}

void ThreadSafeFoo() {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    auto singleton{ThreadSafeSingleton::GetInstance("Foo Safe")};
    std::cout << singleton.getValue() << '\n';
}

void ThreadSafeBar() {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
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
    {
        auto func{[](){
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            ++ZeroHandle::getVal();
        }};
        std::thread t1(func);
        std::thread t2(func);
        t1.join();
        t2.join();
        auto res{ZeroHandle::getVal()};
        std::cout << res << '\n';
    }
    {
        auto func{[](){
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            auto singleton{MeyerSingleton()};
            ++singleton.get();
        }};
        std::thread t1(func);
        std::thread t2(func);
        t1.join();
        t2.join();
        auto res{MeyerSingleton()};
        std::cout << res.get() << '\n';
    }
    std::cout << "exit main\n";
    return 0;
}
