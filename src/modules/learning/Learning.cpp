#include "Learning.h"
#include "../ImageProcessor/ImageProcessor.h"
#include "../factorization/alternatingLeastSquares/NonNegativeFactorization.h"

using namespace std;


Learning::Learning(){}

Learning::~Learning(){}

Matrix* Learning::execute(Matrix* A, int imageQuantity, int p){
    int n = A->rows;
    int m = A->columns;
    
    Matrix *H = new Matrix(p, m);
    Matrix *W = new Matrix(n, p);
    
    time_t t;
    srand((unsigned) time(&t));

    for (int i = 0; i < W->rows; i++)
    {
        for (int j = 0; j < W->columns; j++)
        {
            W->set(i, j, rand());
        }
    }

    NonNegativeFactorization* factorization = new NonNegativeFactorization();
    factorization->execute(A, W, H);

    return W;
}

Matrix** Learning::getImages(Matrix* W, int rows, int columns, int p){
    ImageProcessor* imageProcessor = new ImageProcessor();
    Matrix** images = imageProcessor->reverse(W, rows, columns, p);
    return images;
}