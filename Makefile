# makefile for myscheduler
#

CC=g++
CFLAGS=-Wall
CXXFLAGS=-std=c++11

all: main.o CPU.o Scheduler.o FCFS.o SRTF.o RR.o
	$(CC) $(CFLAGS) $(CXXFLAGS) -o myscheduler main.o CPU.o Scheduler.o FCFS.o SRTF.o RR.o

main.o: main.cpp
	$(CC) $(CFLAGS) $(CXXFLAGS) -c main.cpp

CPU.o: CPU.cpp CPU.h
	$(CC) $(CFLAGS) $(CXXFLAGS) -c CPU.cpp

Scheduler.o: Scheduler.cpp Scheduler.h
	$(CC) $(CFLAGS) $(CXXFLAGS) -c Scheduler.cpp

FCFS.o: FCFS.cpp FCFS.h
	$(CC) $(CFLAGS) $(CXXFLAGS) -c FCFS.cpp

SRTF.o: SRTF.cpp SRTF.h
	$(CC) $(CFLAGS) $(CXXFLAGS) -c SRTF.cpp

RR.o: RR.cpp RR.h
	$(CC) $(CFLAGS) $(CXXFLAGS) -c RR.cpp


clean:
	rm -rf *.o
	rm -rf myscheduler
