#include "../../../testmanager/TestManager.h"
#include "../../../../src/modules/basic/matrix/Matrix.h"
#include "../../../../src/modules/systems/triangularsystemssolver/TriangularSystemsSolver.cpp"
#include <iostream>

using namespace std;
TestManager* testManager;
TriangularSystemsSolver* solver;

void testTriangularMatrix();

int main(){
    testManager = new TestManager();
    solver = new TriangularSystemsSolver();

    cout << endl << "1. ";
    testTriangularMatrix();

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