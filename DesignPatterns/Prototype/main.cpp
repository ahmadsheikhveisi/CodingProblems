#include <iostream>
#include <memory>
#include <string>

#include "factory.hpp"

int main() {
	factory tfact;

    auto product{tfact.createProduct(products::product1)};
	product->print();

	product = tfact.createProduct(products::product1);
	product->print();

	return 0;
}




