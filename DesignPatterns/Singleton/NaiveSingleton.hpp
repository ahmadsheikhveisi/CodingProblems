
#ifndef DESIGNPATTERNS_SINGLETON_NAIVESINGLETON_HPP_
#define DESIGNPATTERNS_SINGLETON_NAIVESINGLETON_HPP_

#include <string>
#include <memory>

class NaiveSingleton final {
 public:
    std::string getVal() const;
    static std::shared_ptr<NaiveSingleton>
        GetInstance(const std::string& value);
 protected:
    std::string m_value;

    /*constructor*/
    explicit NaiveSingleton(const std::string& value) : m_value(value) {}
    /*copy constructor*/
    NaiveSingleton(const NaiveSingleton&) = delete;
    /*assignment operator*/
    NaiveSingleton& operator=(const NaiveSingleton&) = delete;
    /*move constructor*/
    NaiveSingleton(NaiveSingleton&&) = delete;
    /*move assingment operator*/
    NaiveSingleton& operator=(NaiveSingleton&&) = delete;

    static std::shared_ptr<NaiveSingleton> m_singleton;
};

#endif  /*DESIGNPATTERNS_SINGLETON_NAIVESINGLETON_HPP_*/
