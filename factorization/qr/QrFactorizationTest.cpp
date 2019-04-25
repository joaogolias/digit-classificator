#include "QrFactorization.h"
#include "../../basic/matrix/Matrix.h"
#include <iostream>
#include <math.h>

using namespace std;

void testeExecute(Matrix* W);
void testQ(Matrix *W);
Matrix* generateW();
Matrix* generateW2();
void getSoluction(Matrix* M);
Matrix* generateW3();

int main() {
    Matrix*W = generateW3();
    cout << endl << "==========Testing QR Factorization==========" << endl;
    cout << endl << "Input Matrix: " << endl;
    W->print();
    cout << endl << "Output Matrix: " << endl;
    testeExecute(W);
    cout << endl;
    cout << endl << "Correct Solution: "<< endl;
    W->set(2,2, -W->at(2,2));
    W->print();
    W=generateW();
    // cout << endl << "==========Testing Q==========" << endl;
    // testQ(W);
    // cout << endl;

    return 0;
}

Matrix* generateW(){
    Matrix* W = new Matrix(5, 5);
    double matrix[5][5] = {
        {2, 1, 1, -1, 1},
        {0, 3, 0, 1, 2},
        {0, 0, 2, 2, -1}, 
        {0, 0, -1, 1, 2}, 
        {0, 0, 0, 3, 1}
    };
    for(int i=0; i<5; i++) {
        W->setRow(i, matrix[i],5 );
    };
    return W;
}

Matrix* generateW2() {
    Matrix* W = new Matrix(5, 3);
    double matrix[5][3] = {
        {0.8147, 0.0975, 0.1576},
        {0.9058, 0.2785, 0.9706},
        {0.1270, 0.5469, 0.9572}, 
        {0.9134, 0.9575, 0.4854}, 
        {0.6324, 0.9649, 0.8003}
    };
    for(int i=0; i<5; i++) {
        W->setRow(i, matrix[i], 3);
    };
    // W->print();
    return W;
}

Matrix* generateW3() {
    Matrix* W = new Matrix(3, 3);
    double matrix[3][3] = {
        {12, -51, 4},
        {6, 167, -68},
        {-4, 24, -41}
    };
    for(int i=0; i<3; i++) {
        W->setRow(i, matrix[i], 3);
    };
    W->print();
    return W;
}

void getSoluction(Matrix* M) {
    for(int i=0 ; i<M->rows; i++) {
        cout << i << endl;
                    cout << M->at(i+1, M->columns-1) << endl;
             cout << M->at(i, M->columns-1) << endl;
        if(i == M->rows-1){
            cout << "here" << endl;

            M->set(i, M->columns-1, -M->at(i, M->columns-1));
        } else {
            if(abs(M->at(i+1, M->columns-1)) == 0.00000) {
                M->set(i, M->columns-1, -M->at(i, M->columns-1));
                break;
            }
        }
    }
}

void testQ(Matrix *W) {
    QrFactorization* qr = new QrFactorization(W);
    qr->Q(W, 2,3,3);

    W->print();
}

void testeExecute(Matrix *W) {
    QrFactorization* qr = new QrFactorization(W);
    Matrix *result = qr->execute();

    result->print();
}