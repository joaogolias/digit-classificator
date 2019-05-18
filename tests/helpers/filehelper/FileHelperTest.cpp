#include "../../../src/helpers/filehelper/FileHelper.h"
#include "../../testmanager/TestManager.h"
#include "../../../src/modules/imageprocessor/ImageProcessor.h"


#include <iostream>

using namespace std;

FileHelper* fileHelper;
TestManager* testManager;
void fileExistsTest();
void fileDoesNotExistTest();

void readSampleMatricesTest();

int main(){
    fileHelper = new FileHelper();
    testManager = new TestManager();
    
    fileExistsTest();
    fileDoesNotExistTest();

    readSampleMatricesTest();
}

void fileExistsTest(){
    cout << endl << "1. ";
    cout << "Should return true if a file does exists: ";
    char* fileName = "/Users/joaogolias/Documents/Personal Projects/C++/digit-classificator/test1.txt";
    testManager
            ->assertEquals(fileHelper->checkFileExists(fileName), true)
            ->result();
}
void fileDoesNotExistTest(){
    cout << "2. ";
    cout << "Should return false if a file does not exist: ";
    char* fileName = "test2.txt";
    testManager
        ->assertEquals(fileHelper->checkFileExists(fileName), false)
        ->result();
}

void readSampleMatricesTest(){
    cout << "3. ";
    cout << "Should read a matrix: ";
    char* fileName = "/Users/joaogolias/Documents/Personal Projects/C++/digit-classificator/train.txt";
    Matrix **matrices = fileHelper->readSampleMatrixes(fileName, 20);

    testManager
        ->result();
}