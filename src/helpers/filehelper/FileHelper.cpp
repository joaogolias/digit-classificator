#include "FileHelper.h"
#include "../../modules/imageProcessor/ImageProcessor.h"

#include <string>
#include <fstream>
#include <iostream>

using namespace std;


FileHelper::FileHelper(){
}

FileHelper::~FileHelper(){}

Matrix** FileHelper::readSampleMatrixes(char* name, int ndig_treino) {
    Matrix** matrices = new Matrix*[ndig_treino];
    for (int k = 0; k < ndig_treino; k++) {
        matrices[k] = new Matrix(VECTOR_ROWS_QUANTITY, 1);
    }
    if(checkFileExists(name)){
        input.open(name);

        char fileContent;
        int totalReadNUmbersQuantity = 0;
        int readRows = 0;
        int row = 0;
        
        while(input.get(fileContent)){
            if(readRows < ndig_treino) {
                int num;
                input >> num;
                matrices[readRows]->set(row, 0, (int)num);
                readRows++;
                totalReadNUmbersQuantity++;
            }
            if(fileContent == '\n'){
                readRows=0;
                row++;
            }
        }

    } 
    input.close();
    return matrices;
}

bool FileHelper::checkFileExists(char* name) {
    input.open (name);
    if(input.good()) {
        input.close();
        return true;
    } else {
        cout << "file does not exist" << endl;
        input.close();
        return false;
    }
}