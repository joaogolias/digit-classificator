#include "QrFactorization.h"
#include <math.h>

using namespace std;

QrFactorization::QrFactorization(Matrix *W) {
    this->W = W;
}

QrFactorization::~QrFactorization() {
    delete W;
}

//k = coluna

double QrFactorization::calculateS(double wi, double wj){
    return -wj/sqrt(wi*wi+wj*wj);
}

double QrFactorization::calculateC(double wi, double wj){
    return wi/sqrt(wi*wi+wj*wj);
}

void QrFactorization::Q(Matrix* W, double i, double j, double k) {
    double wi = W->at(i, k-1);
    double wj = W->at(j, k-1);
    double c = calculateC(wi, wj);
    double s = calculateS(wi,wj);
    // cout << "Matrix da iteracao " << k << endl;

    for(int u = k-1; u < W->columns; u++) {
        wi = W->at(i, u);
        wj = W->at(j, u);
        double bi = c*wi-s*wj;
        double bj = s*wi+c*wj;
        // cout << "wi: "<< wi << endl << "wj: " << wj << endl;
        // cout << "bi: "<< wi << endl << "bj: " << bj << endl;
        W->set(i,u, c*wi-s*wj);
        W->set(j,u, s*wi+c*wj);
    }
}

Matrix* QrFactorization::execute() {
    Matrix* result = W->copy();
    for(int k = 1; k <= result->columns; k++) {
        for(int j = result->rows; j >= k+1; j--){
            int i = j - 1;
            if(W->at(j-1,k-1) != 0) {
                Q(result, i-1, j-1, k);
            }
        }
    }
    return result;
}