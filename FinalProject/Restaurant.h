//
// Created by Minh Nguyen on 4/16/21.
//

#ifndef FINALPROJECT_RESTAURANT_H
#define FINALPROJECT_RESTAURANT_H
#include "iostream"
#include "deque"
#include "string"
#include <vector>
#include "Order.h"
#include "Driver.h"
#include "Time.h"
using namespace std;

class Restaurant{
//The Restaurant class keeps track of all drivers and orders in the system,
// including logged-out drivers and completed orders.
public:
    /* Create an empty restaurant
    @pre: none
    @post: Create an initial restaurant without any orders/drivers */
    Restaurant();

    /*
    @pre: none
    @post: Prints status of orders and logged-in drivers, as specified by the “status” command description. */
    void status() const;

    /*
    @pre: none
    @post:Prints summary statistics on orders and drivers, as specified by the “summary” command description.  */
    void summary() const;

    //Pre: None
    //Post: Adds the given order to the system, enqueuing it for ordersCooking.
    void addOrder(Order* order) ;
    /*
     @pre: a driver must be logged in
     @post: If a driver with the given name exists within the system (logged in or not),
     returns a pointer to that driver. Otherwise, returns a null pointer.
     */
    Driver * getDriver(string name);

    void addDriver(Driver* driver);
    /*
     @pre:  ordersCooking is not empty
     @post: remove the oldest order from the ordersCooking queue, set it to departure
     */
    void serveNextOrder() throw (logic_error);

    //Pre: The departure queue is not empty.
    //Post: Removes the oldest order from the departure queue and returns it.
    Order* departNextOrder(Driver* driver, Time time) throw (logic_error);

    //Pre: None
    //Post: The order carried by the driver is delivered at the given time. The driver receives the given tip.
    void deliver(Driver* driver, Time time, float tip);

    float averageOrderTime() const;




private:
    deque<Order*> orders; //cooking queue
    deque<Order*> delivery; //delivery queue
    vector <Driver*> driver_List; // a vector contains a list of driver


    int numOfOrders;
    int numOfServedOrders; //orders that are served

    int totalOrder;
    int totalOrderTime;

};





#endif //FINALPROJECT_RESTAURANT_H
