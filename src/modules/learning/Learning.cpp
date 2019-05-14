#include "Learning.h"
#include "../ImageProcessor/ImageProcessor.h"

using namespace std;


Learning::Learning(){}

Learning::~Learning(){}

Matrix* Learning::execute(Matrix** images, int imageQuantity){
    ImageProcessor* imageProcessor = new ImageProcessor();
    Matrix* A = imageProcessor->execute(images, imageQuantity);
    
    //TODO: non-negative factorization of A

    return A;
}

Matrix** Learning::getImages(Matrix* W, int rows, int columns){
    ImageProcessor* imageProcessor = new ImageProcessor();
    Matrix** images = imageProcessor->reverse(W, rows, columns);
    return images;
}