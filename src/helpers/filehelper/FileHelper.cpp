#include "FileHelper.h"
#include "../../modules/imageprocessor/ImageProcessor.h"

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
    if(checkFileExists(string(name))){
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

bool FileHelper::checkFileExists(string name) {
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

void FileHelper::writeFile(string name, string content){
    output.open(name);
    output << content;
    output.close();
}

Matrix* FileHelper::readSampleMatrix(char* name, int ndig_treino, bool normalize){
    //  Matrix** matrices = new Matrix*[ndig_treino];
    // for (int k = 0; k < ndig_treino; k++) {
    //     matrices[k] = new Matrix(VECTOR_ROWS_QUANTITY, 1);
    // }

    Matrix* matrix = new Matrix(VECTOR_ROWS_QUANTITY, ndig_treino);
    if(checkFileExists(string(name))){
        input.open(name);

        char fileContent;
        int totalReadNUmbersQuantity = 0;

        int i = 0;
        int j = 0;
        
        while(input.get(fileContent)){
            if(j < ndig_treino) {
                int num;
                input >> num;
                if(normalize)  matrix->set(i,j,((int) num/255.0));
                else matrix->set(i,j,(int)num);
                j++;
                totalReadNUmbersQuantity++;
            }
            if(fileContent == '\n'){
                j=0;
                i++;
            }
        }

    } 
    input.close();
    return matrix;
}