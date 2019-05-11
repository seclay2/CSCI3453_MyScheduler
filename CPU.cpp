/**
 * @file CPU.cpp
 * @author Scott Clay
 *
 * Due on 2019-5-12
 *
 * @section DESCRIPTION
 *
 * Function definitions for class CPU
 */

#include "CPU.h"

void CPU::run(Process &active, int runTime) {
    active.burstTime -= runTime;    // Run process for specified runTime
    clock += runTime;               // Update clock

}
