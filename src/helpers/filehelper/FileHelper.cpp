#include "FileHelper.h"

#include <string>
#include <fstream>
#include <iostream>

using namespace std;


FileHelper::FileHelper(){
}

FileHelper::~FileHelper(){}

Matrix** FileHelper::readSampleMatrixes(char* name, int ndig_treino) {
    Matrix** matrices = new Matrix*[ndig_treino];
    cout << name << endl;    
    if(checkFileExists(name)){
        int i = 0;
        string line;
        int maxSize = 0;
        cout << "file exists" << endl;
        while(fs.eof()) {
            getline(fs, line);
            cout << line.size() << endl;
        }
    } 
    return matrices;
}

bool FileHelper::checkFileExists(char* name) {
    fs.open (name);
    if(fs.good()) {
        return true;
    } else {
        cout << "file does not exist" << endl;
        return false;
    }
}