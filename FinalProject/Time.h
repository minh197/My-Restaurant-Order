//
// Created by username on 4/12/2021.
//

#ifndef DOMINATO_S_FINAL_PROJECT_TIME_H
#define DOMINATO_S_FINAL_PROJECT_TIME_H

#include <iostream>
#include <string>
using namespace std;

class Time
{
public:
    /**
     @pre None.
     @post Creates time with default values for data members.
     */
    Time();  //Default Constructor

    /**
     @pre 0 <= hour <= 23 AND 0 <= min <= 59.
     @post Creates time with given hour and minutes.
     * @param hour
     * @param min
     */
    Time(int hours, int min) throw (logic_error);

    /**
     @pre None.
     * @param t1
     * @param t2
     * @return Difference in minutes between t1 and t2.
     */
    static int elapsedMin(Time t1, Time t2);

    /**
     @pre None.
     * @return String containing hour and the minutes.
     */
    string toString();

    int hour;
    int minute;
};

#endif //DOMINATO_S_FINAL_PROJECT_TIME_H
