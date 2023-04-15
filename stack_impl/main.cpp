/* COPYRIGHT
*/
#include <iostream>
#include <vector>

#include "stack.hpp"

class mtype {
 public:
    std::string name;
    mtype() {
        name = "default ctor";
        std::cout << "Constructed: " << name << '\n';
    }
    explicit mtype(std::string const& str) {
        name = str;
        std::cout << "Constructed: " << name << '\n';
    }
    ~mtype() {
        std::cout << name << " destructed\n";
    }
    mtype(mtype&& other) {
        name += " " + std::move(other.name) + " Moved";
        std::cout << "Moved constructed: " << name << '\n';
    }
    mtype(mtype const & other) {
        name += " " + other.name + " Copied";
        std::cout << "Copied constructed: " << name << '\n';
    }
    mtype& operator=(mtype const & other) {
        name += " " + other.name + " Assign copied";
        std::cout << "Assgined copied: " << name << '\n';
        return *this;
    }
    mtype& operator=(mtype&& other) {
        name += " " + std::move(other.name) + " Moved assign";
        std::cout << "Move assigned: " << name << '\n';
        return *this;
    }
    const std::string & print() const {
        return name;
    }
};

int main() {
    stack_impl::stack<mtype> msck;
    {
        mtype data1{"Temp"};
        std::cout << "Created\n";
        msck.push(std::move(data1));
        std::cout << "Pushed\n";
    }
    std::cout << "top is: " << msck.top().name << '\n';

    /*msck.push(0);
    msck.push(1);
    std::cout << msck.top() << '\n';
    std::cout << msck.size() << '\n';
    msck.pop();
    std::cout << msck.top() << '\n';
    std::cout << msck.size() << '\n';
    msck.pop();
    std::cout << msck.size() << '\n';
    msck.pop();
    std::cout << msck.size() << '\n';*/

    std::vector<mtype> vec;
    {
        mtype const data1{"Temp"};
        std::cout << "Created\n";
        vec.emplace_back(std::move(data1));
        std::cout << "Pushed\n";
    }
    std::cout << vec.back().name << '\n';
    return 0;
}
