#include "Debug.hpp"
#include "Matrix.hpp"

Matrix :: Matrix(int numRows, int numCols, bool isRandom) {
    this->numRows = numRows;
    this->numCols = numCols;

    for(int r = 0; r < numRows; r ++) {
        std::vector<double> row;

        for(int c = 0; c < numCols; c ++) {
            double v = 0.0;
            if(isRandom)
                v = getRandomNumber();

            row.push_back(v);
        }

        this->values.push_back(row);
    }
}

Matrix* Matrix::transpose() {
    Matrix *m = new Matrix(this->numCols, this->numRows);

    for(int r = 0; r < this->numCols; r ++) {
    for(int c = 0; c < this->numRows; c ++) {
        m->setValue(r, c, this->getValue(c, r));
    }}

    return m;
}

Matrix* Matrix :: copy() {
    Matrix *m = new Matrix(this->numRows, this->numCols);

    for(int r = 0; r < this->numRows; r ++) {
    for(int c = 0; c < this->numCols; c ++) {
        m->setValue(r, c, this->getValue(r, c));
    }}

    return m;
}

void Matrix :: Log() {
    LOG("%dx%d", numRows, numCols)
    pTAB
    for(int i = 0; i < numRows; i ++) {
        LOG_V("% .7f ", values[i])
    }
    mTAB
}

#include <cstdlib>

double Matrix :: getRandomNumber() {
    double res = (double) rand() / RAND_MAX * (2 * RANGE_SIZE) - RANGE_SIZE;
    return res;
}

void multiplyMatrix(Matrix *a, Matrix *b, Matrix *c) { // c = c + a * b
    if(a->getNumCols() != b->getNumRows()) {
        ERROR("a->NumCols != b->NumRows")
        a->Log();
        b->Log();
    }
    for(int i = 0; i < a->getNumRows(); i ++) {
    for(int j = 0; j < b->getNumCols(); j ++) {
        for(int k = 0; k < a->getNumCols(); k ++) {
            double newVal = c->getValue(i, j) +
                            a->getValue(i, k) * b->getValue(k , j);
            c->setValue(i, j, newVal);
        }
    }}
}
