/**
 * RR.h
 * Created by Scott Clay on 2019-5-6
 * Due on 2019-5-12
 */

#ifndef MYSCHEDULER_RR_H
#define MYSCHEDULER_RR_H

#include "Scheduler.h"

/**
 * RR
 * Derived from class Scheduler
 *
 * Round-Robin Scheduler with custom time quantum
 */
class RR : public Scheduler {
private:
    int quantumsize;

public:
    RR() : Scheduler() { quantumsize=0; }
    explicit RR(std::ifstream &input_file, CPU &cpu);
    explicit RR(std::ifstream &input_file, int qs, CPU &cpu);
    void processQueue(std::queue<Process> &readyQueue, CPU &cpu) override;

};


#endif //MYSCHEDULER_RR_H
