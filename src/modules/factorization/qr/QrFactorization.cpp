#include "QrFactorization.h"
#include <math.h>

using namespace std;

QrFactorization::QrFactorization() {}

QrFactorization::~QrFactorization() { }

double QrFactorization::calculateS(double wi, double wj){
    return -wj/sqrt(wi*wi+wj*wj);
}

double QrFactorization::calculateC(double wi, double wj){
    return wi/sqrt(wi*wi+wj*wj);
}

void QrFactorization::Q(Matrix* A, double i, double j, double k,  double c, double s) {
    // Essa função Q é a que realiza a rotação de Givens na matriz <A>
    // Passamos os valores dos índices que devem ser mudados <i, j>, a iteração <k> 
    double wi, wj;
    for(int u = 0; u < A->columns; u++) {
        wi = A->at(i,u);
        wj = A->at(j,u);
        double bi = c*wi-s*wj;
        double bj = s*wi+c*wj;
        A->set(i,u, bi);
        A->set(j,u, bj);
    }
}

// Matrix* QrFactorization::execute(Matrix* W, Matrix *A) {
//     // executa a fatoração QR para as matrizes <W> e <A>
//     int n = A->rows;
//     int m = A->columns;
//     int p = W->columns;
//     double wi, wj, c, s;
//     for(int k = 1; k <= p; k++) {
//         int j;
//         int i;
//         for(j = n; j >= k+1; j--){
//             i = j - 1;
//             if(W->at(j-1,k-1) != 0) {
//                 wi = W->at(i-1, k-1);
//                 wj = W->at(j-1, k-1);
//                 c = calculateC(wi, wj);
//                 s = calculateS(wi,wj);
//                 Q(W, i-1, j-1, k, c, s);
//                 // deixamos a opção de só se fatorar a matriz <W>, por questões de testes
//                 if(A != NULL) Q(A, i-1,j-1,k,c,s);
            
//             }
//         }
//     }
//     return W;
// }

Matrix* QrFactorization::execute(Matrix* W, Matrix *A) {
    int n = A->rows;
    int m = A->columns;
    int p = W->columns;
    double wi, wj, c, s;
    for(int k = 1; k <= p; k++) {
        int j;
        int i;
        for(j = n; j >= k+1; j--){
            i = j - 1;
            if(W->at(j-1,k-1) != 0) {
                wi = W->at(i-1, k-1);
                wj = W->at(j-1, k-1);
                c = calculateC(wi, wj);
                s = calculateS(wi,wj);
                Q(W, i-1, j-1, k, c, s);
                if(A != NULL) Q(A, i-1,j-1,k,c,s);
            
            }
        }
    }
    return W;
}
