#include "../../../testmanager/TestManager.h"
#include "../../../../src/modules/basic/matrix/Matrix.h"
#include <iostream>

void matrixSum();
using namespace std;

int main() {
    cout << endl << "1. ";
    matrixSum();
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