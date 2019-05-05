#ifndef MATRIXGENERATOR_H
#define MATRIXGENERATOR_H

#include "../../modules/basic/matrix/Matrix.h"

class Matrix;

class MatrixGenerator {
    public: 
        static Matrix* identity(int dimension);
        static Matrix* ones(int rows, int columns);
        static Matrix* zeros(int rows, int columns);
};

#endif