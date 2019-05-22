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
    if(rows < 0) throw std::invalid_argument( "rows must be >= 0" );
    if(rows == 0) rows = 1;
    if(columns <= 0) throw std::invalid_argument( "columns must be > 0" );
    
    values = new double*[rows];
    for(int i=0; i < rows; i++) {
        values[i] = new double[columns];
        for(int j=0;j<columns;j++){
            values[i][j] = 0;
        }
    }
}


Matrix::~Matrix(){
    for(int i = 0; i < rows; i++) {
        delete [] values[i];
    }
    delete [] values;
}

double Matrix::at(int row, int column){
    // if(areValidArguments(row, column)){
    //     return values[row][column];
    // }
    return values[row][column];
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

double Matrix::euclideanNomr() {
    double result = 0;
    for(int i=0; i<rows; i++){
        for(int j = 0; j < columns; j++){
            result += at(i,j)*at(i,j);
        }
    }
    return sqrt(result);
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

void Matrix::copyTo(Matrix* to) {
     for(int i = 0; i < rows; i++) {
        for(int j = 0; j<columns; j++) {
            to->set(i,j,at(i,j));
        }
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

void Matrix::add(Matrix* B, Matrix* result) {
    if(rows != B->rows || columns != B->columns) {
        throw std::invalid_argument("Demensions don't match");
    }

    for(int i = 0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            result->set(i, j, at(i,j) + B->at(i,j));
        }
    }
}
        
Matrix* Matrix::add(Matrix* B) {
    Matrix* returnMatrix = new Matrix(rows, columns);
    add(B, returnMatrix);
    return returnMatrix;
}

void Matrix::subtract(Matrix* B, Matrix* result) {
    if(rows != B->rows || columns != B->columns) {
        throw std::invalid_argument("Demensions don't match");
    }

    for(int i = 0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            result->set(i, j, at(i,j) - B->at(i,j));
        }
    }
}

Matrix* Matrix::subtract(Matrix *B){
    Matrix* returnMatrix = new Matrix(rows, columns);
    subtract(B, returnMatrix);
    return returnMatrix;
}

void Matrix::multiply(Matrix* B, Matrix* result) {
    if(B->rows != columns) {
        throw std::invalid_argument("A columns must be equal to B rows.");
    }
    
    if(rows != result->rows) {
        throw std::invalid_argument("result rows must be equal to A rows");
    }

    if(B->columns != result->columns) {
        throw std::invalid_argument("result columns must be equal to B columns.");
    }

    int dimension = columns;
    for(int i = 0; i < result->rows; i++) {
        for(int j = 0; j < result->columns; j++){
            double finalValue = 0;
            for(int k = 0; k<dimension; k++){
                finalValue+=at(i,k)*B->at(k,j);
            }
            result->set(i,j, finalValue);
        }
    }
}

Matrix* Matrix::multiply(Matrix* B) {
    Matrix* returnableMatrix = new Matrix(rows, B->columns);
    multiply(B, returnableMatrix);
    return returnableMatrix;
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


void Matrix::transpose(Matrix* result){
    for(int i = 0; i < rows ; i ++) {
        for (int j = 0; j <columns; j++) {
            result -> set(j,i, at(i,j));
        }
    }
}


Matrix* Matrix::transpose(){
    Matrix* resultMatrix = new Matrix(columns, rows);
    transpose(resultMatrix);
    return resultMatrix;
}

void Matrix::transposeAndHandleNegativeValues(Matrix* result){
    for(int i = 0; i < rows ; i ++) {
        for (int j = 0; j < columns; j++) {
            result -> set(j,i, fmax(0.0, at(i,j)));
        }
    }
}

Matrix* Matrix::transposeAndHandleNegativeValues(){
    Matrix* resultMatrix = new Matrix(columns, rows);
    transposeAndHandleNegativeValues(resultMatrix);
    return resultMatrix;
}

Matrix* Matrix::calculateCErroVector(){
    Matrix* c = new Matrix(columns, 1);
    for(int j = 0; j< columns; j++){
        double value = 0;
        for(int i = 0; i < rows; i++){
            value += at(i,j)*at(i,j);
        }
        c->set(j,0,sqrt(value));
    }
    return c;
}

double* Matrix::getRow(int row){
    if(areValidArguments(row, NIL)){
        return values[row];
    } 
    return NULL;
}

bool Matrix::areValidArguments(int row, int column){
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
    // cout << fixed << setprecision(15) << setfill(' ');
    cout << fixed << setprecision(10) << setfill(' ');
    for(int i = 0; i<rows; i++){
        for(int j=0;j<columns;j++){
            cout << setw(4) << at(i,j) << " ";
            // cout << setw(18) << at(i,j) << " ";
        }
        cout << endl;
    }
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

void Matrix::printColumn(int j){
    for(int i = 0; i < rows; i++){
        cout << at(i,j) << endl;
    }
}

