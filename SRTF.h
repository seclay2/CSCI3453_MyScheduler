/**
 * @file SRTF.h
 * @author Scott Clay
 *
 * Due on 2019-5-12
 *
 * @section DESCRIPTION
 *
 * Class SRTF is an extension of class Scheduler that contains
 * the logic for a Shortest-Remaining-Time-First scheduling
 * algorithm.
 */

#ifndef MYSCHEDULER_SRTF_H
#define MYSCHEDULER_SRTF_H

#include "Scheduler.h"

class SRTF : public Scheduler {

public:
    /**
     * Default Constructor
     */
    SRTF() : Scheduler() {}

    /**
     * Constructor that builds a queue from and input file and
     * processes the queue on the specified CPU.
     *
     * @param input_file is a file containing processes to be scheduled
     * @param cpu is the CPU object that is used to "run" the processes
     */
    explicit SRTF(std::ifstream &input_file, CPU &cpu);

    /**
     * Process queue with a shortest-remaining-time-first algorithm
     * while tracking stastics for the processes as they are run.
     * Override of Scheduler::processQueue().
     *
     * @param readyQueue is a queue of processes
     * @param cpu is the CPU object that is used to run the processes
     */
    void processQueue(std::queue<Process> &readyQueue, CPU &cpu) override;
    //void processQueue2(std::vector<Process> &processes, CPU &cpu);

};


#endif //MYSCHEDULER_SRTF_H
