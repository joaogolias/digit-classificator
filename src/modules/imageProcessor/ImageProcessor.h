#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H
#include "../basic/matrix/Matrix.h"

class Matrix;

class ImageProcessor {
    public: 
        ImageProcessor();
        ~ImageProcessor();

        Matrix* generateVector(Matrix* image);
        Matrix* joinVectors(Matrix** vectors, int vectorsQuantity);
        
        void normalize(Matrix* image);
};

#endif