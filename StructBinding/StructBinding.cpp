#include <iostream>
#include <utility>
#include <tuple>

std::tuple<int,int> return2numbers(int inval)
{
	return std::make_tuple(inval*3,inval*2);
}

int main(int argc, char **argv) {
	std::cout << "Hello world";

	auto[num1,num2] = return2numbers(4);
	std::cout << num1 << " " << num2 << '\n';

	return 0;
}
