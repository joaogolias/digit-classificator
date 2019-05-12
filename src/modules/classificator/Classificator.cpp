#include <iostream>
#include "Classificator.h"
#include "../factorization/qr/QrFactorization.h"
#include "../imageProcessor/ImageProcessor.h"
#include "../systems/triangularsystemssolver/TriangularSystemsSolver.h"

using namespace std;

Classificator::Classificator(){}
Classificator::~Classificator(){}

Matrix* Classificator::classificate(Matrix* digitTrain, Matrix *image) {
    Matrix **images = new Matrix*[1];
    images[0]=image;
    
    ImageProcessor *imageProcessor = new ImageProcessor();
    Matrix* v = imageProcessor->execute(images, 1);

    QrFactorization* qr = new QrFactorization();
    Matrix* WdTriangular = qr->execute(digitTrain, v);

    TriangularSystemsSolver *solver = new TriangularSystemsSolver();
    Matrix*x = solver->solveSystems(WdTriangular, v);

    return x;
}