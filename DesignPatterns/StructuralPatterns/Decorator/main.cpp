
#include <memory>
#include <iostream>

#include "SimpleWrapper.hpp"
#include "CRTPWrapper.hpp"

void ClientCode(std::shared_ptr<Component> component) {
    std::cout << component->Operation() << '\n';
}

int main() {
    {
        auto simple{std::make_shared<ConcretComponent>()};
        ClientCode(simple);
        auto decorator1{std::make_shared<ConcreteDecoratorA>(simple)};
        ClientCode(decorator1);
        auto decorator2{std::make_shared<ConcreteDecoratorB>(decorator1)};
        ClientCode(decorator2);  // all objects need to be kept around.
    }
    {
        Knight k{10, 5};
        Ogre o{12, 2};
        k.charge();
        std::cout << "Knight hits Ogre " << k.hit(o) << '\n';
        Troll t{14, 10};
        std::cout << "Knight hits Troll " << k.hit(t) << '\n';
        VeteranUnit<Knight> vk(std::move(k), 7 , 2);  // takes ownership
        std::cout << "Vetran Knight hits Troll " << vk.hit(t) << '\n';
        VeteranUnit<Ogre> vo(std::move(o), 1, 9);
        std::cout << "Vetran knight hits veteran ogre: " << vk.hit(vo) << '\n';
        VeteranUnit<VeteranUnit<Ogre>> vvo(std::move(vo), 1, 9);
        std::cout << "Vetran knight hits veteran2 ogre: " <<
            vk.hit(vvo) << '\n';
        vk.charge();
        std::cout << "Vetran knight hits veteran2 ogre: " <<
            vk.hit(vvo) << '\n';
    }
    return 0;
}
