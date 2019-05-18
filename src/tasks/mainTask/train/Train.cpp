#include <iostream>
#include <string>
#include "Train.h"
#include "../../../helpers/filehelper/FileHelper.h"
#include "../../../helpers/timehelper/TimeHelper.h"
#include "../../../modules/learning/Learning.h"
#include "../../../modules/imageprocessor/ImageProcessor.h"
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
    TimeHelper *timehelper = new TimeHelper();
    Learning *learning = new Learning();
    
    string fileName = "/Users/joaogolias/Documents/Personal Projects/C++/digit-classificator/train.txt";
    for(int i = 0; i < 10; i++){
        fileName = string("/Users/joaogolias/Documents/Personal Projects/C++/digit-classificator/"); 
        fileName += string("train_dig") + to_string(i) ;
        fileName += string(".txt");

        timehelper->start();
        
        vectors = fileHelper->readSampleMatrixes(&fileName[0], ndig_train); 
        
        timehelper->end();
        double timeToRead = timehelper->calculateSpentTime();

        cout << endl << endl << "Tempo para ler os arquivos do dígito " << i << ": ";
        cout << timeToRead << endl;

        timehelper->start();

        A = processor->joinVectors(vectors, ndig_train);
        processor->normalize(A);

        W = learning->execute(A, ndig_train, p);
        
        timehelper->end();
        double timeToLearn = timehelper->calculateSpentTime();

        cout << "Tempo para aprendizagem do dígito " << i << ": ";
        cout << timehelper->generateStringTime(timeToRead) << endl;

        result[i] = W;
    }
    
    delete A;
    delete W; 

    delete fileHelper;
    delete processor;
    delete timehelper;
    delete learning;

    // for(int i = 0; i < 784; i++) {
    //     delete vectors[i];
    // }
    
    return result;
}