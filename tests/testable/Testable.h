#ifndef TESTABLE_H
#define TESTABLE_H

class Testable {
    public:
        virtual bool isEqualsTo(Testable* compareObject) = 0;
};

#endif