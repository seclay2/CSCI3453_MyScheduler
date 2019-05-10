/**
 * FCFS.h
 * Created by Scott Clay on 2019-5-6
 * Due on 2019-5-12
 */

#ifndef MYSCHEDULER_FCFS_H
#define MYSCHEDULER_FCFS_H

#include "Scheduler.h"

/**
 * FCFS
 * Derived from class Scheduler
 *
 *
 * First-Come-First-Serve Scheduler
 */
class FCFS : public Scheduler {

public:
    FCFS() : Scheduler() {}
    explicit FCFS(std::ifstream &input_file, CPU &cpu);
    void processQueue(std::queue<Process> &readyQueue, CPU &cpu) override;

};


#endif //MYSCHEDULER_FCFS_H
