#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Op : public Base {
public:
    Op(double value) : Base() { number = value; }
    virtual double evaluate() { return number; }
    virtual std::string stringify() { return std::to_string(number); }
    
private:
    double number;
};

#endif //__OP_HPP__
