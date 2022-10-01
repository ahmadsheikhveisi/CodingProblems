
#ifndef DESIGNPATTERNS_CREATIONALPATTERNS_PROTOTYPE_PRODUCT2_HPP_
#define DESIGNPATTERNS_CREATIONALPATTERNS_PROTOTYPE_PRODUCT2_HPP_

#include <iostream>
#include <memory>
#include <string>

#include "prototype.hpp"

class product2 : public prototype {
 public:
    product2(std::string name, int price): m_name(name), m_price(price) {
        std::cout << "product2 constructor2\n";
    }

    void print() override {
        std::cout << "product2\n";
    }

    std::unique_ptr<prototype> clone() override {
        return std::make_unique<product2>(*this);
    }
 private:
    std::string m_name;
    int m_price;
};

#endif  // DESIGNPATTERNS_CREATIONALPATTERNS_PROTOTYPE_PRODUCT2_HPP_
