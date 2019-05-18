#include "NonNegativeFactorization.h"
#include "../qr/QrFactorization.h"
#include "../../systems/triangularsystemssolver/TriangularSystemsSolver.h"
#include <math.h>

#define itmax 100
#define epsilon 10e-5

using namespace std;

NonNegativeFactorization::NonNegativeFactorization()
{
}

NonNegativeFactorization::~NonNegativeFactorization()
{
}

double NonNegativeFactorization::calculateS(Matrix *M, int column)
{
    double squaresSum = 0;

    for (int i = 0; i < M->rows; i++)
    {
        squaresSum += pow(M->at(i, column), 2);
    }

    return sqrt(squaresSum);
}

void NonNegativeFactorization::normalize(Matrix *M)
{   
    for (int j=0; j < M->columns; j++)
    {
        double s = calculateS(M, j);

        for (int i=0; i < M->rows; i++)
        {
            double newValue = M->at(i, j) / s;
            M->set(i, j, newValue);
        }
    }
}

void NonNegativeFactorization::handleNegativeValues(Matrix *M)
{
    for (int i=0; i < M->rows; i++)
    {
        for (int j=0; j < M->columns; j++)
        {
            M->set(i, j, fmax(0.0, M->at(i, j)));
        }
    }
}

double NonNegativeFactorization::calculateError(Matrix *A, Matrix *W, Matrix *H)
{
    double error = 0;

    Matrix *WH = W->multiply(H);
    for (int i = 0; i < A->rows; i++)
    {
        for (int j = 0; j < A->columns; j++)
        {
            double difference = A->at(i, j) - WH->at(i, j);
            error += pow(difference, 2);
        }
    }

    return error;
}

int NonNegativeFactorization::execute(Matrix *A, Matrix *W, Matrix *H )
{   

    if (!A->isANonNegativeMatrix())
        throw std::invalid_argument("All matrix values must be non negatives");

    // Matrix *A_Copy;
    // Matrix* Wtriangular;
    // Matrix* At;
    // Matrix* HtTriangular; 
    // Matrix* Wt; 

    QrFactorization* qrFactorization = new QrFactorization();
    TriangularSystemsSolver* triangularSystemSolver = new TriangularSystemsSolver();

    int iterationCount = 0;
    double errorChange = 10;
    double oldError = 0;


    while (abs(errorChange) > epsilon)
    {   
        if(iterationCount >= itmax)
            break;
        Matrix* A_Copy = A->copy();

        //TODO: Normalizar W tal que a norma de cada uma das colunas seja 1
        normalize(W);

        //TODO: Resolver o problema dos minimos quadrados W * H = A (utiizar A original a cada interação)
        Matrix* Wtriangular = qrFactorization->execute(W, A_Copy);
        H = triangularSystemSolver->solveSystems(Wtriangular, A_Copy);

        //TODO: Redefinir H hij=max(0, hij)
        handleNegativeValues(H);
        
        //TODO: transpor A (original)
        Matrix* At = A->transpose();

        //TODO: Resolver o problema dos minimos quadrados para Ht * Wt = At
        Matrix* HtTriangular = qrFactorization->execute(H->transpose(), At);

        Matrix* Wt = triangularSystemSolver->solveSystems(HtTriangular, At);
       


        //TODO: transpor Wt
        W = Wt->transpose();
        //TODO: Redefinir W wij=max(0, wij)
        handleNegativeValues(W);

        double newError = calculateError(A, W, H);
        errorChange = oldError - newError;
        oldError = newError;

        iterationCount++;
        
       
    }
    this->Wresult = W;
    this->Hresult = H;
    
    // delete Wtriangular;
    // delete At;
    // delete HtTriangular;
    // delete Wt; 
    // delete A_Copy;

    // delete qrFactorization;
    // delete triangularSystemSolver;

    return iterationCount;
}

Matrix* NonNegativeFactorization::getH() {
    return this->Hresult;
}

Matrix* NonNegativeFactorization::getW() {
    return this->Wresult;
}