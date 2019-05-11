/**
 * @file Scheduler.cpp
 * @author Scott Clay
 *
 * Due on 2019-5-12
 *
 * @section DESCRIPTION
 *
 * Function definitions for class Scheduler
 */

#include "Scheduler.h"
#include "TableTools.h"


void Scheduler::buildQueue(std::ifstream &input_file, std::queue<Process> &readyQueue) {
    Process temp;
    // Read file into ready queue
    while (!input_file.eof()) {
        input_file >> temp.pid >> temp.arrivalTime >> temp.burstTime;
        readyQueue.push(temp);
    }

}

void Scheduler::processQueue(std::queue<Process> &readyQueue, CPU &cpu) {
    fprintf(stderr, "Must define processQueue() function in derived class");
    exit(1);

}

void Scheduler::printTable() {
    std::cout << TableTools::center("ProcessID", 12) << " | "
              << TableTools::center("Arrival", 12) << " | "
              << TableTools::center("Burst", 12) << " | "
              << TableTools::center("Complete", 12) << " | "
              << TableTools::center("Wait", 12) << " | "
              << TableTools::center("Turnaround", 12) << " | "
              << TableTools::center("Context Switches", 18) << "\n"
              << std::string(12*6 + 3*6 + 18, '-') << "\n";
    std::priority_queue<Process, std::vector<Process>, Process> rq = processList;
    while (!rq.empty()) {
        Process temp = rq.top();
        std::cout << TableTools::pri(temp.pid, 12) << " | "
                  << TableTools::pri(temp.arrivalTime, 12) << " | "
                  << TableTools::pri(temp.burstTime, 12) << " | "
                  << TableTools::pri(temp.completionTime, 12) << " | "
                  << TableTools::pri(temp.waitTime, 12) << " | "
                  << TableTools::pri(temp.turnaround, 12) << " | "
                  << TableTools::pri(temp.switches, 18) << "\n";
        rq.pop();
    }
    std::cout << std::endl;

}

void Scheduler::printStats() {
    std:: cout << "Average CPU burst time:  " << TableTools::prd(avgBurst, 1, 8+5) << "\n"
               << "Average waiting time:  " << TableTools::prd(avgWait, 1, 10+5) << "\n"
               << "Average turnaround time:  " << TableTools::prd(avgTurnaround, 1, 7+5) << "\n"
               << "Average response time:  " << TableTools::prd(avgResponse, 1, 9+5) << "\n"
               << "Total number of context switches:  " << totalContextSwitches << "\n";

}