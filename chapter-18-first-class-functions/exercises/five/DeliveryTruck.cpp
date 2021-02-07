#include <memory>
#include <sstream>
#include "Box.h"
#include "DeliveryTruck.h"
#include "RandomGenerator.h"

void DeliveryTruck::loadTruck(unsigned count)
{
    RandomGenerator rg {2, 8};

    for(size_t i {}; i < count; ++i)
    {
        load.addBox(std::make_shared<Box>(rg.getRandomReal(), 
                                          rg.getRandomReal(), 
                                          rg.getRandomReal()));
    }
}

void DeliveryTruck::deliverAllBoxes()
{
    for(size_t i {}; i < load.size(); ++i)
    {
        deliverBox(load[i]);
    }
}

bool DeliveryTruck::deliverBox(SharedBox& sb)
{
    //std::stringstream output {};
    //output << *sb;
    std::cout << "Total Boxes: " << load.size() << '\n';
    Box removed {*sb};


    
    if (load.removeBox(sb))
    {
        for(size_t i {}; i < listeners.size(); ++i)
        {
            listeners[i](removed);
        }
        return true;   
    }
    else
    {
        return false;
    }
}

void DeliveryTruck::registerOnDelivered(CallBack cb)
{
    listeners.push_back(cb);
}