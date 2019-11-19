#include <iostream>

#include "NeuralNetwork.hpp"

class A {
public:
    A(int b);
};

A :: A(int b) {
    printf("b: %d\n", b);
}

int main() {
    NeuralNetworkProperty property;

    property.n_input    = 2;
    property.n_output   = 3;

    property.n_h_layers = 1;
    int n_hidden[] = {2};

    property.n_hidden = std::vector<int>(n_hidden,
                                         n_hidden + sizeof(n_hidden) / sizeof(int));

    property.aType_h = Neuron::SIGM;
    property.aType_o = Neuron::SIGM;
    property.costFType = 1; // NeuralNetwok.h define

    property.bias = 1;
    property.learningRate = 0.05;
    property.momentum = 1;

    property.init();

    NeuralNetwork network = NeuralNetwork(property);

    network.Log();

    double _in[] = {0.5, 0.3};
    double _out[] = {0.3, 0.5, 0.4};

    std::vector<double> in = std::vector<double>(_in, _in + sizeof(_in) / sizeof(double));
    std::vector<double> out = std::vector<double>(_out, _out + sizeof(_out) / sizeof(double));

    LOG_V("% .5f", in);
    LOG_V("% .5f", out);

    for(int i = 0; i < 10000; i ++) {
        network.train(in, out);
        printf("\t\terror:%f\n", network.error);
    }

    return 0;
}
