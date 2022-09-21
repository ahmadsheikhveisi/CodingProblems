#ifndef prototype_hpp
#define prototype_hpp

#include <memory>

class prototype {
 public:
    virtual ~prototype() = default;
	virtual void print() = 0;
	virtual std::unique_ptr<prototype> clone() = 0;
};

#endif
