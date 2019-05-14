/**
 * @file Process.h
 * @author Scott Clay
 *
 * Due on 2019-5-12
 *
 * @section DESCRIPTION
 *
 * Struct Process represents a process and contains it's own
 * attributes and process information.
 */

#ifndef MYSCHEDULER_PROCESS_H
#define MYSCHEDULER_PROCESS_H

struct Process {
    int pid,                // Process ID
        arrivalTime,        // Time Process arrives in scheduler
        burstTime,          // Time needed to complete process
        completionTime,     // CPU time when process is completed
        waitTime,           // Time that process was not active in CPU since arrival
        turnaround,         // Time taken since arrival to complete process
        switches;           // Number of context switches needed to complete process

    /**
     * Constructor that initializes all attributes to 0.
     */
    Process() { pid=0; arrivalTime=0; burstTime=0; completionTime=0; waitTime=0; turnaround=0; switches=0; }

    /**
     * Overridden operator for Process comparison for priority queues.
     * For ordering by ascending Process ID
     * Use as:
     *          std::priority_queue<Process, std::vector<Process>, Process>
     */
     bool operator() (const Process &a, const Process &b) const {
        return a.pid > b.pid;
    }
};

class Comparator {
public:
    bool operator() (const Process &a, const Process &b) const {
        return a.burstTime > b.burstTime;
    }
};

#endif //MYSCHEDULER_PROCESS_H