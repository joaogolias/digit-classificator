#ifndef NONNEGATIVEFACTORIZATION_H
#define NONNEGATIVEFACTORIZATION_H

#include "../../basic/matrix/Matrix.h"
#include <iostream>

class Matrix;

class NonNegativeFactorization {
    public:
        NonNegativeFactorization();
        ~NonNegativeFactorization();
        
        void normalize(Matrix* M);
        void handleNegativeValues(Matrix* M);


        int execute(Matrix* A, Matrix* W, Matrix* H);

        Matrix* getH();
        Matrix* getW();

    private:
        Matrix *Hresult;
        Matrix *Wresult;
        double calculateS(Matrix *M, int column);
        double calculateError(Matrix* A, Matrix* W, Matrix* H);

};

#endif