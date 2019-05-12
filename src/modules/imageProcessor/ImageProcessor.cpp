#include <iostream>
#include "ImageProcessor.h"

using namespace std;

ImageProcessor::ImageProcessor(){}
ImageProcessor::~ImageProcessor(){}
Matrix* ImageProcessor::generateVector(Matrix* image){
    int rows = image->rows*image->columns;
    Matrix* vector = new Matrix(rows, 1);

    for(int j = 0; j < image->columns; j++) {
        for(int i = 0; i < image -> rows; i++) {
            vector->set(j*image->rows + i, 0, image->at(i,j));
        }
    }
    return vector;
}

Matrix* ImageProcessor::joinVectors(Matrix** vectors, int vectorsQuantity){
    Matrix *result = new Matrix(vectors[0]->rows, vectorsQuantity);
    for(int i = 0; i < vectorsQuantity; i++) {
        for(int j = 0 ; j < result->rows; j++) {
            result->set(j,i, vectors[i]->at(j,0));
        }
    }
    return result;
}

Matrix** ImageProcessor::splitVectors(Matrix* matrixOfVectors){
    Matrix** vectors = new Matrix*[matrixOfVectors->columns];
    Matrix* vector;

    for(int j = 0 ; j < matrixOfVectors -> columns; j++) {
        vector = new Matrix(matrixOfVectors->rows, 1);
        for (int i = 0; i < matrixOfVectors->rows; i ++) {
            vector->set(i,0,matrixOfVectors->at(i,j));
        }
        vectors[j] = vector;
    }
    return vectors;
}


void ImageProcessor::normalize(Matrix* image){
    image = image->mutiplyByConstant(1/(255.0));
}

void ImageProcessor::unnormalize(Matrix* image){
    image = image->mutiplyByConstant(255.0);
}
