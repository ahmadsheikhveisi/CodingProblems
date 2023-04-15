#include <iostream>
#include <vector>

// all special member functions
class str {
    std::string name;

 public:
    explicit str(std::string t_name = ""): name(t_name) {
        std::cout << name << " Construct" << '\n';
    }

    ~str() {
        std::cout << name << " Destructor" << '\n';
    }

    str(const str& other) {
        name = "copied " + other.name;
        std::cout << name << " Copy Construct" << '\n';
    }

    str(str&& other) {
        name = other.name;
        other.name = "Moved " + other.name;
        std::cout << name << " Move construct" << '\n';
    }

    str& operator=(const str& other) {
        name = "assigned " + other.name;
        std::cout << name << " Copy assignment" << '\n';
        return *this;
    }

    str& operator=(str&& other) {
        name = "swapped " + name;
        std::swap(name , other.name);
        std::cout << name << " Move assignment" << '\n';
        return *this;
    }
};

int main(int argc, char **argv) {
    std::cout << "Hello world" << '\n';
    std::cout << "-----------" << '\n';

    {
        str obj{"zero"};
    }
    std::cout << "-----------" << '\n';

    {
        std::vector<str> vec;
        vec.push_back(str("one"));
    }
    std::cout << "-----------" << '\n';

    {
        std::vector<str> vec;
        vec.emplace_back("two");
    }
    std::cout << "-----------" << '\n';

    {
        str obj1{"three"};
        str obj2{obj1};
        str obj3;
        obj3 = obj1;
    }
    std::cout << "-----------" << '\n';

    return 0;
}
