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
void testQRForOverdeterminatedSystem();
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
    testQRForOverdeterminatedSystem();

    cout << endl << "4. ";
    mmqOverdeterminatedSystemTest();

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

    Matrix* X = solver->solveSystems(A,b);
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

    Matrix* X = solver->solveSystems(R,b);

    double expectedValues[3][1] = {{-0.364}, {0.955}, {-0.318}};
    Matrix* expected = new Matrix(3,1);
     for(int i = 0; i < 3; i++) {
        expected->setRow(i,expectedValues[i],1);
    }

    testManager->assertEquals(X, expected)->result();
}


void testQRForOverdeterminatedSystem() {
    //https://s-mat-pcs.oulu.fi/~mpa/matreng/eem1_7-1.htm
    Matrix* A = new Matrix(4,3);

    double Avalues[4][3] = {{1,0,-1}, {1,0,-3}, {0,1,1}, {0, -1, 1}};
    for(int i = 0; i < 4; i++) {
        A->setRow(i,Avalues[i],3);
    }

    
    double bvalues[4][1] = {{4}, {6} , {-1}, {2}};
    Matrix* b = new Matrix(4,1);
     for(int i = 0; i < 4; i++) {
        b->setRow(i,bvalues[i],1);
    }

    Matrix *R = qr->execute(A, b);
}


void mmqOverdeterminatedSystemTest() {
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
    Matrix *R = qr->execute(A, b_copy);

    Matrix* X = solver->solveSystems(R,b_copy);
    cout << " Norm: "<<  b->subtract(A->multiply(X))->calculateFrobeniusNorm() << endl;
}