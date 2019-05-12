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
        Matrix* joinVectors(Matrix** vectors, int vectorsQuantity);

        Matrix** splitVectors(Matrix* matrixOfVectors);

        void normalize(Matrix* image);
        void unnormalize(Matrix* image);
};

#endif