
#ifndef DESIGNPATTERNS_STRUCTURALPATTERNS_DECORATOR_SIMPLEWRAPPER_HPP_
#define DESIGNPATTERNS_STRUCTURALPATTERNS_DECORATOR_SIMPLEWRAPPER_HPP_

#include <string>
#include <iostream>
#include <memory>

class Component {
 public:
    virtual std::string Operation() const = 0;
    virtual ~Component() {
        std::cout << "Component Destructor\n";
    }
};

// if concreteComponent adds more functionality,
// decorator doesn't have any idea.
class ConcretComponent : public Component {
 public:
    std::string Operation() const override {
        return "ConcretComponent";
    }
};

class Decorator : public Component {
 public:
    explicit Decorator(std::shared_ptr<Component> component) :
        m_component(component) {}
    std::string Operation() const override {
        return m_component->Operation();
    }
 protected:
    std::shared_ptr<Component> m_component;  // Aggregation.
    // the original object must be kept around
    // decorator doesn't take ownership of the component.
};

// Decorator doesn't know anything about concreate component.
// it is a fundamental C++ limitation; it does not handle
// cross-casting well (casting to a type in another branch of the
// same hierarchy)
class ConcreteDecoratorA : public Decorator {
 public:
    explicit ConcreteDecoratorA(std::shared_ptr<Component> component) :
        Decorator(component) {}
    std::string Operation() const override {
        return "ConcreteDecoratorA(" + Decorator::Operation() + ")";
    }
};

class ConcreteDecoratorB : public Decorator {
 public:
    explicit ConcreteDecoratorB(std::shared_ptr<Component> component) :
        Decorator(component) {}
    std::string Operation() const override {
        return "ConcreateDecoratorB(" + Decorator::Operation() + ")";
    }
};

#endif  // DESIGNPATTERNS_STRUCTURALPATTERNS_DECORATOR_SIMPLEWRAPPER_HPP_
