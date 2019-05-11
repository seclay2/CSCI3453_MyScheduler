/**
 * @file Scheduler.h
 * @author Scott Clay
 *
 * Due on 2019-5-12
 *
 * @section DESCRIPTION
 *
 * Class Scheduler is a scheduler object without the logic to process
 * the queue. Scheduler is intended to be extended by derivative classes.
 * Scheduler will build a queue from an input file, but cannot process the queue.
 */

#ifndef MYSCHEDULER_SCHEDULER_H
#define MYSCHEDULER_SCHEDULER_H

#include <iostream>
#include <queue>
#include <fstream>
#include "Process.h"
#include "CPU.h"

class Scheduler {
protected:
    /* List of processes scheduler has seen */
    std::priority_queue<Process, std::vector<Process>, Process> processList;
    /* Statistics of Process attributes */
    double avgBurst, avgWait, avgTurnaround, avgResponse, totalContextSwitches;

public:
    /**
     * Constructor that initializes statistic variables to 0
     */
    Scheduler() { avgBurst=0; avgWait=0; avgTurnaround=0; avgResponse=0; totalContextSwitches=0; }

    /**
     * Read processes in the input file and insert processes into queue.
     *
     * @param input_file is a file containing processes to be scheduled
     * @param readyQueue is an empty queue to be filled from input file
     */
    void buildQueue(std::ifstream &input_file, std::queue<Process> &readyQueue);

    /**
     * Process queue with scheduling algorithm on specified CPU object
     * *** MUST BE OVERRIDDEN IN DERIVATIVE CLASSES ***
     *
     * @param readyQueue is a queue of processes
     * @param cpu is the CPU object that is used to run the processes
     */
    virtual void processQueue(std::queue<Process> &readyQueue, CPU &cpu);

    /**
     * Print formatted table of processes with process attributes.
     */
    void printTable();

    /**
     * Print formatted statistics fo scheduler.
     */
    void printStats();

};


#endif //MYSCHEDULER_SCHEDULER_H
