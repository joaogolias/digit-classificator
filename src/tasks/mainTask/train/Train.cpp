#include <iostream>
#include <string>
#include "Train.h"
#include "../../../helpers/filehelper/FileHelper.h"
#include "../../../helpers/timeHelper/TimeHelper.h"
#include "../../../modules/learning/Learning.h"
#include "../../../modules/imageProcessor/ImageProcessor.h"
#include "../../../modules/factorization/alternatingLeastSquares/NonNegativeFactorization.h"
#include "../../../modules/classificator/Classificator.h"


using namespace std;


Train::Train(){}

Train::~Train(){}

Matrix** Train::execute(int ndig_train, int p){
    cout << "Número de digitos para treino: " << ndig_train << endl;
    cout << "Número de colunas da decomposição de A [p]: " << p << endl;

    Matrix** result = new Matrix*[ndig_train];
    Matrix** vectors;
    
    Matrix* A;
    Matrix* W;
    
    FileHelper* fileHelper = new FileHelper();
    ImageProcessor* processor = new ImageProcessor();
    TimeHelper *timeHelper = new TimeHelper();
    Learning *learning = new Learning();
    
    string fileName = "/Users/joaogolias/Documents/Personal Projects/C++/digit-classificator/train.txt";
    for(int i = 0; i < 10; i++){
        fileName = string("/Users/joaogolias/Documents/Personal Projects/C++/digit-classificator/"); 
        fileName += string("train_dig") + to_string(i) ;
        fileName += string(".txt");

        timeHelper->start();
        
        vectors = fileHelper->readSampleMatrixes(&fileName[0], ndig_train); 
        
        timeHelper->end();
        double timeToRead = timeHelper->calculateSpentTime();

        cout << endl << endl << "Tempo para ler os arquivos do dígito " << i << ": ";
        cout << timeToRead << endl;

        timeHelper->start();

        Matrix* matrix = processor->joinVectors(vectors, ndig_train);
        processor->normalize(matrix);

        W = learning->execute(matrix, ndig_train, p);
        
        timeHelper->end();
        double timeToLearn = timeHelper->calculateSpentTime();

        cout << "Tempo para aprendizagem do dígito " << i << ": ";
        cout << timeHelper->generateStringTime(timeToRead) << endl;
    }
    
    return result;
}