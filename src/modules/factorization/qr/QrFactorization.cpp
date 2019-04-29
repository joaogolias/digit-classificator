#include "QrFactorization.h"
#include <math.h>

using namespace std;

QrFactorization::QrFactorization() {}

QrFactorization::~QrFactorization() {
    delete W;
    delete b;
}

double QrFactorization::calculateS(double wi, double wj){
    return -wj/sqrt(wi*wi+wj*wj);
}

double QrFactorization::calculateC(double wi, double wj){
    return wi/sqrt(wi*wi+wj*wj);
}

void QrFactorization::Q(Matrix* A, double i, double j, double k,  double c, double s) {
    // double wi = W->at(i, k-1);
    // double wj = W->at(j, k-1);
    // double c = calculateC(wi, wj);
    // double s = calculateS(wi,wj);
    // cout << "Matrix da iteracao " << k << endl;
    double wi, wj;
    for(int u = k-1; u < A->columns; u++) {
        wi = A->at(i, u);
        wj = A->at(j, u);
        // wi = W->at(i,u);
        // wj = W->at(j,u);
        double bi = c*wi-s*wj;
        double bj = s*wi+c*wj;
        A->set(i,u, c*wi-s*wj);
        A->set(j,u, s*wi+c*wj);
    }
}

Matrix* QrFactorization::execute(Matrix* W, Matrix *b) {
    this->W = W;
    this->b = b;
    double wi, wj, c, s;
    Matrix* result = W->copy();
    for(int k = 1; k <= result->columns; k++) {
        for(int j = result->rows; j >= k+1; j--){
            int i = j - 1;
            if(W->at(j-1,k-1) != 0) {
                cout << i << ", " << j << ", " << k << endl;
                wi = result->at(i-1, k-1);
                wj = result->at(j-1, k-1);
                c = calculateC(wi, wj);
                s = calculateS(wi,wj);
                cout << "asd" << endl;
                Q(result, i-1, j-1, k, c, s);
                // wi = b->at(i-1, 0);
                // wj = b->at(j-1, 0);
                // c = calculateC(wi, wj);
                // s = calculateS(wi,wj);
                if(b != NULL) Q(b, i-1,1,k,c,s);
            }
        }
    }
    return result;
}