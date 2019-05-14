#include "../../../src/helpers/filehelper/FileHelper.h"
#include "../../testmanager/TestManager.h"

#include <iostream>

using namespace std;

FileHelper* fileHelper;
TestManager* testManager;
void fileExistsTest();
void fileDoesNotExistTest();

int main(){
    fileHelper = new FileHelper();
    testManager = new TestManager();
    
    fileExistsTest();
    fileDoesNotExistTest();
}

void fileExistsTest(){
    cout << endl << "1. ";
    cout << "Should return true if a file does exists: ";
    char* fileName = "test.txt";
    testManager
            ->assertEquals(fileHelper->checkFileExists(fileName), true)
            ->result();
}
void fileDoesNotExistTest(){
    cout << "1. ";
    cout << "Should return false if a file does not exist: ";
    char* fileName = "test1.txt";
    testManager
        ->assertEquals(fileHelper->checkFileExists(fileName), false)
        ->result();
}