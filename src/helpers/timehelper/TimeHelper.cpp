#include "TimeHelper.h"
#include <iostream>
#include <stdexcept>
#include <time.h>
#include <string>

using namespace std;

TimeHelper::TimeHelper(){
    isInEndState = false;
}

TimeHelper::~TimeHelper(){}

bool TimeHelper::checkState(bool expected) {
    if(isInEndState == expected) {
        return true;
    } else {
        string reason;
        if(expected == true) {
            reason = "End state must be in end state";
        } else {
            reason = "End state must not be in end state";
        }
        throw std::domain_error(reason.c_str());
    }
}

TimeHelper* TimeHelper::start() {
    startTime = clock();
    isInEndState = false;
    return this;
}

TimeHelper* TimeHelper::end() {
    if(checkState(false)) {
        endTime = clock();
        isInEndState = true;
    }
    return this;
}

double TimeHelper::calculateSpentTime(double offset) {
    double finalValue = offset;
    if(checkState(true)){
        finalValue +=  ((double) (endTime - startTime)) / CLOCKS_PER_SEC;
    }
    return finalValue;
}

char* TimeHelper::generateStringTime(double offset) {
    static char stringTime[100] = "";
    if(checkState(true)){
        double spentTime = calculateSpentTime(offset);
        if(spentTime < 60) {
            strcpy(stringTime, std::to_string(spentTime).c_str());
            strcat(stringTime, " seconds");
        } else if (spentTime < 60*60) {
            int minutes = (int) spentTime/60;
            double seconds = (spentTime/60-minutes)*60;
            strcpy(stringTime, std::to_string(minutes).c_str());
            strcat(stringTime, " minutes and ");
            strcat(stringTime, std::to_string(seconds).c_str());
            strcat(stringTime, " seconds");
        } else if(spentTime < 24*60*60) {
            int hours = (int) spentTime/(60*60);
            double decimalMinutes = (spentTime/(60*60) - hours)*60;
            int minutes = (int) decimalMinutes;
            double seconds = (decimalMinutes - minutes)*60;
            strcpy(stringTime, std::to_string(hours).c_str());
            strcat(stringTime, " hours and ");
            strcat(stringTime, std::to_string(minutes).c_str());
            strcat(stringTime, " minutes and ");
            strcat(stringTime, std::to_string(seconds).c_str());
            strcat(stringTime, " seconds");
        }
    }
    return stringTime;
}







