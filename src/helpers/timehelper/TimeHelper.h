#ifndef TIMEHELPER_H
#define TIMEHELPER_H

#include <time.h>

class TimeHelper {
    public: 
        TimeHelper();
        ~TimeHelper();
        
        TimeHelper *start();
        TimeHelper *end();

        double calculateSpentTime(double offset = 0.0);
        
        char* generateStringTime(double offset = 0.0);

    private: 
        clock_t startTime;
        clock_t endTime;

        bool isInEndState;
        bool checkState(bool expected);
};

#endif