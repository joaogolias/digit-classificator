#include <iostream>
#include "Classificator.h"
#include "../factorization/qr/QrFactorization.h"
#include "../imageprocessor/ImageProcessor.h"
#include "../systems/triangularsystemssolver/TriangularSystemsSolver.h"

using namespace std;

Classificator::Classificator(){}
Classificator::~Classificator(){}

Matrix* Classificator::classificate(Matrix* digitTrain, Matrix *v) {
    // Matrix **images = new Matrix*[1];
    // images[0]=image;
    
    // ImageProcessor *ImageProcessor = new ImageProcessor();
    // Matrix* v = ImageProcessor->execute(images, 1);

    QrFactorization* qr = new QrFactorization();
    Matrix* WdTriangular = qr->execute(digitTrain, v);

    TriangularSystemsSolver *solver = new TriangularSystemsSolver();
    Matrix*x = solver->solveSystems(WdTriangular, v);

    return x;
}