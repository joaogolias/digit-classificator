#include "MatrixGenerator.h"
#include <iostream>

using namespace std;

void testZeros();
void testOnes();
void testIdentity();

int main() {
    cout << endl << "==========Testing Zeros==========" << endl;
    testZeros();
    cout << endl;

    cout << endl << "==========Testing Ones==========" << endl;
    testOnes();
    cout << endl;

    cout << endl << "==========Testing Identity==========" << endl;
    testIdentity();
    cout << endl;
    return 0;
}

void testZeros() {
    Matrix *zeros = MatrixGenerator::zeros(4,5);
    zeros->print();
}

void testOnes(){
    Matrix *ones = MatrixGenerator::ones(4,2);
    ones->print();
}

void testIdentity(){
    Matrix *identity = MatrixGenerator::identity(5);
    identity->print();
}
