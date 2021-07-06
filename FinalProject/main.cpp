#include <iostream>
#include "Restaurant.h"
#include <string>
using namespace std;

void print_help()
{
    cout << endl << "Commands:" << endl;
    cout << "  help : Print help" << endl;
    cout << "  login : Driver logs in" << endl;
    cout << "  logout : Driver logs out" << endl;
    cout << "  order : Adds new order. Time format: HH:MM" << endl;
    cout << "  serve : Order is now ready for delivery. Time format: HH:MM" << endl;
    cout << "  depart : Driver departs with next order for delivery. Time format: HH:MM" << endl;
    cout << "  deliver : Driver delivers order and receives tip. Time format: HH:MM" << endl;
    cout << "  arrive : Driver returns to restaurant. Time format: HH:MM" << endl;
    cout << "  status : Status of orders and drivers" << endl;
    cout << "  summary : Statistics of all drivers and orders" << endl;
    cout << "  quit : Terminates the program" << endl;
    cout << endl;
}

void login(string driver, Restaurant& arestaurant) {
    Driver* DriverPtr =  arestaurant.getDriver(driver);
    if (DriverPtr == nullptr) {
        Driver* aDriver = new Driver(driver);
        aDriver->login();
        arestaurant.addDriver(aDriver);
    }
    else
        cout << "The driver is already logged in" << endl;
}
void logout(string driver, Restaurant& brestaurant) {
    Driver* DriverPtr = brestaurant.getDriver(driver);
    if (DriverPtr == nullptr){
        cout << "Driver does not exist" << endl;
    }
    else if (!DriverPtr->isLoggedin()) {
        cout << "Driver is already logged out" << endl;
    }
    else{
        DriverPtr->logout();
    }
}
void serve(Time& time, Restaurant& crestaurant) {
    crestaurant.serveNextOrder();
    cout<<"Order is ready for delivery" <<endl;
}
void depart(const Time& time, string driver, Restaurant& drestuarant) {
    Driver* driverPtr = drestuarant.getDriver(driver);
    //Order* orderToDepart = drestuarant.departNextOrder(driverPtr, time);

    if (!driverPtr->isOnDelivery()) {
        drestuarant.departNextOrder(driverPtr, time);
        cout << "Driver has departed to deliver" << endl;
    }
    else if (driverPtr == nullptr){
        cout << "Driver does not exist" << endl;
    }
    else {
        cout << "Driver is already on delivery" << endl;
    }

}

void order(const Time& time, const string info, Restaurant& arestaurant) {
    Order* anOrder = new Order(time,info);
    arestaurant.addOrder(anOrder);
    cout<<"Order has been added" <<endl;
}

void arrive(const Time& time, string driver, Restaurant& arestuarant) {
    Driver* driverPtr = arestuarant.getDriver(driver);
    if (driverPtr->isOnDelivery()) {
        driverPtr->arrived(time);
        cout << "Driver has arrived back at the restaurant" << endl;
    }
    else if (driverPtr == nullptr) {
        cout << "Driver does not exist" << endl;
    }
    else {
        cout << "Driver has not yet been given an order and is still at the restaurant" << endl;
    }
}

void deliver (const Time& time, string driver, Restaurant& arestuarant, float tip) {
    Driver* driverPtr = arestuarant.getDriver(driver);
    //cout << "TESTING DELIVER TIME: " << time.toString() << endl;
    if (driverPtr->isOnDelivery()) {
        arestuarant.deliver(driverPtr,time,tip);
        cout << "Driver has delivered order" << endl;
    }
    else if (driverPtr == nullptr) {
        cout << "Driver does not exist" << endl;
    }
    else {
        cout << "Driver has not yet been given an order" << endl;
    }
}


int main() {

    string command;
    Restaurant pizzaRestaurant;
    string driver; //a string to hold the driver's name
    string orderName = "";

    int hour; //a string to hold time
    int minute;

    float tip; // holds tip amount

    string info; //a string to hold an order's info

    print_help();
    while(command!= "quit") {
        cout << endl;
        cout << "Please enter a command: " << endl;
        cin >> command;
        if (command == "login") {
            cout << "Please input driver's name" << endl;
            cin >> driver;
            login(driver, pizzaRestaurant);
            cout << driver << " is now logged in" << endl;
        } else if (command == "logout") {
            cout << "Please input driver's name" << endl;
            cin >> driver;
            logout(driver, pizzaRestaurant);
            cout << driver << " is now logged out" << endl;
        } else if (command == "order") {
            cout << "Please insert the hour order is made: " << endl;
            cin >> hour;
            cout << "Please insert the minute order is made: " << endl;
            cin >> minute;
            cout << "Please input the order contents and address without spaces: " << endl;
            cin >> orderName;
            cin.ignore();
            Time time(hour, minute);
            order(time, orderName, pizzaRestaurant);
        } else if (command == "serve") {
            cout << "Please insert the hour order is done cooking: " << endl;
            cin >> hour;
            cout << "Please insert the minute order is done cooking: " << endl;
            cin >> minute;
            Time time(hour, minute);
            serve(time, pizzaRestaurant);
        } else if (command == "depart") {
            cout << "Please insert the hour the driver departs: " << endl;
            cin >> hour;
            cout << "Please insert the minute the driver departs: " << endl;
            cin >> minute;
            cout << "Please input the driver's name: " << endl;
            cin >> driver;
            Time time(hour, minute);
            depart(time, driver, pizzaRestaurant);
        }
        else if (command == "deliver") {
            cout << "Please insert the hour the order arrives at its destination: " << endl;
            cin >> hour;
            cout << "Please insert the minute the order arrives at its destination: " << endl;
            cin >> minute;
            cout << "Please input the driver's name: " << endl;
            cin >> driver;
            cout << "Please input the tip amount: " << endl;
            cin >> tip;
            Time time (hour, minute);
            deliver(time, driver, pizzaRestaurant, tip);

        } else if (command == "arrive") {
            cout << "Please insert the hour the driver arrives back at the restaurant: " << endl;
            cin >> hour;
            cout << "Please insert the minute the driver arrives back at the restaurant: " << endl;
            cin >> minute;
            cout << "Please input the driver's name: " << endl;
            cin >> driver;
            Time time (hour, minute);
            arrive(time, driver, pizzaRestaurant);
        } else if (command == "status") {
            cout << "Restaurant status: " << endl;
            pizzaRestaurant.status();
        } else if (command == "summary") {
            cout << "Restaurant summary" << endl;
            pizzaRestaurant.summary();
        } else if (command == "help") {
            print_help();
        } else if (command == "quit") {
            cout << "Quitting Program..." << endl;
        } else {
                cout << "Not a valid command" << endl;
        }
    }
/*
    //create drivers and add to restaurant
    Restaurant pizzaRestaurant;
    Driver bob("Bob");
    Driver adam("Adam");
    pizzaRestaurant.addDriver(&bob);
    pizzaRestaurant.addDriver(&adam);
    Time time1(10, 00);
    Time time2(10, 15);
    Time time3(10, 30);
    Time time4(10, 45);
    Time time5(11, 00);
    Time time6(11, 15);
    Time time7(11, 30);
    Time time8 (11, 43);
    Time time9(11, 50);
    bob.login();
    adam.login();
    Order* order1 = new Order(time1, "2 cheese to 120 West Mango Lane");
    Order* order2 = new Order(time1, "7 goats to 140 Milner Avenue");
    Order* order3 = new Order(time2, "8 trucks to 123 Holden Hall");
    pizzaRestaurant.addOrder(order1);
    pizzaRestaurant.addOrder(order2);
    pizzaRestaurant.addOrder(order3);
    //Bob deliver the order
    pizzaRestaurant.serveNextOrder();
    pizzaRestaurant.departNextOrder(&bob, time2);
    pizzaRestaurant.deliver(&bob, time3, 5.0);
    bob.arrived(time4);
    cout << endl;
    pizzaRestaurant.status();
    //Adam deliver the order
    pizzaRestaurant.serveNextOrder();
    pizzaRestaurant.departNextOrder(&adam, time5);
    pizzaRestaurant.deliver(&adam, time6, 6.0);
    adam.arrived(time7);

    //Bob delivers next order
    pizzaRestaurant.serveNextOrder();
    pizzaRestaurant.departNextOrder(&bob, time5);
    pizzaRestaurant.deliver(&bob, time8, 3.4);
    bob.arrived(time9);

    cout << endl << "Summary: " << endl;
    pizzaRestaurant.summary();
*/
    return 0;
}
