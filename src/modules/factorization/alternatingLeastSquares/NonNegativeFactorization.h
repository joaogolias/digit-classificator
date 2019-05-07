#ifndef NONNEGATIVEFACTORIZATION_H
#define NONNEGATIVEFACTORIZATION_H

#include "../../basic/matrix/Matrix.h"
#include <iostream>

class Matrix;

class NonNegativeFactorization {
    Matrix* W;
    public:
        NonNegativeFactorization(Matrix* W);
        
        void normalize(Matrix* M);
        void generate();
        void handleNegativeValues(Matrix* M);

        ~NonNegativeFactorization();

        Matrix* execute(Matrix* A);

    private:
        double calculateS(Matrix *M, int column);
        double calculateC(double wi, double wj);
        double calculateError(Matrix* A, Matrix* W, Matrix* H);

};

#endif