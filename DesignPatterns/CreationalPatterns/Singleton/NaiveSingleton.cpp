

#include <memory>
#include <string>

#include "NaiveSingleton.hpp"

std::shared_ptr<NaiveSingleton> NaiveSingleton::m_singleton = nullptr;

/* This doesn't work, since make_shared needs to call new and constructor is protected.
 * this needs to wrap the new in a shared pointer.
std::shared_ptr<NaiveSingleton>
    NaiveSingleton::GetInstance(const std::string& value) {
    if (m_singleton == nullptr) {
        m_singleton = std::make_shared<NaiveSingleton>(value);
    }
    return m_singleton;
}
*/

std::shared_ptr<NaiveSingleton>
    NaiveSingleton::GetInstance(const std::string& value) {
    if (NaiveSingleton::m_singleton == nullptr) {
        NaiveSingleton::m_singleton =
            std::shared_ptr<NaiveSingleton>(new NaiveSingleton(value));
    }
    return NaiveSingleton::m_singleton;
}

std::string NaiveSingleton::getVal() const {
    return m_value;
}
