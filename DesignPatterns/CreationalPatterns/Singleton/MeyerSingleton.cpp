
#include "MeyerSingleton.hpp"

#include <iostream>

class MeyerSingleton::imple {
 public:
    int& getValue() {
        return m_value;
    }
    imple() : m_value(0) {
        std::cout << "Imple construct\n";
    }
    ~imple() {
        std::cout << "Imple destructor\n";
    }
 private:
    int m_value;
    imple(const imple&) = delete;
    imple& operator=(const imple&) = delete;
};
// to optimize the pimpl, we cached the reference
MeyerSingleton::MeyerSingleton() : cachedImple(SingletonImple()) {}

int& MeyerSingleton::get() {
    // return SingletonImple().getValue();
    return cachedImple.getValue();
}
/*Just like file-static objects, only one instance of
the static object exists in the entire program. Unlike the file static objects, the function static
objects are initialized the first time they are used;
every call to Singleton::instance() must check whether the object is
already initialized.
static objects are initialized in a thread-safe manner.*/
MeyerSingleton::imple& MeyerSingleton::SingletonImple() {
    static imple singletonImle;  // this is lazy intialization
    return singletonImle;

    // leaky variant, no delete. this makes sure the destruction order.
    // static imple* singletonImple{new imple()};
    // return *singletonImple;
}

