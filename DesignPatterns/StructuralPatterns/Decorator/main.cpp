
#include <memory>
#include <iostream>

#include "SimpleWrapper.hpp"

void ClientCode(std::shared_ptr<Component> component) {
    std::cout << component->Operation() << '\n';
}

int main() {
    auto simple{std::make_shared<ConcretComponent>()};
    ClientCode(simple);
    auto decorator1{std::make_shared<ConcreteDecoratorA>(simple)};
    ClientCode(decorator1);
    auto decorator2{std::make_shared<ConcreteDecoratorB>(decorator1)};
    ClientCode(decorator2);

    return 0;
}
