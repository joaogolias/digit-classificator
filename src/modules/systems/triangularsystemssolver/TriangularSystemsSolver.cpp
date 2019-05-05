#include "TriangularSystemsSolver.h"
#include <stdexcept>
#include <iostream>
#include <math.h>

using namespace std;

TriangularSystemsSolver::TriangularSystemsSolver(){}

TriangularSystemsSolver::~TriangularSystemsSolver(){
    delete W;
    delete b;
}

Matrix* TriangularSystemsSolver::solveOneSystem(Matrix*W, Matrix*b) {
    this-> W = W;
    this-> b = b;
    if(areValidArguments()) {
        Matrix* X = new Matrix(W->columns, 1);
        for(int k = X->rows-1; k >= 0; k--) {
            double finalValue = b->at(k,0);
            for(int j=k+1; j < X->rows; j++){
                finalValue = finalValue - (W->at(k,j)*X->at(j,0));
            }
            finalValue = finalValue/W->at(k,k);
            X->set(k,0,finalValue);
        }
        return X;
    }
    return NULL;
}

Matrix* TriangularSystemsSolver::solveSystems(Matrix*W, Matrix*A){
    int n = A->rows;
    int m = A->columns;
    int p = W->columns;
    Matrix *H = new Matrix(p, m);
    for(int k=p; k>=1 ; k--){
        for(int j=1; j<=m; j++) {
            double finalValue = A->at(k-1,j-1);
            for(int i = k+1; i<=p; i++) {
                finalValue = finalValue - (W->at(k-1,i-1)*H->at(i-1,j-1));
            }
            finalValue = finalValue/W->at(k-1,k-1);
            H->set(k-1, j-1, finalValue);
        }
    }
    return H;
}

bool TriangularSystemsSolver::areValidArguments() {
    if(W->rows == b->rows && isTriangularSystem()){
        return true;
    }
    throw std::invalid_argument("W and b must have the same quantity of rows");
}

bool TriangularSystemsSolver::isTriangularSystem(){
    for(int j = 0; j < W->columns; j++) {
        for(int i = W->rows-1; i >= j+1; i--){
            if(abs(W->at(i,j) - 0) > 0.001){
                throw std::invalid_argument("W must be triangular");
            }
        }
    }
    return true;
}

