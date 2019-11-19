#include "Debug.h"
#include "Neuron.h"
#include <iostream>
#include <cmath>

Neuron :: Neuron(double _val, int _activationType) {
    val = 0.0123123;
    activated_val = -0.00123124;
    derived_val = -0.000123213;

    printf("%lf %lf %lf %d %lf %d\n", val, activated_val, derived_val, activationType, _val, _activationType);

    //LOG("\tn: %d %lf", _activationType, _val);

    this->activationType = _activationType;
    setVal(_val);
    //LOG("\tn: %d %lf\n", activationType, val);
}

void Neuron :: setVal(double _val) {
    val = _val;
    //activate();
    //derive();
}

void Neuron :: activate() {
    activated_val = 1 / (1 + exp(-val));

    /*
    #define FUNC(name, num, a_code, d_code) \
        case num:\
            a_code\
            break;
    switch(activationType) {
        #include "funcs.h"
    default:
        ERROR("activate: WRONG ACTIVATION FUNC")
        LOG("%d", activationType)
        break;
    }
    #undef FUNC
    */
}

void Neuron :: derive() {
    derived_val = activated_val * (1 - activated_val);
    /*
    #define FUNC(name, num, a_code, d_code) \
        case num:\
            d_code\
            break;
    switch(activationType) {
        #include "funcs.h"
    default:
        ERROR("derive: WRONG ACTIVATION FUNC")

        break;
    }
    #undef FUNC
    */
}


void Neuron :: Log() {
    LOG("val: %lf, aT: %d", val, activationType);
}
