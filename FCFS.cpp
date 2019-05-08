/**
 * FCFS.cpp
 * Created by Scott Clay on 2019-5-6
 * Due on 2019-5-12
 */

#include "FCFS.h"

FCFS::FCFS(std::ifstream &input_file) {
    std::queue<Process> readyQueue;
    buildQueue(input_file, readyQueue);
    std::cout << "FCFS Scheduler Built\n";
    processQueue(readyQueue);
}

void FCFS::processQueue(std::queue<Process> &readyQueue) {
    int clock = 0;      // Tracks clock time as each process is made active
    int numProcesses = readyQueue.size();
    int runningBurst=0, runningWait=0, runningTurnaround=0, runningResponse=0;
    while (!readyQueue.empty()) {
        Process active = readyQueue.front();
        /* Wait Time */
        active.waitTime = clock - active.arrivalTime;
        runningWait += active.waitTime;

        /* Burst Time */
        clock += active.burstTime;
        runningBurst += active.burstTime;

        /* Completion Time */
        active.completionTime = clock;

        /* Turnaround Time */
        active.turnaround = active.completionTime - active.arrivalTime;
        runningTurnaround += active.turnaround;

        /* Response Time */
        runningResponse += active.waitTime;     // response time for FCFS is the same as wait time

        /* Context Switching */
        // context switches do not occur in a FCFS algorithm

        processList.push(active);
        readyQueue.pop();
    }
    avgBurst = runningBurst / numProcesses;
    avgWait = runningWait / numProcesses;
    avgTurnaround = runningTurnaround / numProcesses;
    avgResponse = runningResponse / numProcesses;

}

