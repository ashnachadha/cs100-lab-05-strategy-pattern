#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include <math.h>

class Pow : public Base {
public:
    Pow(Base* obj1, Base* obj2) : Base() {
        object1 = obj1;
        object2 = obj2;
    }
    
    virtual double evaluate() {
        return pow ( object1->evaluate() , object2->evaluate() );
    }
    
    virtual std::string stringify() { return object1->stringify() + " ** " + object2->stringify(); }
    
private:
    Base* object1;
    Base* object2;
};

#endif //__POW_HPP__


