
#include <iostream>

#include "SimpleAdapter.hpp"


int main() {
    std::cout << "Adaptor\n";
    {
        SimpleAdapter::Target target;
        SimpleAdapter::ClientCode(target);

        SimpleAdapter::Adaptee adaptee;
        // ClientCode(adaptee) this won't compile
        SimpleAdapter::Adapter adapter(adaptee);
        SimpleAdapter::ClientCode(adapter);

        SimpleAdapter::MultipleInheritenceAdapter MIAdapter;
        SimpleAdapter::ClientCode(MIAdapter);
    }

    return 0;
}
