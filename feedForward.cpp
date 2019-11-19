#include "NeuralNetwork.hpp"

void NeuralNetwork :: feedForward() {
    Matrix *a;
    Matrix *b;
    Matrix *c;

    for(int i = 0; i < property.n_layers - 1; i++) {
        a = getVals(i);     // 1 x Size

        b = getWeight(i);   // Size x nxtSize

        c = new Matrix(a->getNumRows(),
                       b->getNumCols());
        if(i != 0) {
            delete a;
            a = this->getDerived(i);
        }

        multiplyMatrix(a, b, c);

        for(int id = 0; id < c->getNumCols(); id ++) {
            setNeuronVal(i + 1, id, c->getValue(0, id) + property.bias);
        }

        delete a;
        delete b;
        delete c;
    }
}
