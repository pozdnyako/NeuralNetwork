#include "Debug.hpp"
#include "Neuron.hpp"
#include <iostream>
#include <cmath>

Neuron :: Neuron(double _val, int _activationType) {
    activationType = _activationType;
    setVal(_val);
}

Neuron :: Neuron(int a) {
    printf("a: %d", a);
}

void Neuron :: setVal(double _val) {
    val = _val;
    activate();
    derive();
}

void Neuron :: activate() {
    #define FUNC(name, num, a_code, d_code) \
        case num:\
            a_code\
            break;
    switch(activationType) {
        #include "funcs.hpp"
    default:
        ERROR("activate: WRONG ACTIVATION FUNC")
        LOG("%d", activationType)
        break;
    }
    #undef FUNC
}

void Neuron :: derive() {
    #define FUNC(name, num, a_code, d_code) \
        case num:\
            d_code\
            break;
    switch(activationType) {
        #include "funcs.hpp"
    default:
        ERROR("derive: WRONG ACTIVATION FUNC")

        break;
    }
    #undef FUNC
}


void Neuron :: Log() {
    LOG("val: %f, aT: %d", val, activationType);
}
