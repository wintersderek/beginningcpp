/*
Exercise 18 - 5. As noted earlier, callback functions have many more interesting 
uses beyond serving as the argument to higher-order functions.  They are used 
frequently in more advanced object-oriented designs as well.  While creating a 
full-blown, complex system of intercommunicating objects would lead us too far 
astray, one basic example of how this could work should get you started.  Begin 
by recovering the Truckload class of Example 17 - 1.

Create a DeliveryTruck class that encapsulates a single Truckload object. Add 
DeliveryTruck::deliverBox() that not only applies removeBox() on its Truckload 
but also notifies any interested party that the given Box is delivered. It does
so, of course, by calling a callback function. In fact, make it so that a 
DeliveryTruck can have any number of callback functions, all of which are to be 
called whenever a Box is delivered (the newly delivered Box is then to be 
passed to these callbacks as an argument). You could store these callbacks in a 
std::vector<> member, for instance.  New callbacks are added through a 
DeliveryTruck::registerOnDelivered() member. We’ll leave it to you to choose 
the appropriate types, but we do expect that all known flavors of first-class 
functions are supported (that is, function pointers, function objects, and 
lambda closures). In real life, such callbacks could be used by the trucking
company to accumulate statistics on delivery times, to send an e-mail to the 
customer that his Box has arrived, and so on. In your case, a smaller test 
program suffices. It should register at least these callback functions: a 
global logDelivery() function that streams the delivered Box to std::cout and 
a lambda expression that counts the number of times any Box is delivered.

Note: What you are to implement in this exercise is a variation on the 
often-used Observer pattern. In the terminology of this classical 
object-oriented design pattern, the DeliveryTruck is called the observable, and 
the entities that are being notified through the callbacks are called the 
observers. The nice thing about this pattern is that the observable does not 
need to know the concrete type of its observers, meaning that both can be 
developed and compiled completely independently from each other.
*/

#include <functional>
#include <iostream>
#include "Box.h"
#include "DeliveryTruck.h"
#include "Manager.h"


void emailSent(Box& sb) { std::cout << "email sent for: " << sb << '\n'; }

int main (int argc, const char* argv[])
{
    unsigned deliveries {};
    auto record_statistics {[&deliveries](Box& sb) -> void { ++deliveries; }};

    CallBack my_callback {emailSent};

    // create a truckload with boxes
    DeliveryTruck dt {};
    dt.loadTruck(10);

    // register some observers (3)
    dt.registerOnDelivered(my_callback);
    my_callback = record_statistics;
    dt.registerOnDelivered(my_callback);
    //Manager myManager {};
    //my_callback = myManager.watchEmployees;
    //dt.registerOnDelivered(my_callback);

    // deliver all the packages
    dt.deliverAllBoxes();

    // write final deliveries
    std::cout << "Total Deliveries: " << deliveries << '\n';
    std::cout << std::endl;
    return EXIT_SUCCESS;
}
