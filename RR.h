/**
 * @file RR.h
 * @author Scott Clay
 *
 * Due on 2019-5-12
 *
 * @section DESCRIPTION
 *
 * Class RR is an extension of class Scheduler that contains the
 * logic for a Round-Robin scheduling algorithm
 */

#ifndef MYSCHEDULER_RR_H
#define MYSCHEDULER_RR_H

#include "Scheduler.h"

class RR : public Scheduler {
private:
    int quantumsize;    // time quantum size

public:
    /**
     * Default Constructor that sets quantumsize to 0.
     */
    RR() : Scheduler() { quantumsize=0; }

    /**
     * Constructor that builds a queue from and input file and
     * processes the queue on the specified CPU using the default
     * time quantum.
     *
     * @param input_file is a file containing prcesses to be scheduled
     * @param cpu is the CPU object that is used to "run" the processes
     */
    explicit RR(std::ifstream &input_file, CPU &cpu);

    /**
     * Constructor that builds a queue from and input file and
     * processes the queue on the specified CPU using the specified
     * time quantum.
     *
     * @param input_file is a file containig processes to be scheduled
     * @param qs is the time quantum size for the RR algorithm
     * @param cpu is the CPU object that is used to "run" the processes
     */
    explicit RR(std::ifstream &input_file, int qs, CPU &cpu);

    /**
     * Process queue with a round-robin algorithm while tracking
     * stastics for the processes as they are run.
     * Override of Scheduler::processQueue().
     *
     * @param readyQueue is a queue of processes
     * @param cpu is the CPU object that is used to run the processes
     */
    void processQueue(std::queue<Process> &readyQueue, CPU &cpu) override;

};


#endif //MYSCHEDULER_RR_H
