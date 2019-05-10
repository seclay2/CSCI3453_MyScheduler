/**
 * FCFS.cpp
 * Created by Scott Clay on 2019-5-6
 * Due on 2019-5-12
 */

#include "FCFS.h"

FCFS::FCFS(std::ifstream &input_file, CPU &cpu) {
    std::queue<Process> readyQueue;
    buildQueue(input_file, readyQueue);
    std::cout << "FCFS Scheduler Built\n";
    processQueue(readyQueue, cpu);
}

void FCFS::processQueue(std::queue<Process> &readyQueue, CPU &cpu) {
    int numProcesses = readyQueue.size();
    int runningBurst=0, runningWait=0, runningTurnaround=0, runningResponse=0;

    while (!readyQueue.empty()) {
        Process active = readyQueue.front();                                // Move ready process into focus
        readyQueue.pop();                                                   // Remove process from ready queue

        /* Per Process */
        active.waitTime = cpu.getClock() - active.arrivalTime;              // Set wait time
        int activeBurst = active.burstTime;                                 // Save original burst time
        cpu.run(active, active.burstTime);                                  // Run for full burst time
        active.burstTime = activeBurst;                                     // Restore original burst time
        active.completionTime = cpu.getClock();                             // Set completion time
        active.turnaround = active.completionTime - active.arrivalTime;     // Set turnaround

        processList.push(active);                                           // Add Completed Process to list

        /* Overall Stats */
        runningBurst += active.burstTime;
        runningWait += active.waitTime;
        runningTurnaround += active.turnaround;
        runningResponse += active.waitTime;
    }

    /* Overall Stats */
    avgBurst = runningBurst / numProcesses;
    avgWait = runningWait / numProcesses;
    avgTurnaround = runningTurnaround / numProcesses;
    avgResponse = runningResponse / numProcesses;

}
