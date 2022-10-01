
#ifndef DESIGNPATTERNS_CREATIONALPATTERNS_PROTOTYPE_PRODUCT1_HPP_
#define DESIGNPATTERNS_CREATIONALPATTERNS_PROTOTYPE_PRODUCT1_HPP_

#include <iostream>
#include <memory>
#include <string>

#include "prototype.hpp"

class product1 : public prototype {
 public:
    product1(std::string name, int price): m_name(name), m_price(price) {
        std::cout << "product1 constructor1\n";
    }

    product1(const product1& other) {
        std::cout << "product1 copy constructor\n";
        m_name = other.m_name;
        m_price = other.m_price;
    }

    product1(const product1&& other) {
        std::cout << "product1 move constructor\n";
        m_name = other.m_name;
        m_price = other.m_price;
    }

    virtual ~product1() {
        std::cout << "product1 destructor\n";
    }

    product1& operator=(const product1& other) {
        std::cout << "product1 assignment\n";
        m_name = other.m_name;
        m_price = other.m_price;
        return *this;
    }

    product1& operator=(product1&& other) {
        std::cout << "product1 swapped\n";
        m_name = other.m_name;
        m_price = other.m_price;
        return *this;
    }

    void print() override {
        std::cout << "product1\n";
    }

    std::unique_ptr<prototype> clone() override {
        return std::make_unique<product1>(*this);
    }

 private:
    std::string m_name;
    int m_price;
};


#endif  // DESIGNPATTERNS_CREATIONALPATTERNS_PROTOTYPE_PRODUCT1_HPP_
