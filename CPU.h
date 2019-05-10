//
// Created by Scott Clay on 2019-05-09.
//

#ifndef CSCI3453_MYSCHEDULER_CPU_H
#define CSCI3453_MYSCHEDULER_CPU_H

#include "Process.h"

class CPU {
private:
    int clock;  // running clock time

public:
    CPU() { clock=0; }
    void run(Process &active, int runTime);
    int getClock() { return clock; }
};


#endif //CSCI3453_MYSCHEDULER_CPU_H
