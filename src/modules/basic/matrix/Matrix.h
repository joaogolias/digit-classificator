#ifndef MATRIX_H
#define MATRIX_H
// #include "../../factorization/qr/QrFactorization.h"
#include "../../../../tests/comparable/Comparable.h"

class Comparable;

class Matrix : public Comparable {
    double **values;

    public: 
        int columns = 0;
        int rows = 0;
        
        bool isEqualsTo(Matrix* M, double error); 
        bool isEqualsTo(Comparable* compareObject);
        bool isEqualsTo(Comparable* compareObject, double error);

        Matrix(int col, int r);
        ~Matrix();

        double at(int row, int column);
        double* getRow(int row);
        double calculateFrobeniusNorm();

        Matrix* copy();
        Matrix* add(Matrix* B);
        Matrix* subtract(Matrix *B);
        Matrix* multiply(Matrix* B);
        Matrix* mutiplyByConstant(double c, bool createNewMatrix);
        Matrix* transpose();

        bool isANonNegativeMatrix();

        void set(int row, int column, double value);
        void setRow(int row, double* value);
        void setRow(int row, double value[], int size);
        void print();

    private:
        bool areValidArguments(int row, int column);
};

#endif