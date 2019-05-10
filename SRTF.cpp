/**
 * SRTF.cpp
 * Created by Scott Clay on 2019-5-6
 * Due on 2019-5-12
 */

#include "SRTF.h"

SRTF::SRTF(std::ifstream &input_file, CPU &cpu) {
    std::queue<Process> readyQueue;
    buildQueue(input_file, readyQueue);
    std::cout << "SRTF Scheduler Built\n";
    processQueue(readyQueue, cpu);

}

void SRTF::processQueue(std::queue<Process> &readyQueue, CPU &cpu) {


}
