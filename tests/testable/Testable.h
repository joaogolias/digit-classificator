#ifndef TESTABLE_H
#define TESTABLE_H

class Testable {
    public:
        virtual bool isEqualsTo(Testable* compareObject) = 0;
        virtual bool isEqualsTo(Testable* compareObject, double error) = 0;
};

#endif