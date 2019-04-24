#include "QrFactorization.h"
#include "../../basic/matrix/Matrix.h"
#include <iostream>

using namespace std;

void testeExecute(Matrix* W);
Matrix* generateW();
Matrix* generateW2();

int main() {
    Matrix*W = generateW();

    cout << endl << "==========Testing Execute==========" << endl;
    testeExecute(W);
    cout << endl;

    W = generateW2();
    cout << endl << "==========Testing Execute==========" << endl;
    testeExecute(W);
    cout << endl;

    return 0;
}

Matrix* generateW(){
    Matrix* W = new Matrix(5, 5);
    double rowValues1[5] = {2, 1, 1, -1, 1};
    W->setRow(0, rowValues1 , 5);

    double rowValues2[5] = {0, 3, 0, 1, 2};
    W->setRow(1, rowValues2 , 5);
    
    double rowValues3[5] = {0, 0, 2, 2, -1};
    W->setRow(2, rowValues3 , 5);
    
    double rowValues4[5] = {0, 0, -1, 1, 2};
    W->setRow(3, rowValues4 , 5);
    
    double rowValues5[5] = {0, 0, 0, 3, 1};
    W->setRow(4, rowValues5 , 5);

    return W;
}

Matrix* generateW2() {
    Matrix* W = new Matrix(3, 3);
    double rowValues1[3] = {12, -51, 4};
    W->setRow(0, rowValues1 , 3);

    double rowValues2[3] = {6, 167, -68};
    W->setRow(1, rowValues2 , 3);
    
    double rowValues3[3] = {-4, 24, -41};
    W->setRow(2, rowValues3 , 3);

    return W;
}

void testeExecute(Matrix *W) {
    QrFactorization* qr = new QrFactorization(W);
    Matrix *result = qr->execute();

    result->print();
}