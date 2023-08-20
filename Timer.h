#pragma once
#include <chrono>

class Timer {
public:
    Timer(int t);
    //bool timer(int time);
private:
    static int now;
    int t;
};