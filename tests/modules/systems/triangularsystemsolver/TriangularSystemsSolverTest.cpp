#include "../../../testmanager/TestManager.h"
#include "../../../../src/modules/basic/matrix/Matrix.h"
#include "../../../../src/modules/factorization/qr/QrFactorization.h"
#include "../../../../src/modules/systems/triangularsystemssolver/TriangularSystemsSolver.h"

#include <iostream>
#include <math.h>

using namespace std;

TestManager* testManager;
TriangularSystemsSolver* solver;
QrFactorization* qr;


void testTriangularMatrix();
void testQRAndSystemSolving();
void mmqOverdeterminatedSystemTest();

int main(){
    testManager = new TestManager();
    solver = new TriangularSystemsSolver();
    qr =  new QrFactorization();

    cout << endl << "1. ";
    testTriangularMatrix();

    cout << endl << "2. ";
    testQRAndSystemSolving();

    cout << endl << "3. ";
    mmqOverdeterminatedSystemTest();

    return 0;

    // delete testManager;
    // delete solver;
    // delete qr;
}

void testTriangularMatrix(){

    cout << "Testing simple solve system: ";
    Matrix* A = new Matrix(3,3);

    double Avalues[3][3] = {{1,2,1}, {0,-7,-3}, {0,0,-2}};
    for(int i = 0; i < 3; i++) {
        A->setRow(i,Avalues[i],3);
    }
    
    double bvalues[3][1] = {{3}, {-2}, {-6}};
    Matrix* b = new Matrix(3,1);
     for(int i = 0; i < 3; i++) {
        b->setRow(i,bvalues[i],1);
    }

    double expectedValues[3][1] = {{2}, {-1}, {3}};
    Matrix* expected = new Matrix(3,1);
     for(int i = 0; i < 3; i++) {
        expected->setRow(i,expectedValues[i],1);
    }

    Matrix* X = solver->solveSystems(A,b);
    testManager->assertEquals(X, expected)->result();

    // delete A;
    // delete b;
    // delete expected;
    // delete X;
}

void testQRAndSystemSolving(){
    cout << "Testing solving systems by using QR: ";
    Matrix* A = new Matrix(3,3);

    double Avalues[3][3] = {{-1,2,4}, {5,6,6}, {-3,5,9}};
    for(int i = 0; i < 3; i++) {
        A->setRow(i,Avalues[i],3);
    }

    
    double bvalues[3][1] = {{1}, {2} , {3}};
    Matrix* b = new Matrix(3,1);
     for(int i = 0; i < 3; i++) {
        b->setRow(i,bvalues[i],1);
    }
    Matrix *R = qr->execute(A, b);

    Matrix* X = solver->solveSystems(R,b);

    double expectedValues[3][1] = {{-0.364}, {0.955}, {-0.318}};
    Matrix* expected = new Matrix(3,1);
     for(int i = 0; i < 3; i++) {
        expected->setRow(i,expectedValues[i],1);
    }

    testManager->assertEquals(X, expected)->result();

    // delete A;
    // delete b;
    // delete R;
    // delete expected;
    // delete X;
}

void mmqOverdeterminatedSystemTest() {
    cout << "Testing solving overdeterminated systems by using QR/MMQ: ";
    //https://s-mat-pcs.oulu.fi/~mpa/matreng/eem5_5-1.htm
    Matrix* A = new Matrix(3,2);

    double Avalues[3][2] = {{1, -1}, {1,1}, {2,1}};
    for(int i = 0; i < 3; i++) {
        A->setRow(i,Avalues[i],2);
    }
    
    double bvalues[3][1] = {{2}, {4} , {8}};
    Matrix* b = new Matrix(3,1);
     for(int i = 0; i < 3; i++) {
        b->setRow(i,bvalues[i],1);
    }

    Matrix *b_copy = b->copy();
    // Matrix *R = qr->execute(A, b_copy);
    qr->execute(A, b_copy);

    Matrix* X = solver->solveSystems(A ,b_copy);
    
    double realResultValues[2][1] = {{23.0/7.0}, {8.0/7.0}};
    Matrix *realResult = new Matrix(2,1);
    for(int i=0; i < 2; i++) {
        realResult->setRow(i,realResultValues[i],1);
    }

    realResult->print();

    cout << "X: " << endl;
    X->print();

    double frobeniusNorm = b->subtract(A->multiply(X))->calculateFrobeniusNorm();

    testManager
        -> assertEquals(X, realResult)
        -> assertEquals(frobeniusNorm, sqrt(2.0/7.0))
        -> result();

    // delete A;
    // delete b; 
    // delete b_copy; 
    // delete R;
    // delete realResult;
    // delete X;
}