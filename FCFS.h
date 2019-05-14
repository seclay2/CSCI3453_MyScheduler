/**
 * @file FCFS.h
 * @author Scott Clay
 *
 * Due on 2019-5-12
 *
 * @section DESCRIPTION
 *
 * Class FCFS is an extension of the class Scheduler that
 * contains the logic for a First-Come-First-Serve
 * scheduling algorithm.
 */

#ifndef MYSCHEDULER_FCFS_H
#define MYSCHEDULER_FCFS_H

#include "Scheduler.h"

class FCFS : public Scheduler {

public:
    /**
     * Default Constructor
     */
    FCFS() : Scheduler() {}

    /**
     * Constructor that builds a queue from an input file and
     * processes the queue on the specified CPU object.
     *
     * @param input_file is a file containing processes to be scheduled
     * @param cpu is the CPU object that is used to "run" the processes
     */
    explicit FCFS(std::ifstream &input_file, CPU &cpu);

    /**
     * Processes queue with a first-come-first-serve algorithm while
     * tracking statistics for the processes as they are run.
     * Override of Scheduler::processQueue().
     *
     * @param readyQueue is a queue of processes
     * @param cpu is the CPU object that will run the processes
     */
    void processQueue(std::queue<Process> &readyQueue, CPU &cpu) override;

};


#endif //MYSCHEDULER_FCFS_H
