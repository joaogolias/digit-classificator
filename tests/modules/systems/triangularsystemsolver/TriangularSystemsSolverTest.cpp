#include "../../../testmanager/TestManager.h"
#include "../../../../src/modules/basic/matrix/Matrix.h"
#include "../../../../src/modules/factorization/qr/QrFactorization.h"
#include "../../../../src/modules/systems/triangularsystemssolver/TriangularSystemsSolver.h"

#include <iostream>

using namespace std;
TestManager* testManager;
TriangularSystemsSolver* solver;
QrFactorization* qr;


void testTriangularMatrix();
void testQRAndSystemSolving();

int main(){
    testManager = new TestManager();
    solver = new TriangularSystemsSolver();
    qr =  new QrFactorization();

    cout << endl << "1. ";
    testTriangularMatrix();

    cout << endl << "2. ";
    testQRAndSystemSolving();

    return 0;
}

void testTriangularMatrix(){

    cout << "Testing Solve System: ";
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

    Matrix* X = solver->solveSystem(A,b);
    testManager->assertEquals(X, expected)->result();
}

void testQRAndSystemSolving(){
    cout << "Testing QR and System Solving: ";
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

    Matrix* X = solver->solveSystem(R,b);

    double expectedValues[3][1] = {{-0.364}, {0.955}, {-0.318}};
    Matrix* expected = new Matrix(3,1);
     for(int i = 0; i < 3; i++) {
        expected->setRow(i,expectedValues[i],1);
    }

    testManager->assertEquals(X, expected)->result();
}
