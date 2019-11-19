#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <iostream>
#include <vector>

class Matrix;

void multiplyMatrix(Matrix*, Matrix*, Matrix*);

class Matrix {
public:
    Matrix(int numRows, int numCols, bool isRandom = false);

    Matrix *transpose();
    Matrix *copy();

    void Log();

    // Setter
    void setValue(int r, int c, double v) {values.at(r).at(c) = v;}

    //Getter
    int getNumRows() { return this->numRows; }
    int getNumCols() { return this->numCols; }
    double getValue(int r, int c) {return this->values[r][c]; }

private:
    int numRows;
    int numCols;

    std::vector< std::vector<double> > values;

    const double RANGE_SIZE = 0.0001;
    double getRandomNumber();
};

#endif // MATRIX_H_INCLUDED
