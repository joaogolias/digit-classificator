#include <iostream>
#include <stdlib.h>
#include "Learning.h"
#include "../imageprocessor/ImageProcessor.h"
#include "../factorization/alternatingLeastSquares/NonNegativeFactorization.h"

using namespace std;


Learning::Learning(){}

Learning::~Learning(){}

Matrix* Learning::execute(Matrix* A, int imageQuantity, int p){
    // realiza a aprendizagem para um digito A
    int n = A->rows;
    int m = A->columns;
    
    Matrix *H = new Matrix(p, m);
    Matrix *W = new Matrix(n, p);
    
    // inicia o seed da função que gera números aleatórios
    time_t t;
    srand((unsigned) time(&t));

    for (int i = 0; i < W->rows; i++)
    {
        for (int j = 0; j < W->columns; j++)
        {
            // seta valores aleatórios para W
            W->set(i, j, rand());
        }
    }
    
    // realiza a fatoração não negativa da matriz, terminando a aprendizagem
    NonNegativeFactorization* factorization = new NonNegativeFactorization();
    factorization->execute(A, W, H);

    delete H;
    
    return factorization->getW();
}

Matrix** Learning::getImages(Matrix* W, int rows, int columns, int p){
    // pega uma matriz que tem, em suas colunas, os vetores que representam as imagens
    // retorna um array com as matrizes das imagens individualmente 
    ImageProcessor* imageProcessor = new ImageProcessor();
    Matrix** images = imageProcessor->reverse(W, rows, columns, p);
    delete imageProcessor;
    return images;
}