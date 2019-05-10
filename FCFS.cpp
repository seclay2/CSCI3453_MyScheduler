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
    std::queue<Process> rq = readyQueue;
    int numProcesses = readyQueue.size();
    int runningBurst=0, runningWait=0, runningTurnaround=0, runningResponse=0;

    while (!readyQueue.empty()) {
        Process active = readyQueue.front();

        /* Process */
        active.waitTime = cpu.getClock() - active.arrivalTime;
        cpu.run(active, active.burstTime);
        active.completionTime = cpu.getClock();
        active.turnaround = active.completionTime - active.arrivalTime;

        active.burstTime = readyQueue.front().burstTime;
        processList.push(active);
        readyQueue.pop();

        /* Stats */
        runningBurst += active.burstTime;
        runningWait += active.waitTime;
        runningTurnaround += active.turnaround;
        runningResponse += active.waitTime;
    }

    avgBurst = runningBurst / numProcesses;
    avgWait = runningWait / numProcesses;
    avgTurnaround = runningTurnaround / numProcesses;
    avgResponse = runningResponse / numProcesses;

}
