#ifndef NEURON_H_INCLUDED
#define NEURON_H_INCLUDED

#include "Debug.hpp"
#include <cstdio>
#include <vector>

class Neuron{
public:
    Neuron() {printf("zz");}
    Neuron(int);
    Neuron(double _val, int _activationType);

    static const int SIGM = 3;
/*
    #define FUNC(name, num, code1, code2_)\
    static const int name = num;
    #include "funcs.hpp"
    #undef FUNC
*/
    void activate();
    void derive();

    // Setters
    void setVal(double v);

    // Getters
    double getVal() { return val; }
    double getActivatedVal() { return activated_val; }
    double getDerivedVal() { return derived_val; }

    void Log();
private:
    double val;

    double activated_val;
    double derived_val;

    int activationType;
};

#endif // NEURON_H_INCLUDED
