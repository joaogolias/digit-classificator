#ifndef QRFACTORIZARION_H
#define QRFACTORIZARION_H

#include "../../basic/matrix/Matrix.h"
#include <iostream>

class Matrix;

class QrFactorization {
    public:
        QrFactorization();
        ~QrFactorization();

        void Q(Matrix* W, double i, double j, double k, double c, double s);

        Matrix* executeForOneSystem(Matrix* W, Matrix *b);
        Matrix* execute(Matrix* W, Matrix *A);

    private: 
        double calculateS(double wi, double wj);
        double calculateC(double wi, double wj);
};

#endif