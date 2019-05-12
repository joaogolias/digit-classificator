#include <iostream>
#include "../../testmanager/TestManager.h"
#include "../../../src/modules/basic/matrix/Matrix.h"
#include "../../../src/modules/factorization/qr/QrFactorization.h"
#include "../../../src/modules/imageProcessor/ImageProcessor.h"

void firstTest();
void secondTest();
void thirdTest();

using namespace std;

ImageProcessor* imgprocessor = new ImageProcessor();
int main() {
    firstTest();
    secondTest();
    thirdTest();
}

void firstTest() {
    cout << endl << endl << endl << "FirstTest" << endl;
    Matrix* M = new Matrix(3,3);
    double Mvalues[3][3] = {{1,4,7},{2,5,8},{3,6,9}};
    for(int i = 0; i < 3; i++) {
        M->setRow(i, Mvalues[i], 3);
    }

    cout << "M: " << endl;
    M->print();

    cout << "v: " << endl;
    Matrix* v = imgprocessor->generateVector(M);
    v->print();
}

void secondTest() {
    cout << endl << endl << endl << "SecondTest" << endl;
    Matrix* M = new Matrix(2,3);
    double Mvalues[2][3] = {{1,3,5},{2,4,6}};
    for(int i = 0; i < 2; i++) {
        M->setRow(i, Mvalues[i], 3);
    }

    cout << "M: " << endl;
    M->print();

    cout << "v: " << endl;
    Matrix* v = imgprocessor->generateVector(M);
    v->print();
}

void thirdTest() {
    cout << endl << endl << endl << "ThirdTest" << endl;
    Matrix* M = new Matrix(3,2);
    double Mvalues[3][2] = {{1,4},{2,5}, {3,6}};
    for(int i = 0; i < 3; i++) {
        M->setRow(i, Mvalues[i], 2);
    }

    cout << "M: " << endl;
    M->print();

    cout << "v: " << endl;
    Matrix* v = imgprocessor->generateVector(M);
    v->print();
}