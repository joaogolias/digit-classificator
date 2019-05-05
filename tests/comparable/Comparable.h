#ifndef TESTABLE_H
#define TESTABLE_H

class Comparable {
    public:
        virtual bool isEqualsTo(Comparable* compareObject) = 0;
        virtual bool isEqualsTo(Comparable* compareObject, double error) = 0;
};

#endif