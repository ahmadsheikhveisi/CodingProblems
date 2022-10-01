
#ifndef DESIGNPATTERNS_CREATIONALPATTERNS_PROTOTYPE_PROTOTYPE_HPP_
#define DESIGNPATTERNS_CREATIONALPATTERNS_PROTOTYPE_PROTOTYPE_HPP_

#include <memory>

class prototype {
 public:
    virtual ~prototype() = default;
    virtual void print() = 0;
    virtual std::unique_ptr<prototype> clone() = 0;
};

#endif  // DESIGNPATTERNS_CREATIONALPATTERNS_PROTOTYPE_PROTOTYPE_HPP_
