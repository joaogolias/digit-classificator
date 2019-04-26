#include "TestManager.h"
#include "../../src/modules/basic/matrix/Matrix.h"

#include <iostream>

using namespace std;
TestManager::~TestManager() {}

TestManager::TestManager() {}


void TestManager::assertEquals(Testable* actual, Testable* expected){
    if(actual->isEqualsTo(expected)){
        cout << "Test passed successfully" << endl;
        return;
    }
    cout << "Test failed :(" << endl;
}
