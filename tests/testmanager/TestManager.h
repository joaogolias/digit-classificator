#ifndef TESTMANAGER_H
#define TESTMANAGER_H
#include "../comparable/Comparable.h"

class Comparable; 

class TestManager {
    bool testResult = true;
    public:
       TestManager* assertEquals(Comparable* actual, Comparable* expected);
       TestManager*  assertEquals(bool actual, bool expected);
       TestManager*  assertEquals(double actual, double expected);
       void result();
       TestManager();
       ~TestManager();
};

#endif
