#include "Matrix.h"
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <math.h>

#define NIL -1.0

using namespace std;

Matrix::Matrix(int r, int col) {
    columns = col;
    rows = r;
    if(rows < 0) throw std::invalid_argument( "rows must be <= 0" );
    if(rows == 0) rows = 1;
    if(columns <= 0) throw std::invalid_argument( "columns must be > 0" );
    if(rows !=0 && columns!=0) {
        values = (double **) malloc(rows * sizeof(double*));
        for(int i=0; i<rows; i++) {
            values[i] = (double *)malloc(columns * sizeof(double));
        }
    }

}

double Matrix::at(int row, int column){
    if(areValidArguments(row, column)){
        return values[row][column];
    }
    return NIL;
}

double Matrix::calculateFrobeniusNorm() {
    double norm = 0.0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j<columns; j++) {
            norm += at(i,j)*at(i,j);
        }
    }
    return sqrt(norm);
}
void Matrix::set(int row, int column, double value) {
    if(areValidArguments(row, column)){
        values[row][column] = value;
    }
}

void Matrix::setRow(int row, double* value){
    if(areValidArguments(row, NIL)){
        values[row] = value;
    }
}

Matrix* Matrix::copy(){
    Matrix *copyMatrix = new Matrix(rows, columns);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j<columns; j++) {
            copyMatrix->set(i,j,at(i,j));
        }
    }
    return copyMatrix;
    
}
        
Matrix* Matrix::add(Matrix* B) {
    if(rows == B->rows && columns == B-> columns) {
        Matrix* returnMatrix = copy();
        for(int i = 0; i<rows; i++) {
            for(int j=0; j<columns; j++) {
                returnMatrix->set(i, j, at(i,j) + B->at(i,j));
            }
        }
        return returnMatrix;
    }
    else throw std::invalid_argument("Demensions don't match");
}

Matrix* Matrix::subtract(Matrix *B){
    if(rows == B->rows && columns == B-> columns) {
        Matrix* returnMatrix = copy();
        for(int i = 0; i<rows; i++) {
            for(int j=0; j<columns; j++) {
                returnMatrix->set(i, j, at(i,j) - B->at(i,j));
            }
        }
        return returnMatrix;
    }
    else throw std::invalid_argument("Demensions don't match");
}

Matrix* Matrix::multiply(Matrix* B) {
    if(B->rows == columns) {
        int dimension = columns;
        Matrix* returnableMatrix = new Matrix(rows, B->columns);
        for(int i = 0; i < returnableMatrix->rows; i++) {
            for(int j = 0; j < returnableMatrix->columns; j++){
                double finalValue = 0;
                for(int k = 0; k<dimension; k++){
                    finalValue+=at(i,k)*B->at(k,j);
                }
                returnableMatrix->set(i,j, finalValue);
            }
        }
        return returnableMatrix;
    }
    throw std::invalid_argument("A columns must be equal to B rows.");
}

Matrix* Matrix::mutiplyByConstant(double c, bool useSameMatrix) {
    Matrix* returnMatrix;
    if(useSameMatrix) returnMatrix = this;
    else returnMatrix = new Matrix(this->rows, this->columns);
    for(int i = 0; i<rows; i++) {
        for(int j = 0; j<columns; j++)  {
            returnMatrix -> set(i,j,c*at(i,j));
        }
    }
    return returnMatrix;
}

Matrix* Matrix::transpose(){
    Matrix* resultMatrix = new Matrix(columns, rows);
    for(int i = 0; i < rows ; i ++) {
        for (int j = 0; j <columns; j++) {
            resultMatrix -> set(j,i, at(i,j));
        }
    }
    return resultMatrix;
}

double* Matrix::getRow(int row){
    if(areValidArguments(row, NIL)){
        return values[row];
    } 
    return NULL;
}

bool Matrix::areValidArguments(int row, int column){
    // cout << row << endl << column;
    // cout << "columns: " << columns << endl << "rows: " << rows << endl;
    bool validColumn = true;
    bool validRow = true;
    if(column != NIL && column >= columns) validColumn = false; 
    if(row != NIL && row >= rows) validRow = false; 
    if(validColumn && validRow) {
        return true;
    }
    throw std::invalid_argument("Invalid argument of row or column");
}

void Matrix::print() {
    cout << fixed << setprecision(15) << setfill(' ');
    for(int i = 0; i<rows; i++){
        for(int j=0;j<columns;j++){
            cout << setw(18) << at(i,j) << " ";
        }
        cout <<endl;
    }
}

Matrix::~Matrix(){
    for(int i = 0; i < rows; i++) {
        free(values[i]);
    }
    free(values);
}

void Matrix::setRow(int row, double value[], int size) {
    if(size != columns) {
        throw std::invalid_argument("Invalid argument of size");
    }
    for(int j = 0; j <size; j++) {
        set(row, j, value[j]);
    }
}

bool Matrix::isEqualsTo(Matrix* compare, double error) {
    if(columns != compare->columns || rows != compare->rows) {
        return false;
    }
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j<columns; j++){
            if(abs(at(i,j) - compare->at(i,j)) > error){
                return false;
            }
        }
    }
    return true;
}

bool Matrix::isEqualsTo(Comparable* compare, double error) {
    Matrix* M = dynamic_cast<Matrix*>(compare);
    if(M != NULL) {
        return isEqualsTo(M, error);
    }
    return false;
}

bool Matrix::isANonNegativeMatrix(){
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j<columns; j++){
            if(at(i,j) < 0) {
                return false;
            }
        }
    }
    return true;
}