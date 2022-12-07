#ifndef _STOPWATCH_H_
#define _STOPWATCH_H_

#include <ctime>

class Stopwatch
{
    clock_t start_time;
    clock_t end_time;
    bool running;
public:
    Stopwatch();
    void start();            //  Start the timer
    void stop();             //  Stop the timer
    void reset();            //  Reset the timer
    double elapsed() const;  //  Reveal the elapsed time
};

#endif
