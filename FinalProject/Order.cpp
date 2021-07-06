//
// Created by username on 4/12/2021.
//

#include "Order.h"


using namespace std;

Order::Order() {
    Time the_time;
    ordered = the_time;
    deliver = the_time;
    information = "";
    hasDeparted = 0;
}


Order::Order(Time time, string info) {
    Time the_time;
    ordered = time;
    deliver = the_time;
    information = info;
    hasDeparted = 0;
}


void Order::departed() throw(logic_error) {
    if (hasDeparted == 1) {
        throw (logic_error("The order had already departed!"));
    }
    hasDeparted = 1;
}


void Order::delivered(Time time) {
    deliver = time;
}


int Order::getMinToDelivery() {
    return Time::elapsedMin(ordered, deliver);
}


string Order::toString() {
    string finalOrder = "";
    finalOrder += ordered.toString() + " ";
    if (hasDeparted) {
        finalOrder += " (Out for delivery!) ";
    } else{
        finalOrder += " (Order is cooking!) ";
    }
    finalOrder += information;
    Time theTime;
    if (Time::elapsedMin(deliver, theTime) == 0) {
        finalOrder += " (The order has not been delivered!) ";
    } else{
        finalOrder += " (Order has been delivered!) ";
    }
    return finalOrder;
}

