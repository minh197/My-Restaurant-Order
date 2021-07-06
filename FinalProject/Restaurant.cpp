#include "Restaurant.h"

Restaurant::Restaurant(){
    numOfOrders = 0;
    numOfServedOrders = 0;
}
void Restaurant::status() const {
    cout<<"Orders ready to cook:" << endl;
    for(auto& i: orders) {
        cout << i->toString() << endl;
    }
    cout<<"Orders ready to depart:" << endl;
    for(auto& i: delivery){
        if (i->toString() != "") {
            cout << i->toString() << endl;
        }
    }
    cout<<"Driver(s): " << endl;
    for(auto& i: driver_List) {
        if(i->isLoggedin()){
            cout << i->toString() << endl;
        }
    }
    cout << endl;
}
void Restaurant::summary() const{
    float deliveryTime;
    cout << "Number of orders completed: " << numOfServedOrders << endl;
    cout << "Average time per order: " << averageOrderTime() <<endl;
    cout << endl;
    for(auto& i: driver_List){
        cout << "Driver: " << i->getName() << endl;
        cout << "Number of deliveries completed: " << i->totalDeliveries() <<endl;
        //cout << "Time spent delivering: " << i->timeDelivering() << endl;
        if(i->totalDeliveries() == 0){
            cout <<"N/A";
        }
        else{
            deliveryTime = (float) i->timeDelivering() / (float) i->totalDeliveries();
            cout << "Average time per delivery: " << (deliveryTime)<< endl;
        }
        cout <<"Total driving time: " << i->timeDelivering() <<endl; //total or just time delivering
        cout << "Total tips: " << i->totalTip() <<endl;
        cout << endl;
    }
}
Driver * Restaurant::getDriver(string name){
    vector<Driver*>::const_iterator driver = driver_List.begin();
    Driver* driverPtr = nullptr;
    bool isExist = false;
    while(!isExist && driver != driver_List.end()){
        if((**driver).getName() == name){
            driverPtr = *driver;
            isExist = true;
        }
        driver++;
    }
    return driverPtr;
}

void Restaurant::addDriver(Driver* driver) {
    driver_List.push_back(driver);
}
//Pre: None
//Post: Adds the given order to the system, enqueuing it for ordersCooking.
void Restaurant::addOrder(Order* order) {
    orders.push_back(order);

}
//Pre: The ordersCooking queue is not empty.
//Post: Removes the oldest order from the ordersCooking queue and enqueues it for departure.
void Restaurant::serveNextOrder() throw (logic_error) {
    if(orders.empty()){
        throw logic_error("Cooking queue is empty");
    }
    else{
        numOfServedOrders++;
        delivery.push_back(orders.front());
        orders.pop_front();
    }
}
//Pre: The departure queue is not empty.
//Post: Removes the oldest order from the departure queue and returns it.
Order *Restaurant::departNextOrder(Driver* driver, Time time) throw (logic_error) {
    if(delivery.empty()){
        throw logic_error("Delivery queue is empty");
    }
    else{
        Order* deliveryPtr = delivery.front();
        driver->departed(time, *delivery.front());
        delivery.pop_front();
        cout << driver->getName() << " departs with a order" << endl;
        return deliveryPtr;
    }
}
//Pre: None
//Post: The order carried by the driver is delivered at the given time. The driver receives the given tip.
void Restaurant::deliver(Driver *driver, Time time, float tip) {
    driver->delivered(time, tip);
    totalOrder = (*driver).totalDeliveries();
    totalOrderTime = (*driver).timeDelivering();
    cout << "TESTING DELIVER TIME: " << time.toString() << endl;
    cout << "Total order time: " << totalOrderTime << endl;
}

float Restaurant::averageOrderTime() const {
    float average_time = (totalOrder != 0) ? (totalOrderTime / totalOrder) : 0; //calculates the average time per order, 0 if there is no order
    return average_time;
}
