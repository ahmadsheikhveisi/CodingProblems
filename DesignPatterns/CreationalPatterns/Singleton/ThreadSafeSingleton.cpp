

#include "ThreadSafeSingleton.hpp"

#include <string>
#include <mutex>

ThreadSafeSingleton ThreadSafeSingleton::singleton{std::string()};
std::mutex ThreadSafeSingleton::m_mutex;

std::string ThreadSafeSingleton::getValue() const {
    return m_value;
}

ThreadSafeSingleton& ThreadSafeSingleton::GetInstance(
        const std::string& value) {
    std::lock_guard<std::mutex> lock(singleton.m_mutex);
    if (singleton.m_value.empty()) {
        singleton.m_value = value;
    }
    return singleton;
}
