#include "Debug.hpp"
#include "Layer.hpp"

Layer :: Layer(int _size, int _activationType) {
    size = _size;
    for(int j = 0; j < _size; j ++) {
        Neuron *n = new Neuron(0.0, _activationType);
        this->neurons.push_back(n);
    }
}

void Layer :: setVal(int n, double v) {
    neurons.at(n)->setVal(v);
}

std::vector<double> Layer :: getActivatedVals() {
    std::vector<double> res;

    for(int i = 0; i < (int)neurons.size(); i++) {
        res.push_back(neurons.at(i)->getActivatedVal());
    }

    return res;
}

Matrix* Layer :: vals() {
    Matrix *m = new Matrix(1, this->neurons.size());

    for(int i = 0; i < this->neurons.size(); i ++) {
        m->setValue(0, i, this->neurons.at(i)->getVal());
    }

    return m;
}

Matrix* Layer :: activatedVals() {
    Matrix *m = new Matrix(1, this->neurons.size());

    for(int i = 0; i < this->neurons.size(); i ++) {
        m->setValue(0, i, this->neurons.at(i)->getActivatedVal());
    }

    return m;
}

Matrix* Layer :: derivedVals() {
    Matrix *m = new Matrix(1, this->neurons.size());

    for(int i = 0; i < this->neurons.size(); i ++) {
        m->setValue(0, i, this->neurons.at(i)->getDerivedVal());
    }

    return m;
}

void Layer :: Log() {
    LOG("layer from %d neurons:", neurons.size())
     // FULL LOG
    pTAB
    for(int i = 0; i < neurons.size(); i ++) {
        neurons.at(i)->Log();
    }
    mTAB

}
