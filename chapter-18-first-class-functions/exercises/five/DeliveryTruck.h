//DeliveryTruck.h
#ifndef DELIVERY_TRUCK_H
#define DELIVERY_TRUCK_H

#include <functional>
#include <vector>
#include "TruckLoad.h"

using CallBack = std::function<void(Box &)>;
using CallBacks = std::vector<CallBack>;

class DeliveryTruck
{
public:
    DeliveryTruck() = default;
    explicit DeliveryTruck(Truckload tr, CallBacks cb) : 
        load {tr}, listeners {cb} {}

    void loadTruck(unsigned count);
    void deliverAllBoxes();
    bool deliverBox(SharedBox& box);
    void registerOnDelivered(CallBack cb);
private:
    Truckload load;
    CallBacks listeners;
};
#endif