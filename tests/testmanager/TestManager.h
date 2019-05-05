#ifndef TESTMANAGER_H
#define TESTMANAGER_H
#include "../testable/Testable.h"

class TestManager {
    bool testResult = true;
    public:
       TestManager* assertEquals(Testable* actual, Testable* expected);
       TestManager*  assertEquals(bool actual, bool expected);
       TestManager*  assertEquals(double actual, double expected);
       void result();
       TestManager();
       ~TestManager();
};

#endif
