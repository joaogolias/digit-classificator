#ifndef FILEHELPER_H
#define FILEHELPER_H
#include "../../modules/basic/matrix/Matrix.h"
#include <fstream>
#include <iostream>
#include <string>

#define VECTOR_ROWS_QUANTITY 784

using namespace std;

class Matrix; 

class FileHelper {
    ifstream input;
    ofstream output;
    
    public:
        FileHelper();
        ~FileHelper();
        Matrix** readSampleMatrixes(char* name, int ndig_treino);
        Matrix* readSampleMatrix(char* name, int ndig_treino, bool normalize = false, int rowsQuantity = VECTOR_ROWS_QUANTITY);
        void writeFile(string name, string content);
        bool checkFileExists(string name);
};
#endif