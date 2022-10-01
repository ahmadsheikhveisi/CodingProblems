
#ifndef DESIGNPATTERNS_SINGLETON_THREADSAFESINGLETON_HPP_
#define DESIGNPATTERNS_SINGLETON_THREADSAFESINGLETON_HPP_

#include <string>
#include <mutex>

class ThreadSafeSingleton {
 public:
    std::string getValue() const;
    static ThreadSafeSingleton& GetInstance(const std::string& value);
 private:
    std::string m_value;
    static std::mutex m_mutex;
    static ThreadSafeSingleton singleton;
    explicit ThreadSafeSingleton(const std::string& value) : m_value(value) {}
    //  ThreadSafeSingleton(ThreadSafeSingleton &) = delete;
    //  ThreadSafeSingleton& operator=(const ThreadSafeSingleton&) = delete;
    //  ThreadSafeSingleton(ThreadSafeSingleton&&) = delete;
    //  ThreadSafeSingleton& operator=(ThreadSafeSingleton&&) = delete;
};





#endif  // DESIGNPATTERNS_SINGLETON_THREADSAFESINGLETON_HPP_
