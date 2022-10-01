#ifndef factory_hpp
#define factory_hpp

#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

#include "prototype.hpp"
#include "product1.hpp"
#include "product2.hpp"


enum class products : int {
    product1,
    product2
};

class factory {
 private:
    std::unordered_map<products, std::unique_ptr<prototype>> m_database;

 public:
    factory() {
        m_database[products::product1] = std::make_unique<product1>("name1", 1);
        m_database[products::product2] = std::make_unique<product2>("name2", 2);
    }

    std::unique_ptr<prototype> createProduct(products productname) {
        return m_database[productname]->clone();
    }
};

#endif
