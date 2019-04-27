#include "TriangularSystemsSolver.h"
#include <stdexcept>
#include <iostream>

using namespace std;

TriangularSystemsSolver::TriangularSystemsSolver(){}

TriangularSystemsSolver::~TriangularSystemsSolver(){
    delete W;
    delete b;
}

Matrix* TriangularSystemsSolver::solveSystem(Matrix*W, Matrix*b) {
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

bool TriangularSystemsSolver::areValidArguments() {
    if(W->rows == b->rows && isTriangularSystem()){
        return true;
    }
    throw std::invalid_argument("W and b must have the same quantity of rows");
}

bool TriangularSystemsSolver::isTriangularSystem(){
    for(int j = 0; j < W->columns; j++) {
        for(int i = W->rows-1; i >= j+1; i--){
            if(W->at(i,j) != 0){
                throw std::invalid_argument("W must be triangular");
            }
        }
    }
    return true;
}

