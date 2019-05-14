/**
 * @file CPU.h
 * @author Scott Clay
 *
 * Due on 2019-5-12
 *
 * @section DESCRIPTION
 *
 * Class CPU acts as a virtual CPU where processes are "run"
 * by removing processing time from the process burst time.
 * Processing clock time is tracked.
 */

#ifndef CSCI3453_MYSCHEDULER_CPU_H
#define CSCI3453_MYSCHEDULER_CPU_H

#include "Process.h"

class CPU {
private:
    int clock;  // running clock time

public:
    /**
     * Constructor that initiates clock time to 0.
     */
    CPU() { clock=0; }

    /**
     * Run process for specified run time.
     *
     * @param active is the process to be "run"
     * @param runTime is the amount of time to run the process
     */
    void run(Process &active, int runTime);

    /**
     * Get clock time.
     *
     * @return clock variable
     */
    int getClock() { return clock; }
};


#endif //CSCI3453_MYSCHEDULER_CPU_H
