/**
 * @file RR.cpp
 * @author Scott Clay
 *
 * Due on 2019-5-12
 *
 * @section DESCRIPTION
 *
 * Function definitions for class RR
 */

#include "RR.h"
#include <unordered_map>

RR::RR(std::ifstream &input_file, CPU &cpu) {
    quantumsize = 3;
    std::cout<< "Time quantum unspecified: Building RR Scheduler with default time quantum " << quantumsize << "\n";
    std::queue<Process> readyQueue;
    buildQueue(input_file, readyQueue);
    std::cout << "RR Scheduler Built with time quantum " << quantumsize << "\n";
    processQueue(readyQueue, cpu);
}

RR::RR(std::ifstream &input_file, int qs, CPU &cpu) {
    quantumsize = qs;
    std::queue<Process> readyQueue;
    buildQueue(input_file, readyQueue);
    std::cout << "RR Scheduler Built with time quantum " << quantumsize << "\n";
    processQueue(readyQueue, cpu);
}

void RR::processQueue(std::queue<Process> &readyQueue, CPU &cpu) {
    std::queue<Process> activeQueue;
    std::unordered_map<int, int> burstTimes;
    double numProcesses = readyQueue.size();
    double runningBurst=0, runningWait=0, runningTurnaround=0, runningResponse=0;

    activeQueue.push(readyQueue.front());
    readyQueue.pop();
    while (!readyQueue.empty() || !activeQueue.empty()) {
        Process active = activeQueue.front();
        activeQueue.pop();

        /* First time seeing process */
        if (burstTimes.count(active.pid) < 1) {
            burstTimes[active.pid] = active.burstTime;                  // Save original burst time
            active.waitTime = cpu.getClock() - active.arrivalTime;      // Set initial wait time
            runningResponse += active.waitTime;                         // Update running response time
            //printf("pid: %d, arrival: %d, clock: %d, wait: %d\n", active.pid, active.arrivalTime, cpu.getClock(), active.waitTime);
        } else {
            active.waitTime += (cpu.getClock() - active.completionTime);
        }

        /* If process will NOT complete this CPU cycle */
        if (quantumsize < active.burstTime) {
            cpu.run(active, quantumsize);               // Run for time quantum
            active.completionTime = cpu.getClock();     // Set temporary completion time
            active.switches++;                          // Context switch occured
            totalContextSwitches++;

            /* Check for new arrivals */
            while(!readyQueue.empty() && readyQueue.front().arrivalTime <= cpu.getClock()) {
                activeQueue.push(readyQueue.front());
                readyQueue.pop();
            }

            activeQueue.push(active);                    // Add process back into active queue
        }
        /* If process will complete this CPU cycle */
        else {
            cpu.run(active, active.burstTime);              // Run for remaining burst time
            active.completionTime = cpu.getClock();         // Set final completion time
            active.turnaround = active.completionTime - active.arrivalTime;     // Set turnaround
            active.burstTime = burstTimes[active.pid];      // Reset burst time in process
            processList.push(active);

            /* Overall Stats */
            runningBurst += active.burstTime;
            runningWait += active.waitTime;
            runningTurnaround += active.turnaround;

            /* Check for new arrivals */
            while(!readyQueue.empty() && readyQueue.front().arrivalTime <= cpu.getClock()) {
                activeQueue.push(readyQueue.front());
                readyQueue.pop();
            }
        }

    }

    /* Overall Stats */
    avgBurst = runningBurst / numProcesses;
    avgWait = runningWait / numProcesses;
    avgTurnaround = runningTurnaround / numProcesses;
    avgResponse = runningResponse / numProcesses;

}
