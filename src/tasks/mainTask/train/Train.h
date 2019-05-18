#ifndef TRAIN_H
#define TRAIN_H
#include "../../../modules/basic/matrix/Matrix.h"

using namespace std;

class Matrix;

class Train {
    public: 
        Train();
        ~Train();
        Matrix** execute(int ndig_train, int p, string* text);
};

#endif