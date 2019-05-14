#ifndef CLASSIFICATOR_H
#define CLASSIFICATOR_H
#include "../basic/matrix/Matrix.h"

class Matrix;

class Classificator {
    public:
        Classificator();
        ~Classificator();
        Matrix* classificate(Matrix* digitTrain, Matrix *image);
};

#endif