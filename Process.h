/**
 * Process.h
 * Created by Scott Clay on 2019-5-6
 * Due on 2019-5-12
 */

#ifndef MYSCHEDULER_PROCESS_H
#define MYSCHEDULER_PROCESS_H

struct Process {
    int pid, arrivalTime, burstTime, completionTime, waitTime, turnaround, switches;
    Process() { pid=0; arrivalTime=0; burstTime=0; completionTime=0; waitTime=0; turnaround=0; switches=0; }

    bool operator() (const Process &a, const Process &b) const {
        return a.pid > b.pid;
    }
};

// Overridden operator for Process comparison for priority queues
class Comparator {
public:
    bool operator() (const Process &a, const Process &b) const {
        return a.pid > b.pid;
    }
};

#endif //MYSCHEDULER_PROCESS_H