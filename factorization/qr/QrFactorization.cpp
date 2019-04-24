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
double QrFactorization::calculateTau(bool isWiGreatest, double wj, double wi){
    if(isWiGreatest){
        return -wj/wi;
    } 
    return -wi/wj;
}

double QrFactorization::calculateS(bool isWiGreatest, double c, double tau){
    if(isWiGreatest){
        return c*tau;
    }
    return 1/sqrt(1+tau*tau);
}

double QrFactorization::calculateC(bool isWiGreatest, double s, double tau){
    if(isWiGreatest){
        return 1/sqrt(1+tau*tau);
    }
    return s*tau;
}

void QrFactorization::Q(Matrix* W, double i, double j, double k) {
    double wi = W->at(i, k);
    double wj = W->at(j, k);
    bool isWiGreatest = abs(wi)>abs(wj);
    double tau = calculateTau(isWiGreatest, wj, wi);
    double c;
    double s;
    if(isWiGreatest) {
        c = calculateC(isWiGreatest, 0, tau);
        s = calculateS(isWiGreatest, c, tau);
    } else {
        s = calculateS(isWiGreatest, 0, tau);
        c = calculateC(isWiGreatest, s, tau);
    }
    W->set(i,k, c*wi-s*wj);
    W->set(j,k, s*wi+c*wj);
}

Matrix* QrFactorization::execute() {
    Matrix* result = W->copy();
    for(int k = 1; k <= result->columns-1; k++) {
        for(int j = result->rows -1; j >= k+1; j--){
            int i = j - 1;
            if(W->at(j,k) != 0) {
                Q(result, i, j, k);
            }
        }
    }
    return result;
}