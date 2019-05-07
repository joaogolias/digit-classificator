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
    ifstream reader(name);
    cout << "kkkk" << endl;
    if(reader.is_open()) {
        return true;
    } else {
        return false;
    }
}