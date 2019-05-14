#include "../../../src/helpers/timehelper/TimeHelper.h"
#include "../../testmanager/TestManager.h"
#include <iostream>
#include <stdexcept>

using namespace std;

TimeHelper *timeHelper = new TimeHelper();
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
    timeHelper->start();
    double j;
    for(long i = 0; i <1000000; i++) {
       for(long j = 0; j < 100000; j++) {

       }
    }
    timeHelper->end();
    cout << "Time spent to run this loop is: ";
    cout << timeHelper->generateStringTime() << endl;
}

void testCallingEndWithoutStart() {
    bool anErrorOccurred = false;
    try {
        timeHelper->end();
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
        timeHelper->start();
        timeHelper->end();
        timeHelper->end();
    } catch(std::domain_error &e) {
        anErrorOccurred = true;
    }

    cout << "Testing if an error is thrown if end() function is called twice consecutively: ";
    testManager
        -> assertEquals(anErrorOccurred, true)
        -> result();
}