#ifndef LAYER_H_INCLUDED
#define LAYER_H_INCLUDED


#include "Matrix.hpp"
#include "Neuron.hpp"

class Layer {
public:
    Layer() {printf("--");};
    Layer(int _size, int _activationType);

    // Setter
    void setVal(int n, double v);
    void setNeuron(std::vector<Neuron *> neurons);

    //Getter
    std::vector<double> getActivatedVals();
    std::vector<Neuron *> getNeurons() { return neurons; }

    Matrix *vals();
    Matrix *activatedVals();
    Matrix *derivedVals();

    void Log();
private:
    int size;
    std::vector<Neuron*> neurons;
};

#endif // LAYER_H_INCLUDED
