/**
 * @file main.cpp
 * @author Scott Clay
 *
 * Due on 2019-5-12
 *
 * @section DESCRIPTION
 *
 * Driver program for simulating a scheduling algorithm on
 * a list of processes from an input file.
 *
 * ./myscheduler <input file> <scheduling algorithm> <time quantum(optional)>
 */

#include <iostream>
#include <fstream>
#include "CPU.h"
#include "FCFS.h"
#include "SRTF.h"
#include "RR.h"

int main(int argc, char *argv[])
{
    // Check arguments
    if (argc < 2) {
        std::cout << "Expected 2 Arguments: \" ./myscheduler <filename> <algorithm> <quantumsize(optional)> \"\n";
        exit(1);
    }

    // Open input file
    std::ifstream input_file(argv[1]);
    if (!input_file.is_open()) {
        perror("file");
        exit(1);
    }

    // Create virtual CPU
    CPU cpu1;

    if (strcmp(argv[2], "FCFS") == 0 || strcmp(argv[2], "fcfs") == 0) {
        FCFS myScheduler(input_file, cpu1);
        myScheduler.printTable();
        myScheduler.printStats();

    }
    else if (strcmp(argv[2], "SRTF") == 0 || strcmp(argv[2], "srtf") == 0) {
        SRTF myScheduler(input_file, cpu1);
        myScheduler.printTable();
        myScheduler.printStats();

    }
    else if (strcmp(argv[2], "RR") == 0 || strcmp(argv[2], "rr") == 0) {
        if (argc > 3) {
            RR myScheduler(input_file, atoi(argv[3]), cpu1);
            myScheduler.printTable();
            myScheduler.printStats();
        } else {
            RR myScheduler(input_file, cpu1);
            myScheduler.printTable();
            myScheduler.printStats();
        }

    }
    else {
        std::cout << "Invalid scheduling algorithm. FCFS, SRTF, RR supported\n";
        exit(1);
    }

    return 0;
}