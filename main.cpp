/**
 * main.cpp
 * Created by Scott Clay on 2019-5-6
 * Due on 2019-5-12
 */

#include <iostream>
#include <fstream>
#include "FCFS.h"
#include "SRTF.h"
#include "RR.h"

int main(int argc, char *argv[])
{
    // Check arguments
    if (argc < 2) {
        std::cout << "Expected 2 Arguments: \" ./myscheduler \'filename\' \'algorithm\' \"\n"
                  << "(RR algorithm requires quantumsize as aditional argument)\n";
        exit(1);
    }

    // Open input file
    std::ifstream input_file(argv[1]);
    if (!input_file.is_open()) {
        perror("file");
        exit(1);
    }

    if (strcmp(argv[2], "FCFS") == 0 || strcmp(argv[2], "fcfs") == 0) {
        FCFS myScheduler(input_file);
        myScheduler.printTable();
        myScheduler.printStats();

    }
    else if (strcmp(argv[2], "SRTF") == 0 || strcmp(argv[2], "srtf") == 0) {
        SRTF myScheduler(input_file);
        myScheduler.printTable();
        myScheduler.printStats();

    }
    else if (strcmp(argv[2], "RR") == 0 || strcmp(argv[2], "rr") == 0) {
        RR myScheduler(input_file, atoi(argv[3]));
        myScheduler.printTable();
        myScheduler.printStats();

    }
    else {
        std::cout << "Invalid scheduling algorithm. FCFS, SRTF, RR supported\n";
        exit(1);
    }


    return 0;
}