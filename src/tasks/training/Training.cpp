#include <iostream>
#include <stdexcept>
#include <iomanip>
#include "../../helpers/filehelper/FileHelper.h"
#include "../../helpers/timeHelper/TimeHelper.h"
#include "../../modules/learning/Learning.h"
#include "../../modules/imageProcessor/ImageProcessor.h"
#include "../../modules/factorization/alternatingLeastSquares/NonNegativeFactorization.h"
#include "../../modules/classificator/Classificator.h"

#define VECTOR_ROWS 784

using namespace std;

int main() {
    TimeHelper* timeHelper = new TimeHelper();
    try {
        FileHelper *fileHelper = new FileHelper();
        Learning *learning = new Learning();
        ImageProcessor *imageProcessor = new ImageProcessor();
        NonNegativeFactorization *factorization = new NonNegativeFactorization();
        Classificator *classificator  = new Classificator();

        timeHelper->start();

        char* fileName = "/Users/joaogolias/Documents/Personal Projects/C++/digit-classificator/train.txt";
        int n_dig_treino = 100;
        Matrix **matrices = fileHelper->readSampleMatrixes(fileName, n_dig_treino);
        
        cout << endl << "rows: " << matrices[0]->rows << endl << matrices[0]->columns << endl;

        cout << "LEU" << endl;

        Matrix* vectors = imageProcessor->joinVectors(matrices, n_dig_treino);
    
        imageProcessor->normalize(vectors);

        cout << "PROCESSOU"  << endl;
        Matrix* W = learning->execute(vectors, n_dig_treino, 10);

        cout << "APRENDEU" << endl;
        Matrix **images = learning->getImages(W, 28, 28, 10);

        cout << "PEGOU" << endl;
        timeHelper->end();

        cout << "Time to run it all" << endl << endl << endl << endl;
        cout << timeHelper->generateStringTime() << endl;

        // for(int i = 0; i <10; i++){
        //     cout << endl << endl << "MATRIZ " << i + 1  << endl << endl;
        //     images[i]->print();
        // }

        fileName = "/Users/joaogolias/Documents/Personal Projects/C++/digit-classificator/image-tests.txt";
        
        Matrix **matrices1 = fileHelper->readSampleMatrixes(fileName, 6);
        
        imageProcessor->normalize(matrices1[0]);
        Matrix * x = classificator->classificate(W, matrices1[0]);
        x->print();

        cout << "Para o 7: " << matrices1[0]->subtract(W->multiply(x))->euclideanNomr() << endl;

        imageProcessor->normalize(matrices1[1]);
        x = classificator->classificate(W, matrices1[1]);
        cout << "Para o 2: " << matrices1[1]->subtract(W->multiply(x))->euclideanNomr() << endl;
        // imageProcessor->regenerateMatrix(matrices1[1], 28, 28)->print();

        imageProcessor->normalize(matrices1[2]);
        x = classificator->classificate(W, matrices1[2]);
        cout << "Para o 1: " << matrices1[1]->subtract(W->multiply(x))->euclideanNomr() << endl;

        imageProcessor->normalize(matrices1[3]);
        x = classificator->classificate(W, matrices1[3]);
        cout << "Para o 0: " << matrices1[1]->subtract(W->multiply(x))->euclideanNomr() << endl;

        imageProcessor->normalize(matrices1[4]);
        x = classificator->classificate(W, matrices1[4]);
        cout << "Para o 4: " << matrices1[1]->subtract(W->multiply(x))->euclideanNomr() << endl;

        imageProcessor->normalize(matrices1[5]);
        x = classificator->classificate(W, matrices1[5]);
        cout << "Para o 1: " << matrices1[1]->subtract(W->multiply(x))->euclideanNomr() << endl;

        return 0;
    } catch(std::invalid_argument* e) {
        timeHelper->end();
        cout << timeHelper->generateStringTime() << endl;
        return 0;
    }

    return 0;

}

