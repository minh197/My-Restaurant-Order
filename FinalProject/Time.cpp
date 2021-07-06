//
// Created by username on 4/12/2021.
//

#include "Time.h"
#include <cmath>
#include <string>

using namespace std;

Time::Time() {
    hour = 0;
    minute = 0;
}

Time::Time(int hours, int min) throw(logic_error) {
    if (hours >= 0 && min >= 0 && hours < 24 && min < 60) {
        hour = hours;
        minute = min;
    } else {
        throw(logic_error("The time is not correct!"));
    }
}

int Time::elapsedMin(Time t1, Time t2) {
    if (t2.hour > t1.hour) {
        int elapsedHour = t2.hour - t1.hour;
        int elapsedMinute = (t2.minute + 60) - t1.minute;
        elapsedMinute += elapsedHour * 60;
        return elapsedMinute;
    }
    else {
        int elapsedHour = pow(sqrt(t2.hour - t1.hour), 2);
        int elapsedMinute = pow(sqrt(t2.minute - t1.minute), 2);
        elapsedMinute += elapsedHour * 60;
        return elapsedMinute;
    }
}

string Time::toString() {
    string theHour;
    if (hour < 10) {
        theHour = "0" + to_string(hour);
    } else{
        theHour = to_string(hour);
    }
    string theMinute;
    if (minute < 10) {
        theMinute = "0" + to_string(minute);
    } else{
        theMinute = to_string(minute);
    }
    return theHour + ":" + theMinute;
}



