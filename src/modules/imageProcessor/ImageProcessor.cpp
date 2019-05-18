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

Matrix* ImageProcessor::regenerateMatrix(Matrix* vector, int rows, int columns){
    Matrix* M = new Matrix(rows, columns);

    for(int i = 0; i < rows; i ++) {
        for (int j = 0; j < columns; j++){
            M->set(i,j, vector->at(i + rows*j,0));
        }
    }

    return M->transpose();
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
    cout << "finish split" << endl;
    return vectors;
}


void ImageProcessor::normalize(Matrix* image){
    image = image->mutiplyByConstant(1/(255.0));
}

void ImageProcessor::unnormalize(Matrix* image){
    image = image->mutiplyByConstant(255.0);
}

Matrix* ImageProcessor::execute(Matrix** images, int imageQuantity, bool reverse, int rows, int columns) {
    Matrix** vectors = new Matrix*[imageQuantity];
    for(int k = 0; k < imageQuantity; k++) {
        Matrix* image = images[k];

        Matrix* vector = generateVector(image);
        vectors[k] = vector;

        // cout << "v" << k+1 << ": " << endl;
        // vector->print();
    }

    // cout << endl << "Matrix A" << endl;
    Matrix* A = joinVectors(vectors, imageQuantity);
    // A->print();

    // cout << endl << "Normalized Matrix A" << endl;
    normalize(A);
    // A->print();
    if(reverse && rows !=0 && columns != 0) { 
        this->reverse(A, rows, columns, imageQuantity);
    }
    return A;
}

Matrix** ImageProcessor::reverse(Matrix* A, int rows, int columns, int p){
    // unnormalize(A);

    Matrix** matrixes = new Matrix*[A->columns];
    Matrix** vectors = splitVectors(A);
    for(int l = 0 ; l < p; l++) {
        
        Matrix* reversedMatrix = regenerateMatrix(vectors[l], rows, columns);

        matrixes[l] = reversedMatrix;
    }

    return matrixes;
}
