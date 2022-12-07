#include <iostream>
#include "stopwatch.h"

using namespace std;

//  Creates a Stopwatch object
//  A newly minted object is not running and is in a "reset" state
Stopwatch::Stopwatch(): start_time(0), end_time(0), running(false) {}

//  Starts the stopwatch.  If there is no current
//  start time, the stopwatch has not been used or 
//  has just been reset, so we record the current
//  system time to begin a new timing.  If there is
//  a valid start time, we merely resume the current timing.
//  Puts the stopwatch object in the 'running' state.
void Stopwatch::start() {
    if (start_time == 0)     //  Need to start with a fresh timing?
        start_time = clock();  //  If so, record start time
    running = true;            //  The clock is running
}

//  Stops the stopwatch.  Records the current
//  system time and puts the stopwatch object in
//  the 'not running' state. 
//  If the stopwatch is already stopped, a diagnostic
//  message is issued, but the stored elapsed time is
//  unaffected.
void Stopwatch::stop() {
    if (running) {
        end_time = clock();
        running = false;
    }
    else
        cout << "Stopwatch is not running" << endl;
}

//  Reports the time elapsed between the
//  stopwatch's starting and stopping times.
//  If elapsed is called while the stopwatch
//  is running, an error message is printed,
//  and the program terminates.
double Stopwatch::elapsed() const {
    if (running) {
		cout << "Stopwatch must be stopped for call to 'elapsed'" << endl;
        exit(1);
    }
    return static_cast<double>(end_time - start_time)/CLOCKS_PER_SEC;
}

//  Resets the stopwatch so a subsequent start begins recording 
//  a new time.  An attempt to  reset a running stopwatch 
//  produces an error message.
void Stopwatch::reset() {
    if (!running)
        start_time = end_time = 0;  //  Reset times
    else
        cout << "Error: Cannot reset a stopwatch that is running"
             << endl;
}

