#ifndef QRFACTORIZARION_H
#define QRFACTORIZARION_H

#include "../../basic/matrix/Matrix.h"
#include <iostream>

class Matrix;

class QrFactorization {
    Matrix* W;
    public:
        QrFactorization(Matrix* W);
        
        void generate();
        void Q(Matrix* W, double i, double j, double k);

        ~QrFactorization();


        Matrix* execute();

    private: 
        double calculateS(double wi, double wj);
        double calculateC(double wi, double wj);

};

#endif