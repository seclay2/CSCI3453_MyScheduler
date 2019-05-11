/**
 * @file SRTF.cpp
 * @author Scott Clay
 *
 * Due on 2019-5-12
 *
 * @section DESCRIPTION
 *
 * Function definitions for class SRTF
 */

#include "SRTF.h"
#include <unordered_map>

SRTF::SRTF(std::ifstream &input_file, CPU &cpu) {
    std::queue<Process> readyQueue;
    buildQueue(input_file, readyQueue);
    std::cout << "SRTF Scheduler Built\n";
    processQueue(readyQueue, cpu);

}

void SRTF::processQueue(std::queue<Process> &processes, CPU &cpu) {
    std::priority_queue<Process, std::vector<Process>, Comparator> activeQueue;
    std::unordered_map<int, int> burstTimes;
    double numProcesses = processes.size();
    double runningBurst=0, runningWait=0, runningTurnaround=0, runningResponse=0;
    int prevActivePid = 0;

    while (!processes.empty() || !activeQueue.empty()) {
        if (activeQueue.empty() || processes.front().arrivalTime == cpu.getClock()) {
            burstTimes[processes.front().pid] = processes.front().burstTime;
            activeQueue.push(processes.front());
            processes.pop();
        }
        Process active = activeQueue.top();
        activeQueue.pop();

        /* First time seeing process */
        if (active.burstTime == burstTimes[active.pid]) {
            active.waitTime = cpu.getClock() - active.arrivalTime;              // Set wait time
            runningResponse += active.waitTime;                                 //
        } else {
            active.waitTime += (cpu.getClock() - active.completionTime);
            if (prevActivePid != active.pid) {
                active.switches++;
                totalContextSwitches++;
            }
        }

        /* Run Process */
        cpu.run(active, 1);
        /* If process has completed */
        if (active.burstTime < 1) {
            active.completionTime = cpu.getClock();                             // Set completion time
            active.turnaround = active.completionTime - active.arrivalTime;     // Set turnaround time
            active.burstTime = burstTimes[active.pid];                          // Reset original burst time
            processList.push(active);

            /* Overall Stats */
            runningBurst += active.burstTime;
            runningWait += active.waitTime;
            runningTurnaround += active.turnaround;
        }
        /* If process has not completed */
        else {
            active.completionTime = cpu.getClock();         // Set temporary completion time
            activeQueue.push(active);
        }

        prevActivePid = active.pid;

    }

    /* Overall Stats */
    avgBurst = runningBurst / numProcesses;
    avgWait = runningWait / numProcesses;
    avgTurnaround = runningTurnaround / numProcesses;
    avgResponse = runningResponse / numProcesses;
}
