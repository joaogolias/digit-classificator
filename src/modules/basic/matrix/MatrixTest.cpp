#include "./Matrix.h"
#include <iostream>
#include <stdexcept>
#include <math.h>

using namespace std;

void testVector();
void setMatrix();
void sumMatrix();
void subtractMatrix();
void multiplyMatrix();
void multiplyMatrix2();
void multiplyMatrixError();
void testTranspose();
void testIsANonNegativeMatrix();

int main(){
    cout << endl << "==========Testing Vector==========" << endl;
    testVector();
    cout << endl;
    
    cout << endl << "==========Testing Set Matrix==========" << endl;
    setMatrix();
    cout << endl;

    cout << endl << "==========Testing Sum Matrix==========" << endl;
    sumMatrix();
    cout << endl;

    cout << endl << "==========Testing Subtract Matrix==========" << endl;
    subtractMatrix();
    cout << endl;

    cout << endl << "==========Testing Multiply Matrix==========" << endl;
    multiplyMatrix();
    cout << endl;

    cout << endl << "==========Testing Multiply Matrix2==========" << endl;
    multiplyMatrix2();
    cout << endl;

    // cout << endl << "==========Testing Matrix with error==========" << endl;
    // multiplyMatrixError();
    // cout << endl;

    cout << endl << "==========Testing Transpose Matrix==========" << endl;
    testTranspose();
    cout << endl;
    return 0;

    cout << endl << "==========Testing Transpose Matrix==========" << endl;
    testIsANonNegativeMatrix();
    cout << endl;
    return 0;
}


void testConstructorInvalidRow() {
    Matrix *matrix = new Matrix(-1,0);
    delete matrix;
}

void testConstructorInvalidColumn() {
    Matrix *matrix = new Matrix(0,-2);
    delete matrix;
}

void testVector() {
    Matrix *vector = new Matrix(1,5);
    for(int i=0; i<5;i++) {
        if(i==0) {
            vector->set(0,i, 2.0);
        } else{
            vector->set(0,i, 2.0*vector->at(0,i-1));
        }
    }
    vector->print();
    delete vector;
}

void setMatrix() {
    Matrix *matrix = new Matrix(4, 4);
    for(int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->columns; j++) {
            matrix->set(i,j, i*j+1);
        }
    }
    matrix->print();

    delete matrix;
}

void sumMatrix() {
    Matrix *A = new Matrix(4, 4);
    for(int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            A->set(i,j, i*j+1);
        }
    }
    cout << "Matrix A: " << endl;
    A->print();
    cout << endl;    
    Matrix *B= new Matrix(4, 4);
    for(int i = 0; i < B->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
            B->set(i,j, i*j-1);
        }
    }
    cout << "Matrix B: " << endl;
    B->print();
    cout << endl;

    cout << "Result: " << endl;
    Matrix *result = A->add(B);
    result->print();

    delete A;
    delete B; 
    delete result;
}

void subtractMatrix() {
    Matrix *A = new Matrix(4, 4);
    for(int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            A->set(i,j, i*j+1);
        }
    }
    cout << "Matrix A: " << endl;
    A->print();
    cout << endl;    
    Matrix *B= new Matrix(4, 4);
    for(int i = 0; i < B->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
            B->set(i,j, i*j-1);
        }
    }
    cout << "Matrix B: " << endl;
    B->print();
    cout << endl;

    cout << "Result: " << endl;
    Matrix *result = A->subtract(B);
    result->print();

    delete A;
    delete B; 
    delete result;
}

void multiplyMatrix() {
    Matrix *A = new Matrix(2,2);
    Matrix *B = new Matrix(2,2);
    A->set(0,0,1);
    A->set(0,1,2);
    A->set(1,0,3);
    A->set(1,1,4);
    cout << "Matrix A: " << endl;
    A->print();
    cout << endl;   

    B->set(0,0,5);
    B->set(0,1,6);
    B->set(1,0,7);
    B->set(1,1,8);
    cout << "Matrix B: " << endl;
    B->print();
    cout << endl;

    cout << "Result: " << endl;
    Matrix *result = A->multiply(B);
    result->print();

    delete A;
    delete B;
    delete result;
}

void multiplyMatrix2() {
    Matrix *A = new Matrix(3,4);
    Matrix *B = new Matrix(4,3);
      for(int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            A->set(i,j, i*j+1);
        }
    }

     for(int i = 0; i < B->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
            B->set(i,j, 2*i*j);
        }
    }

    cout << "Matrix A: " << endl;
    A->print();
    cout << endl;   

    cout << "Matrix B: " << endl;
    B->print();
    cout << endl;

    cout << "Result: " << endl;
    Matrix *result = A->multiply(B);
    result->print();

    delete A;
    delete B;
    delete result;
}

void multiplyMatrixError() {
    Matrix *A = new Matrix(4,5);
    Matrix *B = new Matrix(3,5);
    try {
        cout << "Result: " << endl;
        Matrix *result = A->multiply(B);
        result->print();
        delete A;
        delete B;
    } catch(std::exception* e) {
        cout << "hahahah" << endl;
        cout << e->what() <<endl;
        delete A;
        delete B;
    }
    
}

void testTranspose() {
    Matrix *A = new Matrix(3,4);
      for(int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            A->set(i,j, i*j+1);
        }
    }

    cout << "Matrix A: " << endl;
    A->print();
    cout << endl;   

    cout << "Matrix A transpose: " << endl;
    A->transpose()->print();
    cout << endl;   
    delete A;
}

void testIsANonNegativeMatrix(){
    Matrix *A = new Matrix(2,2);
    for(int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            A->set(i,j, pow(-1, i+j));
        }
    }

    cout << "Matrix A: " << endl;
    A->print();
    cout << endl;  

    cout << "Matrix A is a nonnegative matrix: " << A->isANonNegativeMatrix << endl;
}

