/* COPYRIGHT
*/
#include <iostream>

#include "stack.hpp"

int main() {
    stack_impl::stack<int> msck;
    msck.push(0);
    msck.push(1);
    std::cout << msck.top() << '\n';
    msck.pop();
    std::cout << msck.top() << '\n';
    return 0;
}
