#ifndef MATRIX_H
#define MATRIX_H
// #include "../../factorization/qr/QrFactorization.h"
#include "../../../../tests/testable/Testable.h"

class Matrix : public Testable {
    double **values;

    public: 
        int columns = 0;
        int rows = 0;
        
        bool isEqualsTo(Matrix* M); 
        bool isEqualsTo(Testable* compareObject);

        Matrix(int col, int r);
        ~Matrix();

        double at(int row, int column);
        double* getRow(int row);

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