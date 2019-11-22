#include <iostream>

#include "NeuralNetwork.hpp"

int main() {
    NeuralNetworkProperty property;

    property.n_input    = 2;
    property.n_output   = 3;

    property.n_h_layers = 2;
    int n_hidden[] = {2, 1};

    property.n_hidden = std::vector<int>(n_hidden,
                                         n_hidden + sizeof(n_hidden) / sizeof(int));

    property.aType_h = Neuron::SIGM;
    property.aType_o = Neuron::SIGM;
    property.costFType = 1; // NeuralNetwok.h define

    property.bias = 1;
    property.learningRate = 0.01;
    property.momentum = 1;

    property.init();

    NeuralNetwork network = NeuralNetwork(property);

    double _in[] = {0.5, 0.3};
    double _out[] = {0.3, 0.4, 0.7};

    std::vector<double> in = std::vector<double>(_in, _in + sizeof(_in) / sizeof(double));
    std::vector<double> out = std::vector<double>(_out, _out + sizeof(_out) / sizeof(double));

    LOG_V("% .5f", in);
    LOG_V("% .5f", out);

    for(int i = 0; i < 1000; i ++) {
        //network.Log();

        network.train(in, out);

        //LOG_V("%.3f", network.getActivatedVals(3));

        printf("\t\terror:%f\n", network.error);
    }

    return 0;
}
