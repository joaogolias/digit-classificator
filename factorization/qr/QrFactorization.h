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
        double calculateTau(bool isWiGreatest, double wj, double wi);
        double calculateS(bool isWiGreatest, double c, double tau);
        double calculateC(bool isWiGreatest, double s, double tau);

};

#endif