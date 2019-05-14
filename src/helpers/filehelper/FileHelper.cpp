#include "FileHelper.h"

#include <fstream>
#include <iostream>

using namespace std;


FileHelper::FileHelper(){
    cout << "oi";
}

FileHelper::~FileHelper(){}

// char* FileHelper::readFile(char* name){

// }

bool FileHelper::checkFileExists(char* name) {
    fstream fs;
    fs.open (name);
    if(fs.good()) {
        return true;
    } else {
        return false;
    }
}