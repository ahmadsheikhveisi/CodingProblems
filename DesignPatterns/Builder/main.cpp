


#include <string>
#include <iostream>
#include <memory>

class Pizza {
 public:
    void setDough(const std::string& dough) {
        m_dough = dough;
    }
    void setSauce(const std::string& sause) {
        m_sause = sause;
    }
    void setTopping(const std::string& topping) {
        m_topping = topping;
    }
    void open() const {
        std::cout << "Pizza with " << m_dough << " dough, " << m_sause <<
        " sause and " << m_topping << " topping.\n";
    }
 private:
    std::string m_dough{"No dough"};
    std::string m_sause{"No sause"};
    std::string m_topping{"No topping"};
};

// Abstract Builder
class PizzaBuilder {
 public:
    virtual ~PizzaBuilder() = default;
    Pizza* getPizza() {
        return m_pizza.release();
    }
    void createNewPizzaProduct() {
        m_pizza = std::make_unique<Pizza>();
    }
    virtual void buildDough() = 0;
    virtual void buildSause() = 0;
    virtual void buildTopping() = 0;
 protected:
    std::unique_ptr<Pizza> m_pizza;
};

class HawaiianPizzaBuilder : public PizzaBuilder {
 public:
    virtual ~HawaiianPizzaBuilder() override = default;
    void buildDough() override {
        m_pizza->setDough("Hawaiian dough");
    }
    void buildSause() override {
        m_pizza->setSauce("Hawaiian sause");
    }
    void buildTopping() override {
        m_pizza->setTopping("Hawaiian topping");
    }
};

class SpicyPizzaBuilder : public PizzaBuilder {
 public:
    ~SpicyPizzaBuilder() override = default;
    void buildDough() override {
        m_pizza->setDough("Spicy dough");
    }
    void buildSause() override {
        m_pizza->setSauce("Spicy sauce");
    }
    void buildTopping() override {
        m_pizza->setTopping("Spicy topping");
    }
};

class Cook {
 public:
    void openPizza() const {
        m_pizzaBuilder->getPizza()->open();
    }

    void createPizza(PizzaBuilder* pizzaBuilder) {
        m_pizzaBuilder = pizzaBuilder;
        m_pizzaBuilder->createNewPizzaProduct();
        m_pizzaBuilder->buildDough();
        m_pizzaBuilder->buildSause();
        m_pizzaBuilder->buildTopping();
    }
 private:
    PizzaBuilder* m_pizzaBuilder;
};


int main() {
    Cook cook{};
    HawaiianPizzaBuilder hawaiianPizzeBuilder;
    cook.createPizza(&hawaiianPizzeBuilder);
    cook.openPizza();
    return 0;
}