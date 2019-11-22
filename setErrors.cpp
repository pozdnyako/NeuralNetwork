#include "NeuralNetwork.hpp"

void NeuralNetwork :: setErrors() {
    switch(property.costFType) {
        case(COST_MSE): setErrorsMSE(); break;
        default: setErrorsMSE(); break;
    }
}

#include <cmath>

void NeuralNetwork :: setErrorsMSE() {
    int outputLayerID = property.n_layers - 1;
    std::vector<Neuron *> outputNeurons = layers.at(outputLayerID)->getNeurons();

    error = 0.0;

    for(int i = 0; i < target.size(); i ++) {
        double t = target.at(i);
        double y = outputNeurons.at(i)->getActivatedVal();

        errors.at(i)        = 0.5 * (t - y) * (t - y);
        derivedErrors.at(i) = (y - t);

        error += errors.at(i);
    }

    //LOG_V("%f", errors);

    error = sqrt(2 * error) / (double)target.size();
}
