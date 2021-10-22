/* COPYRIGHT shape class
 * This file implements shapes.
 * 
*/

#include <iostream>

#include "shapes.hpp"

template<typename T1, typename T2> void compare(T1 obj1, T2 obj2) {
    if (obj1 == obj2) {
        std::cout << "These are equal." << '\n';
    }
    if (obj1 > obj2) {
        std::cout << "Obj1 is bigger than obj2." << '\n';
    }
    if (obj1 < obj2) {
        std::cout << "Obj1 is smaller than obj2." << '\n';
    }
}


int main() {
    Triangle trg(50, 70);
    Circle crc(2);
    Rectangle rct(50, 70);
    compare(trg, crc);
    compare(rct, crc);
    compare(trg, rct);
    compare(1, 3.14f);
    compare(1, 1.0f);
    return 0;
}
