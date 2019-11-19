#include "Debug.h"
#include "NeuralNetwork.h"

void NeuralNetworkProperty :: init() {
    n_layers = n_h_layers + 2;
    topology.push_back(n_input);
    for(int i = 0; i < n_hidden.size(); i ++) {
        topology.push_back(n_hidden.at(i));
    }
    topology.push_back(n_output);
}

bool NeuralNetworkProperty :: isOk() {
    if ((int) n_hidden.size() != n_h_layers) {
        ERROR("n_hidden.size != n_hidden.size()")
        Log();
    } else {
        return true;
    }
    return false;
}

void NeuralNetworkProperty :: Log() {
    LOG("Neural Netwok Property :")
    pTAB

    LOG("n layes: %d", n_layers)
    LOG("n_input: %d", n_input);
    LOG("n_output: %d", n_output);

    LOG("hidden %d layes :", n_h_layers)
    pTAB
    for(int i = 0; i < n_hidden.size(); i ++) {
        LOG("%d: %d", i, n_hidden.at(i))
    }
    mTAB

    LOG("topology :")
    pTAB
    for(int i = 0; i < topology.size(); i ++) {
        LOG("%d: %d", i, topology.at(i))
    }
    mTAB


    LOG("activation type in hidden layers: %d", aType_h);
    LOG("activation type in last layer: %d", aType_o);
    LOG("cost function type: %d", costFType);
    mTAB
}

NeuralNetwork :: NeuralNetwork(NeuralNetworkProperty property){

    this->property = property;

    property.isOk();

    for(int i = 0; i < property.n_layers; i ++) {
        if(i < property.n_layers - 1) {
            Layer *l = new Layer(property.topology.at(i), property.aType_h);
            layers.push_back(l);
            l->Log();
        } else {
            Layer *l = new Layer(property.topology.at(i), property.aType_o);
            layers.push_back(l);
            l->Log();
        }
    }

    for(int i = 0; i < property.n_layers - 1; i ++ ) {
        Matrix *weight = new Matrix(property.topology.at(i), property.topology.at(i+1), true);
        this->weights.push_back(weight);
    }

    input = std::vector<double>(property.n_input, 0.0);
    target = std::vector<double>(property.n_output, 0.0);
    errors = std::vector<double>(property.n_output, 0.0);
    derivedErrors = std::vector<double>(property.n_output, 0.0);

    error = 0.0;

    Log();
}

void NeuralNetwork :: setCurrentInput(std::vector<double> input) {
    if((int)input.size() != this->property.n_input) {
        ERROR("input size is incorrect");
    }

    this->input = input;

    for(int i = 0; i < (int)input.size(); i ++) {
        this->layers.at(0)->setVal(i, input.at(i));
    }
}

void NeuralNetwork :: train(std::vector<double> _input,
                            std::vector<double> _target) {
    Log();
    setCurrentInput(_input);
    Log();
    setCurrentTarget(_target);

    Log();
    feedForward();
    Log();
    setErrors();
    Log();
    backPropogation();
    Log();
}

void NeuralNetwork :: Log() {
    LOG("Neural Network");
    pTAB

    LOG("properties:")
    pTAB
    property.Log();
    mTAB

    LOG("%d layers:", layers.size())
    pTAB
    for(int i = 0; i < layers.size(); i ++) {
        layers[i]->Log();
    }
    mTAB

    LOG("%d weights:", weights.size())
    for(int i = 0; i < weights.size(); i ++) {
        weights[i]->Log();
    }

    mTAB
}


