#include "./SecondTask.h"
#include "../../../src/modules/factorization/alternatingLeastSquares/NonNegativeFactorization.h"
#include "../../../src/modules/factorization/qr/QrFactorization.h"
#include "../../../src/modules/systems/triangularsystemssolver/TriangularSystemsSolver.h"
#include <iostream>

using namespace std;

SecondTask *secondTask = new SecondTask();
NonNegativeFactorization *nonNegativeFac = new NonNegativeFactorization();
QrFactorization *qr = new QrFactorization();
TriangularSystemsSolver *solver = new TriangularSystemsSolver();

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

    cout << endl << "Exercise approximate A answer is: ";
    if (printResult)
    {
        cout << iterations << "interacoes" << endl;
        cout << "Matriz A ============================" << endl;
        A->print();
        cout << "Matriz W ============================" << endl;
        W->print();
        cout << "Matriz H ============================" << endl;
        H->print();
    }

    Matrix *aproxA = W->multiply(H);

    if (aproxA->isEqualsTo(A))
    {
        cout << "Correct, because W*h = A" << endl;
    }
    else
    {
        cout << "Wrong, because W*H != A" << endl;
    }
}