#ifndef NEURALNETWORK_H_INCLUDED
#define NEURALNETWORK_H_INCLUDED

#include "Layer.hpp"

#define COST_MSE 1

class NeuralNetworkProperty {
public:
    NeuralNetworkProperty(){};

    int n_layers;
    int n_h_layers;
    std::vector<int> n_hidden;

    std::vector<int> topology;

    int aType_h;
    int aType_o;
    int costFType;

    int n_input;
    int n_output;

    double bias;
    double learningRate;
    double momentum;

    void init();
    bool isOk();
    void Log();
};

class NeuralNetwork {
public:
    NeuralNetwork(NeuralNetworkProperty property);
    // Setter
    void setCurrentInput(std::vector<double> input);
    void setCurrentTarget(std::vector<double> target) {this->target = target; }
    void setNeuronVal(int layerID, int neuronID, double val) {layers.at(layerID)->setVal(neuronID, val); }

    //Getter
    std::vector<double> getActivatedVals(int layerID) {return this->layers.at(layerID)->getActivatedVals(); }
    Matrix *getVals(int layerID) {return this->layers.at(layerID)->vals(); }
    Matrix *getActivated(int layerID) {return this->layers.at(layerID)->activatedVals(); }
    Matrix *getDerived(int layerID) {return this->layers.at(layerID)->derivedVals(); }
    Matrix* getWeight(int layerID) { return new Matrix(*weights.at(layerID));}

    // Core methods
    void feedForward();
    void backPropogation();
    void setErrors();
    void train(std::vector<double> input,
               std::vector<double> target);

    void Log();

    void setErrorsMSE();

    NeuralNetworkProperty property;

    std::vector<Layer*> layers;
    std::vector<Matrix*> weights;
    std::vector<Matrix*> gradients;

    std::vector<double> input;
    std::vector<double> target;
    std::vector<double> errors;
    std::vector<double> derivedErrors;

    double error;
private:
};

#endif // NEURALNETWORK_H_INCLUDED
