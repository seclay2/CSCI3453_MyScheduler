/**
 * RR.cpp
 * Created by Scott Clay on 2019-5-6
 * Due on 2019-5-12
 */

#include "RR.h"

RR::RR(std::ifstream &input_file, CPU &cpu) {
    quantumsize = 4;
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


}
