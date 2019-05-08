/**
 * RR.h
 * Created by Scott Clay on 2019-5-6
 * Due on 2019-5-12
 */

#ifndef OSLAB03_RR_H
#define OSLAB03_RR_H

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
    //TODO add RR constructor for input file param only with default qs
    explicit RR(std::ifstream &input_file, int qs);
    void processQueue(std::queue<Process> &readyQueue) override;

};


#endif //OSLAB03_RR_H
