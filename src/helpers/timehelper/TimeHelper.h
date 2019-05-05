#ifndef TIMEHELPER_H
#define TIMEHELPER_H

#include <time.h>

class TimeHelper {
    public: 
        TimeHelper();
        ~TimeHelper();
        
        TimeHelper *start();
        TimeHelper *end();

        double calculateSpentTime();
        
        char* generateStringTime();

    private: 
        clock_t startTime;
        clock_t endTime;
        bool isInEndState;
        bool isEndStateValid(bool expected);
};

#endif