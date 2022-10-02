
#ifndef DESIGNPATTERNS_STRUCTURALPATTERNS_ADAPTER_SIMPLEADAPTER_HPP_
#define DESIGNPATTERNS_STRUCTURALPATTERNS_ADAPTER_SIMPLEADAPTER_HPP_

#include <string>
#include <iostream>

namespace SimpleAdapter {

class Target {
 public:
    virtual std::string Request() const {
        return "Target: default target behavior.\n";
    }
    virtual ~Target() = default;
};

void ClientCode(const Target& target) {
    std::cout << target.Request();
}

class Adaptee {
 public:
    std::string SpecificRequest() const {
        return "Adaptee: Special behavior\n";
    }
    virtual ~Adaptee() = default;
};

class Adapter : public Target {
 private:
    Adaptee& m_adaptee;
 public:
    explicit Adapter(Adaptee& adaptee) : m_adaptee(adaptee) {}

    std::string Request() const override {
        return "Adapter: " + m_adaptee.SpecificRequest();
    }
};

class MultipleInheritenceAdapter : public Target, public Adaptee {
 public:
    MultipleInheritenceAdapter() {}
    std::string Request() const {
        return "MultipleInheritence Adaptor: " + Adaptee::SpecificRequest();
    }
};

}  // namespace SimpleAdapter

#endif  // DESIGNPATTERNS_STRUCTURALPATTERNS_ADAPTER_SIMPLEADAPTER_HPP_
