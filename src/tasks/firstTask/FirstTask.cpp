#include "FirstTask.h"
#include "../../../src/modules/basic/matrix/Matrix.h"
#include "../../../src/modules/factorization/qr/QrFactorization.h"
#include "../../../src/modules/systems/triangularsystemssolver/TriangularSystemsSolver.h"
#include <math.h>

using namespace std;

QrFactorization *qr = new QrFactorization();
TriangularSystemsSolver* solver = new TriangularSystemsSolver();


Matrix* FirstTask::exerciseResultA(Matrix* w, Matrix *b, bool printIntermediarySteps) {
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
    Matrix*x = solver->solveSystem(r,b_copy);
   
    return x;
}