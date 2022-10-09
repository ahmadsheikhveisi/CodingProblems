
#ifndef DESIGNPATTERNS_STRUCTURALPATTERNS_DECORATOR_CRTPWRAPPER_HPP_
#define DESIGNPATTERNS_STRUCTURALPATTERNS_DECORATOR_CRTPWRAPPER_HPP_

#include <iostream>
#include <typeinfo>

class Unit {
 public:
    Unit(double strength, double armor) : m_stregth(strength), m_armor(armor) {}
    virtual bool hit(Unit& target) {
        return attack() > target.defense();
    }
    virtual double attack() = 0;
    virtual double defense() = 0;

 protected:
    double m_stregth;
    double m_armor;
};

class Knight : public Unit {
 public:
    Knight(double stregth, double armor) : Unit(stregth, armor),
    m_charge_bonus(0) {}

    double attack() {
        double res{m_stregth + m_sword_bonus + m_charge_bonus};
        m_charge_bonus = 0;
        return res;
    }
    double defense() {
        return m_armor + m_plate_bonus;
    }
    void charge() {
        m_charge_bonus = 1;
    }

 protected:
    double m_charge_bonus;
    static constexpr double m_sword_bonus{2};
    static constexpr double m_plate_bonus{3};
};

class Ogre : public Unit {
 public:
    using Unit::Unit;  // just using it!!!!
    double attack() {
        return m_stregth + m_club_penalty;
    }
    double defense() {
        return m_armor + m_leather_penalty;
    }
 protected:
    static constexpr double m_club_penalty{-1};
    static constexpr double m_leather_penalty{-1};
};

class Troll : public Unit {
 public:
    using Unit::Unit;
    double attack() {
        return m_stregth + m_mace_bonus;
    }
    double defense() {
        return m_armor + m_hide_bonus;
    }
 protected:
    static constexpr double m_mace_bonus{3};
    static constexpr double m_hide_bonus{8};
};

// this decorator has access to the concrete units method.
// also it takes ownership of the concrete unit.
// however, caller needs to transfer the ownership, i.e. calling std::move
template<typename U>
class VeteranUnit : public U {
 public:
    VeteranUnit(U&& unit, double strength_bonus, double armor_bonus) :
    U(unit), m_armor_bonus(armor_bonus), m_strength_bonus(strength_bonus) {}
    double attack() {
        return U::attack() + m_strength_bonus;
    }
    double defense() {
        return U::defense() + m_armor_bonus;
    }
 protected:
    double m_strength_bonus;
    double m_armor_bonus;
};

#endif  // DESIGNPATTERNS_STRUCTURALPATTERNS_DECORATOR_CRTPWRAPPER_HPP_
