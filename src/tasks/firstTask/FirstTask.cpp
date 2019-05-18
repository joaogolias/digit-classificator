#include "FirstTask.h"
#include "../../../src/modules/basic/matrix/Matrix.h"
#include "../../../src/modules/factorization/qr/QrFactorization.h"
#include "../../../src/modules/systems/triangularsystemssolver/TriangularSystemsSolver.h"

using namespace std;

double abs(double value);
QrFactorization *qr = new QrFactorization();
TriangularSystemsSolver* solver = new TriangularSystemsSolver();


Matrix* FirstTask::resultOfExerciseA(Matrix* w, Matrix *b) {
    int w_size = w->columns;
    int i, j;
    for(i = 1; i < w_size+1; i++) {
        for (j = 1; j < w_size+1; j++) {
            if(i==j) {
                w->set(i-1,j-1,2);
            } else {
                if(abs(i*1.0-j*1.0) == 1) {
                    w->set(i-1,j-1,1);
                } else {
                    if(abs(i*1.0-j*1.0) > 1) {
                        w->set(i-1,j-1,0);
                    }
                }
            }
        }
    }
    
    for(i = 1;  i < w_size+1;  i++) {
        b->set(i-1,0,i);
    }

    Matrix*b_copy = b->copy();

    Matrix *r = qr->execute(w,b_copy);
    Matrix*x = solver->solveSystems(r,b_copy);
   
    return x;
}

Matrix* FirstTask::resultOfExerciseB(Matrix* w, Matrix *b) {
    int i, j;
    for(i=1 ; i<w->rows+1 ; i++) {
        for(j=1 ; j < w->columns+1; j++) {
            if(abs(i*1.0 - j*1.0) <= 4) {
                w->set(i-1,j-1, 1.0/(i+j-1));
            } else {
                w->set(i-1,j-1, 0);
            }
        }
    }

    for(i=1;i<b->rows+1;i++) {
        b->set(i-1,0,i);
    }

    Matrix* b_copy = b->copy();
    Matrix* r = qr->execute(w, b_copy);
    Matrix* x = solver->solveSystems(r, b_copy);
    return x;
}

Matrix* FirstTask::resultOfExerciseC(Matrix* w, Matrix *a){
    int w_size = w->columns;
    int i, j;
    for(i = 1; i < w_size+1; i++) {
        for (j = 1; j < w_size+1; j++) {
            if(i==j) {
                w->set(i-1,j-1,2);
            } else {
                if(abs(i*1.0-j*1.0) == 1) {
                    w->set(i-1,j-1,1);
                } else {
                    if(abs(i*1.0-j*1.0) > 1) {
                        w->set(i-1,j-1,0);
                    }
                }
            }
        }
    }

    for(int i = 1; i < w_size+1; i++){
        a->set(i-1,0, 1);
        a->set(i-1,1, i);
        a->set(i-1,2, 2*i-1);
    }

    Matrix* a_copy = a->copy();
    Matrix* r = qr->execute(w, a_copy);
    Matrix* x = solver->solveSystems(r, a_copy);
    return x;
}

Matrix* FirstTask::resultOfExerciseD(Matrix* w, Matrix *a){
    int w_size = w->columns;
    int i, j;
    for(i=1 ; i<w->rows+1 ; i++) {
        for(j=1 ; j < w->columns+1; j++) {
            if(abs(i*1.0 - j*1.0) <= 4) {
                w->set(i-1,j-1, 1.0/(i+j-1));
            } else {
                w->set(i-1,j-1, 0);
            }
        }
    }

    for(int i = 1; i < w_size+1; i++){
        a->set(i-1,0, 1);
        a->set(i-1,1, i);
        a->set(i-1,2, 2*i-1);
    }

    Matrix* a_copy = a->copy();
    Matrix* r = qr->execute(w, a_copy);
    Matrix* x = solver->solveSystems(r, a_copy);
    return x;
}

double abs(double value) {
    if(value < 0) return -value;
    return value;
}