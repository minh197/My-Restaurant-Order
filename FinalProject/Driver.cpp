//
// Created by hkoh on 4/12/2021.
//

#include "Driver.h"
#include <iostream>
using namespace std;

Driver :: Driver (string name) {
    driverName = name;
    tipTotal = 0.00;
    onDelivery = false;
    deliveries = 0;
    delivering = 0;
    isLogged = false;
}
void Driver :: login () throw (logic_error){
    if (!isLogged) {
        isLogged = true;
        atRestaurant = true;
    }
    else {
        throw logic_error ("Driver is already logged in.");
    }
}

void Driver :: logout () throw (logic_error) {
    if (isLogged == true) {
        isLogged = false;
        atRestaurant = false;
    }
    else {
        throw logic_error ("Driver is already logged out.");
    }
}

void Driver :: departed (Time t, Order contents) throw (logic_error) {
    if (atRestaurant == true) {
        atRestaurant = false;
        orderInfo = contents;
        start = t;
        onDelivery = true;
    }
    else {
        throw logic_error ("Driver is not at the restaurant and cannot take the order.");
    }
}

void Driver :: delivered (Time t, float money) {
    if(!isLoggedin()){
        cout << "Driver is not log-in" << endl;
    }
    else if(money < 0.0){
        cout <<" Tip has to be higher than 0.0 " << endl;
    }
    else if(!isOnDelivery()){
        cout << "Driver has not on delivery yet" << endl;
    }
    else{
        atDelivery = t;
        cout << "time elapsed : " << t.elapsedMin(start, t) << endl;
        delivering = delivering + (float)t.elapsedMin(start, t);
        tipTotal+=money;
        deliveries++;
    }

}

void Driver :: arrived (Time t) {
    back = back + t.elapsedMin(atDelivery, t);
    atRestaurant = true;
    onDelivery = false;
}

int Driver ::totalDeliveries() {
    return deliveries;
}

int Driver :: timeDelivering() {
    return delivering;
}

int Driver ::timeReturning() {
    return back;
}


bool Driver::isLoggedin() {
    return isLogged;
}
bool Driver::isOnDelivery() {
    return onDelivery;
}
string Driver::toString() {
    string driverInfo = "";
    if(isLogged){
        driverInfo.append(getName());
        driverInfo.append(" is logged in ");
    }
    else{
        driverInfo.append(getName());
        driverInfo.append(" is not logged in");
    }
    if(isOnDelivery()){
        driverInfo.append("and departed at") + orderInfo.toString();
    }
    return driverInfo;

}
float Driver::totalTip(){
    return tipTotal;
}
string Driver::getName() {
    return driverName;
}

Order Driver::getOrder() throw (logic_error) {

    if (!isOnDelivery()) {

        throw logic_error("The driver is not on the way to deliver yet.");

    } else {

        return orderInfo;

    }

}