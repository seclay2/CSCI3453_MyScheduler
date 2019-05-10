//
// Created by Scott Clay on 2019-05-07.
//

#ifndef MYSCHEDULER_SCHEDULER_H
#define MYSCHEDULER_SCHEDULER_H

#include <iostream>
#include <queue>
#include <fstream>
#include "Process.h"
#include "CPU.h"


class Scheduler {
protected:
    std::queue<Process> processList;
    int avgBurst, avgWait, avgTurnaround, avgResponse, totalContextSwitches;

public:
    Scheduler() { avgBurst=0; avgWait=0; avgTurnaround=0; avgResponse=0; totalContextSwitches=0; }
    void buildQueue(std::ifstream &input_file, std::queue<Process> &readyQueue);
    virtual void processQueue(std::queue<Process> &readyQueue, CPU &cpu);
    void printTable();
    void printStats();

};


#endif //MYSCHEDULER_SCHEDULER_H
