#include <iostream>
#include <string>
#include "Train.h"
#include "../../../helpers/filehelper/FileHelper.h"
#include "../../../helpers/timehelper/TimeHelper.h"
#include "../../../modules/learning/Learning.h"
#include "../../../modules/imageprocessor/ImageProcessor.h"
#include "../../../modules/factorization/alternatingLeastSquares/NonNegativeFactorization.h"


using namespace std;


Train::Train(){}

Train::~Train(){}

Matrix** Train::execute(int ndig_train, int p, string* text){
    // executa o treino dos números
    *text += "*******************************************************************\n";
    *text += string("Número de digitos para treino: ") + to_string(ndig_train) + string("\n");
    *text += string("Número de colunas da decomposição de A [p]: ") + to_string(p) + string("\n\n\n");

    Matrix** result = new Matrix*[ndig_train];
    
    Matrix* A;
    Matrix* W;
    
    FileHelper* fileHelper = new FileHelper();
    ImageProcessor* processor = new ImageProcessor();
    TimeHelper *timehelper = new TimeHelper();
    Learning *learning = new Learning();
    
    string fileName = "./train.txt";
    
    for(int i = 0; i < 10; i++){
        // monta o nome padrã de arquivo de entrada de treino
        fileName = string("./"); 
        fileName += string("train_dig") + to_string(i) ;
        fileName += string(".txt");

        timehelper->start();
        
        // lê o arquivo e guarda informações na matriz A, dado uma quantidade de número
        // de dígitos de treino
        A = fileHelper->readSampleMatrix(&fileName[0], ndig_train); 
        
        timehelper->end();
        double timeToRead = timehelper->calculateSpentTime();

        // gera a string para montar o arquivo com as informações de treinamento
        *text += string("Tempo para ler os arquivos do dígito ") + to_string(i) + string(": ");
        *text += timehelper->generateStringTime() + string("\n");

        timehelper->start();

        // executa o treinamento/aprendizagem
        W = learning->execute(A, ndig_train, p);
        
        timehelper->end();
        double timeToLearn = timehelper->calculateSpentTime();

        *text += string("Tempo para aprendizagem do dígito ") + to_string(i) + string(": ");
        *text += timehelper->generateStringTime() + string("\n\n");

        cout << "Treinamento do digito " << i << " finalizado em " << timehelper->generateStringTime(timeToRead) << endl;
        result[i] = W;

        delete A;
    }

    delete fileHelper;
    delete processor;
    delete timehelper;
    delete learning;
    
    return result;
}