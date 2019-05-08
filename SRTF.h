/**
 * SRTF.h
 * Created by Scott Clay on 2019-5-6
 * Due on 2019-5-12
 */

#ifndef OSLAB03_SRTF_H
#define OSLAB03_SRTF_H

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
    explicit SRTF(std::ifstream &input_file);
    void processQueue(std::queue<Process> &readyQueue) override;

};


#endif //OSLAB03_SRTF_H
