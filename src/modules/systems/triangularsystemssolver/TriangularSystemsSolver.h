#ifndef TRIANGULARSYSTEMSSOLVER_H
#define TRIANGULARSYSTEMSSOLVER_H
#include "../../basic/matrix/Matrix.h"

class Matrix;

class TriangularSystemsSolver {
    public:
        TriangularSystemsSolver();
        ~TriangularSystemsSolver();
        Matrix* solveOneSystem(Matrix*W, Matrix*b);
        Matrix* solveSystems(Matrix*W, Matrix*A, bool handleNegativeValues = false);
    private: 
        bool isTriangularSystem(Matrix*W);
        bool areValidArguments(Matrix* W, Matrix*b);
};

#endif