#include "TestManager.h"
#include "../../src/modules/basic/matrix/Matrix.h"

#include <iostream>
#include <math.h>

using namespace std;

TestManager::~TestManager() {}

TestManager::TestManager() {}

void TestManager::result() {
    if(testResult) {
        cout << "Test passed successfully" << endl;
    } else {
        cout << "Test failed :(" << endl;
    }
}

TestManager* TestManager::assertEquals(Testable* actual, Testable* expected){
    testResult = testResult && (actual->isEqualsTo(expected));
    return this;
}

TestManager* TestManager::assertEquals(bool actual,bool expected){
    testResult = testResult && (actual == expected);
    return this;
}

TestManager* TestManager::assertEquals(double actual, double expected){
    testResult = testResult && abs(actual - expected) < 0.000001;
    return this;
}

