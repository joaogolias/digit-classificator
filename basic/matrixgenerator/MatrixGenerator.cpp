#include <iostream>
#include "MatrixGenerator.h"
#include "../matrix/Matrix.h"

Matrix* MatrixGenerator::identity(int dimension) {
    Matrix* matrix = new Matrix(dimension, dimension);
    for(int i = 0; i<dimension; i++) {
        for (int j = 0; j<dimension; j++) {
            if(i == j) matrix->set(i,j,1.0);
            else matrix->set(i,j,0.0);
        }
    }
    return matrix;
}

Matrix* MatrixGenerator::zeros(int rows, int columns) {
    Matrix* matrix = new Matrix(rows, columns);
    for(int i = 0; i<rows; i++) {
        for (int j = 0; j<columns; j++) {
            matrix->set(i,j,0.0);
        }
    }
    return matrix;
}

Matrix* MatrixGenerator::ones(int rows, int columns) {
    Matrix* matrix = new Matrix(rows, columns);
    for(int i = 0; i<rows; i++) {
        for (int j = 0; j<columns; j++) {
            matrix->set(i,j,1.0);
        }
    }
    return matrix;
}
