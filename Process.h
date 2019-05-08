/**
 * Process.h
 * Created by Scott Clay on 2019-5-6
 * Due on 2019-5-12
 */

#ifndef OSLAB03_PROCESS_H
#define OSLAB03_PROCESS_H

struct Process {
    int pid, arrivalTime, burstTime, completionTime, waitTime, turnaround, switches;
    Process() { pid=0; arrivalTime=0; burstTime=0; completionTime=0; waitTime=0; turnaround=0; switches=0; }
};

#endif //OSLAB03_PROCESS_H