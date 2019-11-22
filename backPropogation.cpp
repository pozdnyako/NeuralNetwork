#include "NeuralNetwork.hpp"
#include <algorithm>

void NeuralNetwork :: backPropogation() {
    std::vector<Matrix *> newWeights;

    Matrix *deltaWeights;
    Matrix *gradients;
    Matrix *derivedValues;
    Matrix *gradientsTransposed;
    Matrix *zActivatedVals;
    Matrix *tempNewWeights;
    Matrix *pGradients;
    Matrix *trasposedPWeights;
    Matrix *hiddenDerived;
    Matrix *transposedHidden;

    /// OUPUT TO LAST HIDDEN LAYER

    int outputLayerID = property.n_layers - 1;

    gradients = new Matrix(1, property.n_output);
    derivedValues = layers.at(outputLayerID)->derivedVals();

    for(int i = 0; i < property.n_output; i ++) {
        double e = derivedErrors.at(i);
        double y = derivedValues->getValue(0, i);

        double g = e * y;

        gradients->setValue(0, i, g);
    }

    // Gt * Z

    gradientsTransposed = gradients->transpose();
    zActivatedVals = layers.at(outputLayerID - 1)->activatedVals();

    deltaWeights = new Matrix(gradientsTransposed->getNumRows(),
                              zActivatedVals->getNumCols());

    multiplyMatrix(gradientsTransposed, zActivatedVals, deltaWeights);

    /// COMPUTE NEW WEIGHTS

    tempNewWeights = new Matrix(property.topology.at(outputLayerID - 1),
                                property.topology.at(outputLayerID));

    for(int r = 0; r < tempNewWeights->getNumRows(); r ++) {
    for(int c = 0; c < tempNewWeights->getNumCols(); c ++) {

        double originalValue = weights.at(outputLayerID - 1)->getValue(r, c);
        double deltaValue = deltaWeights->getValue(c, r);

        originalValue *= property.momentum;
        deltaValue *= property.learningRate;

        tempNewWeights->setValue(r, c, (originalValue - deltaValue));
    }}

    newWeights.push_back(new Matrix(*tempNewWeights));

    delete gradientsTransposed;
    delete zActivatedVals;
    delete tempNewWeights;
    delete deltaWeights;
    delete derivedValues;

    /// OTHER LAYERS

    for(int i = outputLayerID - 1; i > 0; i --) {
        //gradients->Log();

        pGradients = new Matrix(*gradients);
        delete gradients;

        trasposedPWeights = weights.at(i)->transpose();

        gradients = new Matrix(1, trasposedPWeights->getNumCols());


        //LOG("pG: %dx%d", pGradients->getNumRows(), pGradients->getNumCols());
        //LOG("g: %dx%d", gradients->getNumRows(), gradients->getNumCols());
        //LOG("tpW: %dx%d", trasposedPWeights->getNumRows(), trasposedPWeights->getNumCols());


        multiplyMatrix(pGradients, trasposedPWeights, gradients);

        hiddenDerived = layers.at(i)->derivedVals();

        //LOG("hD: %dx%d",hiddenDerived->getNumRows(), hiddenDerived->getNumCols());

        for(int col = 0; col < hiddenDerived->getNumRows(); col ++ ){
            double g = gradients->getValue(0, col) * hiddenDerived->getValue(0, col);
            gradients->setValue(0, col, g);
        }

        /// COMPUTE NEW WEIGHTS

        zActivatedVals = layers.at(i-1)->activatedVals();

        transposedHidden = zActivatedVals->transpose();

        //LOG("tH: %dx%d",transposedHidden->getNumRows(), transposedHidden->getNumCols());
        //LOG("g: %dx%d", gradients->getNumRows(), gradients->getNumCols());

        deltaWeights = new Matrix(transposedHidden->getNumRows(), gradients->getNumCols());

        multiplyMatrix(transposedHidden, gradients, deltaWeights);

        tempNewWeights = new Matrix(weights.at(i - 1)->getNumRows(),
                                    weights.at(i - 1)->getNumCols());

        //LOG("nW: %dx%d", tempNewWeights->getNumRows(), tempNewWeights->getNumCols());
        //LOG("dW: %dx%d", deltaWeights->getNumRows(), deltaWeights->getNumCols());

        for(int r = 0; r < tempNewWeights->getNumRows(); r ++) {
            for(int c = 0; c <tempNewWeights->getNumCols(); c ++) {
                double originalValue = weights.at(i - 1)->getValue(r, c);
                double deltaValue = deltaWeights->getValue(r, c);

                originalValue *= property.momentum;
                deltaValue *= property.learningRate;

                tempNewWeights->setValue(r, c, (originalValue - deltaValue));
            }
        }

        newWeights.push_back(new Matrix(*tempNewWeights));

        delete pGradients;
        delete trasposedPWeights;
        delete hiddenDerived;
        delete zActivatedVals;
        delete transposedHidden;
        delete tempNewWeights;
        delete deltaWeights;
    }
    delete gradients;

    for(int i = 0; i < this->weights.size(); i++) {
        delete weights[i];
    }

    weights.clear();

    reverse(newWeights.begin(), newWeights.end());

    for(int i = 0; i < newWeights.size(); i ++) {
        weights.push_back(new Matrix(*newWeights.at(i)));
        delete newWeights[i];
    }

    //LOG("\n")
}

/*Matrix* NeuralNetwork :: generateOutputDelta() {
    int layerID = property.n_layers - 1;
    Matrix *delta = new Matrix(1, property.topology.at(LayerID));


}*/
