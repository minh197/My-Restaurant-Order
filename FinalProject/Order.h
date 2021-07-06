//
// Created by username on 4/12/2021.
//

#ifndef DOMINATO_S_FINAL_PROJECT_ORDER_H
#define DOMINATO_S_FINAL_PROJECT_ORDER_H

#include <iostream>
#include <string>
#include "Time.h"
using namespace std;

class Order
{
public:
    /**
     @pre None
     @post Creates order with default values for data members.
     */
    Order();  //Default Constructor

    /**
     @pre None
     @post Creates order with given order time and information.
     * @param time
     * @param info
     */
    Order(Time time, string info);

    /**
     @pre Order is at restaurant.
     @post Order is out for delivery.
     */
     void departed() throw (logic_error);

     /**
      @pre Order is out for delivery.
      @post Order has been delivered. The time it was delivered has been recorded.
      * @param time
      */
     void delivered(Time time);

     /**
      @pre Order has been delivered.
      * @return Minutes until order has been delivered.
      */
     int getMinToDelivery();

     /**
      @pre None.
      * @return A string containing order time and other information.
      */
     string toString();

    /* Show the infor of delivering number
   @pre: Driver is delivering.
   @post: Returns the order being delivered.  */

     Time ordered;
     Time deliver;
     bool hasDeparted;
     string information;
};

#endif //DOMINATO_S_FINAL_PROJECT_ORDER_H
