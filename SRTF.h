/**
 * SRTF.h
 * Created by Scott Clay on 2019-5-6
 * Due on 2019-5-12
 */

#ifndef MYSCHEDULER_SRTF_H
#define MYSCHEDULER_SRTF_H

#include "Scheduler.h"

/**
 * SRTF
 * Derived from class Scheduler
 *
 * Shortest-Remaining-Time-First Scheduler
 */
class SRTF : public Scheduler {

public:
    SRTF() : Scheduler() {}
    explicit SRTF(std::ifstream &input_file, CPU &cpu);
    void processQueue(std::queue<Process> &readyQueue, CPU &cpu) override;

};


#endif //MYSCHEDULER_SRTF_H
