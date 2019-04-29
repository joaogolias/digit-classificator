#ifndef TRIANGULARSYSTEMSSOLVER_H
#define TRIANGULARSYSTEMSSOLVER_H
#include "../../basic/matrix/Matrix.h"

class Matrix;

class TriangularSystemsSolver {
    Matrix *W;
    Matrix *b;
    public:
        TriangularSystemsSolver();
        ~TriangularSystemsSolver();
        Matrix* solveSystem(Matrix*W, Matrix*b);
    private: 
        bool isTriangularSystem();
        bool areValidArguments();
};

#endif