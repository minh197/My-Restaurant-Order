//
// Created by hkoh on 4/12/2021.
//
#include <iostream>
#include "Order.h"
#include "Time.h"
using namespace std;

#ifndef FINALPROJECT_DRIVER_H
#define FINALPROJECT_DRIVER_H

class Driver {
public:
    //Pre: None
    //Post: Creates a driver with a name
    Driver (string name);

    //Pre: Cannot be logged in
    //Post: Driver is now logged in
    void login () throw (logic_error);

    //Pre: Cannot be logged out
    //Post: Driver is now logged out
    void logout () throw (logic_error);

    //Pre: Has to be at resturant
    //Post: Driver is no longer at resturant, time left is recorded and order contents are stored
    void departed (Time t, Order contents) throw (logic_error);

    //Pre: Driver is delivering, tip is 0 or greater
    //Post: Driver is no longer delivering
    void delivered (Time t, float tip);

    //Pre: Driver is not at resturaunt and noe delivering
    //Post: Driver is at resturaunr
    void arrived (Time t);

    //Pre: None
    //Post: number of delieveries made is returned
    int totalDeliveries();

    //Pre: None
    //Post: Returns time spent driving to delivery address
    int timeDelivering();

    //Pre: None
    //Post: Returns time spent returning to restaurant
    int timeReturning();

    //Pre: None
    //Post: Returns true if driver is logged in; else returns false
    bool isLoggedin();

    //Pre: None
    //Post: Returns true if the driver is on delivery; else, returns false
    bool isOnDelivery();

    //Pre: None
    //Post: Returns if the driver is logged in, else states driver is not, and if driver is on delivery,
            //returns that driver is on delivery and what order information the driver has.
    string toString();

    //Pre: None
    //Post: Returns the amount of tips a driver has
    float totalTip();

    //Pre: None
    //Post: Returns the drivers name
    string getName();

    //Pre: None
    //Post: Returns the order the driver has
    Order getOrder() throw (logic_error);



private:
    string driverName;
    Order orderInfo;
    bool isLogged;
    bool onDelivery; //true if the driver is on delivery, otherwise it is false
    float tipTotal;
    bool atRestaurant;
    int deliveries;
    float delivering;
    Time atDelivery;
    int back;
    Time start;
};






#endif //FINALPROJECT_DRIVER_H
