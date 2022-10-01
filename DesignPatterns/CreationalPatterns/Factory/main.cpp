

#include <string>
#include <iostream>
#include <memory>

class Vehicle {
 public:
    virtual void printVehicle() = 0;
};

class TwoWheeler : public Vehicle {
 public:
    void printVehicle() {
        std::cout << "Two wheeler\n";
    }
};

class FourWheeler : public Vehicle {
 public:
    void printVehicle() {
        std::cout << "Four Wheeler\n";
    }
};

class Client {
 public:
    std::unique_ptr<Vehicle> CreateClient(int type) {
        if (type == 1) {
            return std::make_unique<TwoWheeler>();
        } else if (type == 2) {
            return std::make_unique<FourWheeler>();
        } else {
            return nullptr;
        }
    }

 private:
    std::unique_ptr<Vehicle> pVehicle;
};

int main() {
    return 0;
}