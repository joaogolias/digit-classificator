#include "TestManager.h"
#include "../../src/modules/basic/matrix/Matrix.h"

#include <iostream>

using namespace std;
TestManager::~TestManager() {}

TestManager::TestManager() {}


TestManager* TestManager::assertEquals(Testable* actual, Testable* expected){
    if(actual->isEqualsTo(expected)){
        testResult = testResult && true;
    } else {
        testResult = testResult && false;
    }
    return this;
}

void TestManager::result() {
    if(testResult) {
        cout << "Test passed successfully" << endl;
    } else {
        cout << "Test failed :(" << endl;
    }
}

void TestManager::assertEquals(bool actual,bool expected){
    if(actual == expected){
        cout << "Test passed successfully" << endl;
        return;
    }
    
    cout << "Test failed :(" << endl;
}

