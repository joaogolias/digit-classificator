#include "./SecondTask.h"
#include "../../../src/modules/factorization/alternatingLeastSquares/NonNegativeFactorization.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

SecondTask *secondTask = new SecondTask();
NonNegativeFactorization *nonNegativeFac = new NonNegativeFactorization();

void runExerciseA(bool printResult);

int main()
{
    runExerciseA(true);
}

void runExerciseA(bool printResult)
{
    int p = 2;

    Matrix *A = new Matrix(3, 3);
    double Avalues[3][3] = {{0.3, 0.6, 0}, {0.5, 0, 1}, {0.4, 0.8, 0}};
    for (int i = 0; i < 3; i++)
    {
        A->setRow(i, Avalues[i], 3);
    }

    int  n;
    time_t t;
   
    n = 5;
   
    /* Intializes random number generator */
    srand((unsigned) time(&t));

    Matrix *W = new Matrix(A->rows, p);
    for (int i = 0; i < W->rows; i++)
    {
        for (int j = 0; j < W->columns; j++)
        {
            W->set(i, j, rand());
        }
    }
    Matrix *H = new Matrix(p, 3);

    int iterations = nonNegativeFac->execute(A, W, H);

    H = nonNegativeFac->getH();

    W = nonNegativeFac->getW();

    if (printResult)
    {
        cout << endl << "Result given in: ";
        cout << iterations << "interacoes" << endl;
        cout << "Matriz A ============================" << endl;
        A->print();
        cout << "Matriz W ============================" << endl;
        W->print();
        cout << "Matriz H ============================" << endl;
        H->print();
    }

    Matrix *aproxA = W->multiply(H);
    cout << "Matriz aproxA=======================" <<endl;
    aproxA->print();

    if (aproxA->isEqualsTo(A))
    {
        cout << "Correct, because W*h = A" << endl;
    }
    else
    {
        cout << "Wrong, because W*H != A" << endl;
    }
}