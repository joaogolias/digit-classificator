#include "../../../testmanager/TestManager.h"
#include "../../../../src/modules/basic/matrix/Matrix.h"
#include <iostream>

void matrixSum();
void matrixMultiply();

void negativeMatrixIsNonNegative();
void nullMatrixIsNonNegative();
using namespace std;

int main() {
    cout << endl << "1. ";
    matrixSum();


    cout << endl << "2. ";
    matrixMultiply();
    cout << endl;

    cout << endl << "2. ";
    negativeMatrixIsNonNegative();
    cout << endl;

    cout << endl << "3. ";
    nullMatrixIsNonNegative();
    cout << endl;


    return 0;
}

void matrixSum() {
    cout << "Testing Matrix Sum: ";

    double Mvalues[2][2] = {{0,0}, {0,0}};
    Matrix *M = new Matrix(2,2);
    for(int i = 0; i < 2; i++) {
        M->setRow(i, Mvalues[i]);
    }

    double Bvalues[2][2] = {{1,1}, {1,1}};
    Matrix *B = new Matrix(2,2);
    for(int i = 0; i < 2; i++) {
        B->setRow(i, Mvalues[i]);
    }

    Matrix *C = M->add(B);

    TestManager* testManager = new TestManager();
    testManager -> assertEquals(C, B);
}

void matrixMultiply(){
    cout << "Testing Matrix Multiply: ";

    double Mvalues[2][2] = {{0,0}, {0,0}};
    Matrix *A = new Matrix(2,2);
    for(int i = 0; i < 2; i++) {
        A->setRow(i, Mvalues[i]);
    }

    double Bvalues[2][2] = {{1,1}, {1,1}};
    Matrix *B = new Matrix(2,2);
    for(int i = 0; i < 2; i++) {
        B->setRow(i, Mvalues[i]);
    }

    Matrix *C = A->multiply(B);

    TestManager* testManager = new TestManager();
    testManager -> assertEquals(C, A);
}

void negativeMatrixIsNonNegative() {
    cout << "Testing Is NonNegative to Nagative Matrix: ";
    double Mvalues[2][2] = {{0,1}, {1, -1}};
    Matrix *M = new Matrix(2,2);
    for(int i = 0; i < 2; i++) {
        M->setRow(i, Mvalues[i]);
    }

    TestManager* testManager = new TestManager();
    testManager->assertEquals(M->isANonNegativeMatrix(), false);
}

void nullMatrixIsNonNegative() {
    cout << "Testing Is NonNegative to Null Matrix: ";
    double Mvalues[2][2] = {{0,0}, {0,0}};
    Matrix *M = new Matrix(2,2);
    for(int i = 0; i < 2; i++) {
        M->setRow(i, Mvalues[i]);
    }

    TestManager* testManager = new TestManager();
    testManager->assertEquals(M->isANonNegativeMatrix(), true);
}