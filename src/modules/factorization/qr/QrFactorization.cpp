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
    double wi, wj;
    for(int u = 0; u < A->columns; u++) {
        // cout << "c: " << c << endl;
        // cout << "s: " << s << endl;
        // cout << "wi: " << wi << endl;
        wi = A->at(i,u);
        // cout << "wj: " << wj << endl;
        wj = A->at(j,u);
        double bi = c*wi-s*wj;
        double bj = s*wi+c*wj;
        // cout << "bi: " << bi << endl;
        // cout << "bj: " << bj << endl;
        A->set(i,u, bi);
        A->set(j,u, bj);
    }
}

Matrix* QrFactorization::executeForOneSystem(Matrix* W, Matrix *b) {
    this->W = W;
    this->b = b;
    double wi, wj, c, s;
    Matrix* result = W->copy();
    for(int k = 1; k <= result->columns; k++) {
        int j;
        int i;
        for(j = result->rows; j >= k+1; j--){
            i = j - 1;
            if(result->at(j-1,k-1) != 0) {
                wi = result->at(i-1, k-1);
                wj = result->at(j-1, k-1);
                c = calculateC(wi, wj);
                s = calculateS(wi,wj);
                Q(result, i-1, j-1, k, c, s);
                if(b != NULL) Q(b, i-1,j-1,k,c,s);
            
            }
        }
    }
    return result;
}


Matrix* QrFactorization::execute(Matrix* W, Matrix *A) {
    int n = A->rows;
    int m = A->columns;
    int p = W->columns;
    double wi, wj, c, s;
    Matrix* result = W->copy();
    for(int k = 1; k <= p; k++) {
        int j;
        int i;
        for(j = n; j >= k+1; j--){
            i = j - 1;
            if(result->at(j-1,k-1) != 0) {
                wi = result->at(i-1, k-1);
                wj = result->at(j-1, k-1);
                c = calculateC(wi, wj);
                s = calculateS(wi,wj);
                Q(result, i-1, j-1, k, c, s);
                if(A != NULL) Q(A, i-1,j-1,k,c,s);
            
            }
        }
    }
    return result;
}