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
    for(int j = 0; j < columns; j++) {
        for(int i = 0; i < rows; i++) {
            M->set(i,j,vector->at(j*rows + i,0));
        }
    }
    return M;
    // int rows = image->rows*image->columns;
    // Matrix* vector = new Matrix(rows, 1);

    // for(int j = 0; j < image->columns; j++) {
    //     for(int i = 0; i < image -> rows; i++) {
    //         vector->set(j*image->rows + i, 0, image->at(i,j));
    //     }
    // }
    // return vector;
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

void ImageProcessor::execute(Matrix** images, int imageQuantity, bool reverse, int rows, int columns) {
    Matrix** vectors = new Matrix*[imageQuantity];
    for(int k = 0; k < imageQuantity; k++) {
        Matrix* image = images[k];

        Matrix* vector = generateVector(image);
        vectors[k] = vector;

        cout << "v" << k+1 << ": " << endl;
        vector->print();
    }

    cout << endl << "Matrix A" << endl;
    Matrix* A = joinVectors(vectors, imageQuantity);
    A->print();

    cout << endl << "Normalized Matrix A" << endl;
    normalize(A);
    A->print();

    if(reverse) { 

        cout << endl << "Unnormalized Matrix A" << endl;
        unnormalize(A);
        A->print();

        Matrix** vectors = splitVectors(A);
        for(int l = 0 ; l < imageQuantity; l++) {
            cout << "v" << l+1 << ": " << endl;
            vectors[l]->print();

            Matrix* reversedMatrix = regenerateMatrix(vectors[l], rows, columns);
            cout << "Matrix" << l+1 << ": " << endl;
            reversedMatrix->print();
        }

        

    }
}
