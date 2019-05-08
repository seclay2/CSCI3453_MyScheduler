//
// Created by Scott Clay on 2019-05-07.
//

#include "Scheduler.h"
#include "TableTools.h"

Scheduler::Scheduler(std::ifstream &input_file) {
    avgBurst = 0;
    avgWait = 0;
    avgTurnaround = 0;
    avgResponse = 0;
    totalContextSwitches = 0;
    std::queue<Process> readyQueue;
    buildQueue(input_file, readyQueue);
    std::cout << "Scheduler Built\n";
    //processQueue(readyQueue);

}

void Scheduler::buildQueue(std::ifstream &input_file, std::queue<Process> &readyQueue) {
    Process temp;
    // Read file into ready queue
    while (!input_file.eof()) {
        input_file >> temp.pid >> temp.arrivalTime >> temp.burstTime;
        readyQueue.push(temp);
    }

}

void Scheduler::processQueue(std::queue<Process> &readyQueue) {
    fprintf(stderr, "Must define processQueue() function in derived class");
    exit(1);

}

void Scheduler::printTable() {
    std::cout << TableTools::center("Process", 12) << " | "
              << TableTools::center("Arrival", 12) << " | "
              << TableTools::center("Burst", 12) << " | "
              << TableTools::center("Complete", 12) << " | "
              << TableTools::center("Wait", 12) << " | "
              << TableTools::center("Turnaround", 12) << "\n"
              << std::string(12*6 + 3*5, '-') << "\n";
    std::queue<Process> rq = processList;
    while (!rq.empty()) {
        Process temp = rq.front();
        std::cout << TableTools::pri(temp.pid, 12) << " | "
                  << TableTools::pri(temp.arrivalTime, 12) << " | "
                  << TableTools::pri(temp.burstTime, 12) << " | "
                  << TableTools::pri(temp.completionTime, 12) << " | "
                  << TableTools::pri(temp.waitTime, 12) << " | "
                  << TableTools::pri(temp.turnaround, 12) << "\n";
        rq.pop();
    }
    std::cout << std::endl;

}

void Scheduler::printStats() {
    std:: cout << "Average CPU burst time:  " << avgBurst << "\n"
               << "Average waiting time:  " << avgWait << "\n"
               << "Average turnaround time:  " << avgTurnaround << "\n"
               << "Average response time:  " << avgResponse << "\n"
               << "Total number of context switches:  " << totalContextSwitches << "\n";

}