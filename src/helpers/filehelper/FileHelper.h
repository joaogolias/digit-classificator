#ifndef FILEHELPER_H
#define FILEHELPER_H
#include "../../modules/basic/matrix/Matrix.h"
#include <fstream>
#include <iostream>

using namespace std;

class Matrix; 

class FileHelper {
    ifstream input;
    
    public:
        FileHelper();
        ~FileHelper();
        Matrix** readSampleMatrixes(char* name, int ndig_treino);
        // void writeFile(char* name, char* content, bool overrideFile);
        bool checkFileExists(char* name);
        const int VECTOR_ROWS_QUANTITY = 784;
};
#endif