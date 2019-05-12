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

void ImageProcessor::normalize(Matrix* image){
    image = image->mutiplyByConstant(1/(255.0));
    // for(int i = 0; i < image->rows; i++) {
    //     for(int j = 0 ; j < image->columns; j++) {
    //         image->set(i,j, (image->at(i,j)/(255.0)));
    //     }
    // }
}

void ImageProcessor::unnormalize(Matrix* image){
    image = image->mutiplyByConstant(255.0);
    // for(int i = 0; i < image->rows; i++) {
    //     for(int j = 0 ; j < image->columns; j++) {
    //         image->set(i,j, (image->at(i,j)/(255.0)));
    //     }
    // }
}
