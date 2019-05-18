#ifndef FILEHELPER_H
#define FILEHELPER_H
#include "../../modules/basic/matrix/Matrix.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Matrix; 

class FileHelper {
    ifstream input;
    ofstream output;
    
    public:
        FileHelper();
        ~FileHelper();
        Matrix** readSampleMatrixes(char* name, int ndig_treino);
        void writeFile(string name, string content);
        bool checkFileExists(string name);
        const int VECTOR_ROWS_QUANTITY = 784;
};
#endif