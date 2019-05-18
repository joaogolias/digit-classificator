#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H
#include "../basic/matrix/Matrix.h"

class Matrix;

class ImageProcessor {
    public: 
        ImageProcessor();
        ~ImageProcessor();

        Matrix* generateVector(Matrix* image);
        Matrix* regenerateMatrix(Matrix* vector, int rows, int columns);
        Matrix* joinVectors(Matrix** vectors, int vectorsQuantity, bool normalize = false);

        Matrix** splitVectors(Matrix* matrixOfVectors);

        void normalize(Matrix* image);
        void unnormalize(Matrix* image);

        //rows and columns must not be 0 if reverse is true!
        Matrix* execute(Matrix** images, int imageQuantity, bool reverse = false, int rows = 0, int columns = 0);
        Matrix** reverse(Matrix* A, int rows, int columns, int p);
};

#endif