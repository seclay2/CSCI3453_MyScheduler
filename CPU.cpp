//
// Created by Scott Clay on 2019-05-09.
//

#include "CPU.h"

void CPU::run(Process &active, int runTime) {

    active.burstTime -= runTime;    // Run process for specified runTime
    clock += runTime;               // Update clock

}
