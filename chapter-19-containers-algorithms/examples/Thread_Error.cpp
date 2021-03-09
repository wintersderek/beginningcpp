/*
Test if std::tread does terminate if out of scope
*/

#include <thread>
#include <chrono>

void sleep(const int seconds)
{
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

int main(int argc, char const *argv[])
{
    std::thread t1 {sleep, 5};
    std::thread t2 {sleep, 7};
    if (t2.joinable()) t2.detach();
    sleep(3);

    sleep(4);

    sleep(1);
    
    if (t1.joinable()) t1.join();
    return 0;
}
