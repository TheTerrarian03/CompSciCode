all: run

run: build rr

build:
	clear
	gcc -lstdc++ -o program.o Data.hpp QueueNode.hpp Queue.hpp Tests.hpp Simulation.hpp main.cpp

rr:
	clear && ./program.o