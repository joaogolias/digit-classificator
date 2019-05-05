#include "../../../../src/modules/factorization/qr/QrFactorization.h"
#include "../../../../src/modules/basic/matrix/Matrix.h"
#include "../../../testmanager/TestManager.h"
#include "../../../../src/modules/systems/triangularsystemssolver/TriangularSystemsSolver.cpp"
#include <iostream>
#include <math.h>

using namespace std;

TestManager* testManager;
TriangularSystemsSolver *solver;
QrFactorization* qr;

void oneSystemFactorizationQr();
void qrForOverdeterminatedSystemTest();

int main() {
    testManager = new TestManager();
    solver = new TriangularSystemsSolver();
    qr = new QrFactorization();

    cout << endl << "1. ";
    oneSystemFactorizationQr();

    cout << endl << "2. ";
    qrForOverdeterminatedSystemTest();
    return 0; 
}

void oneSystemFactorizationQr() {
    cout << "Testing Qr factorization for one system: ";


    double Avalues[3][3] = {{-1,2,4}, {5,6,6}, {-3,5,9}};
    Matrix* A = new Matrix(3,3);  
    for(int i = 0; i < 3; i++) {
        A->setRow(i,Avalues[i],3);
    }

    
    double bvalues[3][1] = {{1}, {2} , {3}};
    Matrix* b = new Matrix(3,1);
     for(int i = 0; i < 3; i++) {
        b->setRow(i,bvalues[i],1);
    }

    double Aresultvalues[3][3] = {
        {5.916, 2.197, -0.169}, 
        {0, 7.757, 11.521}, 
        {0,0,0.479}
        };
    Matrix* Aresult = new Matrix(3,3);  

    for(int i = 0; i < 3; i++) {
        Aresult->setRow(i,Aresultvalues[i],3);
    }
    
    double bresultvalues[3][1] = {{-0}, {3.738}, {-0.152}};
    Matrix* bresult = new Matrix(3,1);
     for(int i = 0; i < 3; i++) {
        bresult->setRow(i,bresultvalues[i],1);
    }

    Matrix *result = qr->execute(A,b);

    testManager
        ->assertEquals(result, Aresult)
        ->assertEquals(b, bresult)
        ->result();
}


void qrForOverdeterminatedSystemTest() {
    //https://s-mat-pcs.oulu.fi/~mpa/matreng/eem1_7-1.htm

    cout << "Testing Qr factorization for overdeterminated system: ";

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

    double realResultValues[4][3] = {{sqrt(2), 0, -2*sqrt(2)}, {0, sqrt(2), 0}, {0, 0, 2}, {0,0,0}};
    Matrix* realResult = new Matrix(4,3);
    for(int i = 0; i < 4; i++) {
        realResult->setRow(i,realResultValues[i],3);
    }

    testManager
        ->assertEquals(R, realResult)
        ->result();
}
