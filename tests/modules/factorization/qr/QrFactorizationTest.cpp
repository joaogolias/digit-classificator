#include "../../../../src/modules/factorization/qr/QrFactorization.h"
#include "../../../../src/modules/basic/matrix/Matrix.h"
#include "../../../testmanager/TestManager.h"
#include "../../../../src/modules/systems/triangularsystemssolver/TriangularSystemsSolver.cpp"
#include <iostream>
#include <math.h>

using namespace std;

TestManager* testManager;
TriangularSystemsSolver *solver;

void executeFirstTest();
Matrix* testExecute(Matrix *A, Matrix *b);
void testQ(Matrix *W);
Matrix* generateW();
Matrix* generateW2();
void getSoluction(Matrix* M);
Matrix* generateW3();

int main() {
    testManager = new TestManager();
    solver = new TriangularSystemsSolver();
    cout << endl << "1. ";
    executeFirstTest();
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
    // QrFactorization* qr = new QrFactorization();
    // qr->Q(W, 2,3,3);

    // W->print();
}

void executeFirstTest() {
    cout << "First Testing Execute: ";


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

    Matrix *result = testExecute(A,b);

    testManager
        ->assertEquals(result, Aresult)
        ->assertEquals(b, bresult)
        ->result();
}

Matrix* testExecute(Matrix *A, Matrix *b) {
    QrFactorization* qr = new QrFactorization();
    Matrix *result = qr->execute(A, b);
    return result;
} 