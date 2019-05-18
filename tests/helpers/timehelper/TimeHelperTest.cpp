#include "../../../src/helpers/timehelper/TimeHelper.h"
#include "../../testmanager/TestManager.h"
#include <iostream>
#include <stdexcept>

using namespace std;

TimeHelper *timehelper = new TimeHelper();
TestManager *testManager = new TestManager();

void firstTest();
void testCallingEndWithoutStart();
void testTwoConsecutivesEnds();


int main() {
    cout << "1. ";
    firstTest();

    cout << "2. ";
    testCallingEndWithoutStart();

    cout << "3. ";
    testTwoConsecutivesEnds();
}

void firstTest() {
    timehelper->start();
    double j;
    for(long i = 0; i <1000000; i++) {
       for(long j = 0; j < 100000; j++) {

       }
    }
    timehelper->end();
    cout << "Time spent to run this loop is: ";
    cout << timehelper->generateStringTime() << endl;
}

void testCallingEndWithoutStart() {
    bool anErrorOccurred = false;
    try {
        timehelper->end();
    } catch(std::domain_error &e) {
        anErrorOccurred = true;
    }
    cout << "Testing if an error is thrown if end() function is called whithout calling start() function: ";
    testManager
        -> assertEquals(anErrorOccurred, true)
        -> result();

}

void testTwoConsecutivesEnds() {
    bool anErrorOccurred = false;
    try {
        timehelper->start();
        timehelper->end();
        timehelper->end();
    } catch(std::domain_error &e) {
        anErrorOccurred = true;
    }

    cout << "Testing if an error is thrown if end() function is called twice consecutively: ";
    testManager
        -> assertEquals(anErrorOccurred, true)
        -> result();
}