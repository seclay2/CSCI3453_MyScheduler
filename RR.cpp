/**
 * RR.cpp
 * Created by Scott Clay on 2019-5-6
 * Due on 2019-5-12
 */

#include "RR.h"

RR::RR(std::ifstream &input_file, int qs) {
    quantumsize = qs;
    std::queue<Process> readyQueue;
    buildQueue(input_file, readyQueue);
    std::cout << "RR Scheduler Built with time quantum " << quantumsize << "\n";
    processQueue(readyQueue);
}

void RR::processQueue(std::queue<Process> &readyQueue) {
    Scheduler::processQueue(readyQueue);

}
