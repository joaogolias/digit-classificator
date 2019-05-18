#ifndef LEARNING_H
#define LEARNING_H
#include "../basic/matrix/Matrix.h"

class Matrix;

class Learning {
    public: 
        Learning();
        ~Learning();
        Matrix* execute(Matrix* A, int imageQuantity, int p);
        Matrix** getImages(Matrix* W, int rows, int columns, int p);
};

#endif
