#include "NonNegativeFactorization.h"
#include "QrFactorization.h"
#include "TriangularSystemsSolver.h"
#include <math.h>

#define itmax 100
#define epsilon 10e-5

using namespace std;

NonNegativeFactorization::NonNegativeFactorization(Matrix *W)
{
    this->W = W;
}

NonNegativeFactorization::~NonNegativeFactorization()
{
    delete W;
}

double NonNegativeFactorization::calculateS(Matrix *M, int column)
{
    double squaresSum = 0;

    for (int i = 0; i <= M->rows; i++)
    {
        squaresSum += pow(M->at(i, column), 2);
    }

    return sqrt(squaresSum);
}

void NonNegativeFactorization::normalize(Matrix *M)
{
    for (int j; j <= M->columns; j++)
    {
        double s = calculateS(M, j);
        for (int i; i <= M->rows; i++)
        {
            double newValue = M->at(i, j) / s;
            M->set(i, j, newValue);
        }
    }
}

void NonNegativeFactorization::handleNegativeValues(Matrix *M)
{
    for (int i; i <= M->rows; i++)
    {
        for (int j; j <= M->columns; j++)
        {
            M->set(i, j, fmax(0.0, M->at(i, j)));
        }
    }
}

double NonNegativeFactorization::calculateError(Matrix *A, Matrix *W, Matrix *H)
{
    double error = 0;
    Matrix *WH = W->multiply(H);

    for (int i = 0; i <= A->rows; i++)
    {
        for (int j = 0; j <= A->columns; j++)
        {
            double difference = A->at(i, j) - WH->at(i, j);
            error += pow(difference, 2);
        }
    }

    return error;
}

Matrix *NonNegativeFactorization::execute(Matrix *A)
{
    if (!A->isANonNegativeMatrix())
        throw std::invalid_argument("All matrix values must be non negatives");

    QrFactorization* qrFactorization = new QrFactorization();
    TriangularSystemsSolver* triangularSystemSolver = new TriangularSystemsSolver();

    //TODO: Change fixed column dimension
    Matrix *W = new Matrix(A->rows, 2);
    for (int i = 0; i < W->rows; i++)
    {
        for (int j = 0; j <= W->columns; j++)
        {
            A->set(i, j, rand());
        }
    }

    int iterationCount = 0;
    double errorChange = 0;
    double oldError = 0;

    while (errorChange > epsilon)
    {
        if(iterationCount >= itmax)
            break;

        Matrix *A_Copy = A->copy();

        //TODO: Normalizar W tal que a norma de cada uma das colunas seja 1
        normalize(W);

        //TODO: Resolver o problema dos minimos quadrados W * H = A (utiizar A original a cada interação)
        Matrix* Wtriangular = qrFactorization->execute(W, A_Copy);
        Matrix* H = triangularSystemSolver->solveSystems(Wtriangular, A_Copy);

        //TODO: Redefinir H hij=max(0, hij)
        handleNegativeValues(H);

        //TODO: transpor A (original)
        Matrix* transposedA = A->transpose();

        //TODO: Resolver o problema dos minimos quadrados para Ht * Wt = At
        Matrix* transposedWtriangular = qrFactorization->execute(W->transpose(), transposedA);
        Matrix* H = triangularSystemSolver->solveSystems(transposedWtriangular, transposedA);

        //TODO: transpor Wt
        Matrix* transposedWt = transposedWtriangular->transpose();
        //TODO: Redefinir W wij=max(0, wij)
        handleNegativeValues(transposedWt);

        double newError = calculateError(A, transposedWt, H);
        errorChange = newError - oldError;
        oldError = newError;

        iterationCount++;
    }

    return A_Copy;
}