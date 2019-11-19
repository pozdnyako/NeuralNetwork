#include <iostream>

#include "NeuralNetwork.h"

int main() {
    Neuron *n = new Neuron(0.1, 1);

    return 0;
    NeuralNetworkProperty property;

    property.n_input    = 2;
    property.n_output   = 2;

    property.n_h_layers = 1;
    int n_hidden[] = {2};

    property.n_hidden = std::vector<int>(n_hidden,
                                         n_hidden + sizeof(n_hidden) / sizeof(int));

    property.aType_h = 3;//Neuron::SIGM;
    property.aType_o = 3;//Neuron::SIGM;
    property.costFType = 1; // NeuralNetwok.h define

    property.bias = 1;
    property.learningRate = 0.05;
    property.momentum = 1;

    property.init();

    property.Log();

    NeuralNetwork network = NeuralNetwork(property);

    network.Log();

    double _in[] = {0.5, 0.3};
    double _out[] = {0.3, 0.5};

    std::vector<double> in = std::vector<double>(_in, _in + sizeof(_in) / sizeof(double));
    std::vector<double> out = std::vector<double>(_out, _out + sizeof(_out) / sizeof(double));

    LOG_V("% .5f", in);
    LOG_V("% .5f", out);

    for(int i = 0; i < 1; i ++) {
        network.train(in, out);
        //network.getWeight(0)->Log();
        //network.getWeight(1)->Log();

        //LOG_V("% .5f", network.getActivatedVals(1));
        //LOG_V("% .5f", network.getActivatedVals(2));
        //LOG()

        //printf("\t\terror:%lf\n", network.error);
    }

    return 0;
}
