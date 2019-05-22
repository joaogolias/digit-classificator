#include "NonNegativeFactorization.h"
#include "../qr/QrFactorization.h"
#include "../../systems/triangularsystemssolver/TriangularSystemsSolver.h"
#include <math.h>
#include <iomanip>

#define itmax 100
#define epsilon 10e-5

using namespace std;

NonNegativeFactorization::NonNegativeFactorization(){}

NonNegativeFactorization::~NonNegativeFactorization(){}

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
            if(M->at(i,j) < 0) M->set(i, j, 0);
            else M->set(i,j, M->at(i,j));
            
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
            error += difference * difference;
        }
    }

    delete WH;
    
    return error;
}

int NonNegativeFactorization::execute(Matrix *A, Matrix *W, Matrix *H )
{   

    if (!A->isANonNegativeMatrix())
        throw std::invalid_argument("All matrix values must be non negatives");

    Matrix *A_Copy = new Matrix(A->rows, A->columns);
    Matrix* At = new Matrix(A->columns, A->rows);
    Matrix* Ht = new Matrix(H->columns, H->rows); 
    Matrix* Wt;

    this->Wresult = W->copy();
    this->Hresult = H->copy();

    QrFactorization* qrFactorization = new QrFactorization();
    TriangularSystemsSolver* triangularSystemSolver = new TriangularSystemsSolver();

    int iterationCount = 0;
    double errorChange = 10;
    double oldError = 0;
    double newError = 0;

    while (abs(errorChange) > epsilon)
    {   
        if(iterationCount >= itmax)
            break;

        // A_Copy = A->copy();
        A->copyTo(A_Copy);

        //Normalizar W tal que a norma de cada uma das colunas seja 1
        normalize(this->Wresult);

        //Resolver o problema dos minimos quadrados W * H = A (utiizar A original a cada interação)
        qrFactorization->execute(this->Wresult, A_Copy);
        this->Hresult = triangularSystemSolver->solveSystems(this->Wresult, A_Copy);

        //Redefinir H hij=max(0, hij)
        handleNegativeValues(this->Hresult);
        
        //transpor A (original)
        A->transpose(At);

        //Resolver o problema dos minimos quadrados para Ht * Wt = At
        this->Hresult->transpose(Ht);

        qrFactorization->execute(Ht, At);
        Wt = triangularSystemSolver->solveSystems(Ht, At);

        //Redefinir W
        Wt->transposeAndHandleNegativeValues(this->Wresult);


        //Atualizar variação do erro
        newError = calculateError(A, W, H);
        errorChange = oldError - newError;
        oldError = newError;

        iterationCount++;
    }

    delete A_Copy;
    delete At;
    delete Ht; 
    delete Wt;

    delete qrFactorization;
    delete triangularSystemSolver;

    return iterationCount;
}

Matrix* NonNegativeFactorization::getH() {
    return this->Hresult;
}

Matrix* NonNegativeFactorization::getW() {
    return this->Wresult;
}