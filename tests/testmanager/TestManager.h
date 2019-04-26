#ifndef TESTMANAGER_H
#define TESTMANAGER_H
#include "../testable/Testable.h"

class TestManager {
    public:
       void assertEquals(Testable* actual, Testable* expexted);
       TestManager();
       ~TestManager();
};

#endif
