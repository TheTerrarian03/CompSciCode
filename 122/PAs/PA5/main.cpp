// #include "Queue.hpp"
#include "Tests.hpp"
// #include "Simulation.hpp"

bool ynPrompt(std::string prompt);

int main() {
    std::cout << "---------- TEST QUEUE FUNCTIONALITY ----------" << std::endl << std::endl;
    
    if (ynPrompt("Would you like to run the Queue Tests?")) testMost();

    std::cout << std::endl << "---------- TEST SIMULATION ----------" << std::endl;

    if (ynPrompt("Would you like to run the Test Simulation (24h)?")) testSim24H();

    std::cout << std::endl << "---------- SIMULATION ----------" << std::endl;

    if (ynPrompt("Would you like to run a custom simulation?")) {
        int n = 0;
        bool verbose = false, realtime = false;
        
        std::cout << "How many minutes? (integer):" << std::endl << "> ";
        std::cin >> n;

        verbose = ynPrompt("Would you like to enable verbose output?");

        realtime = ynPrompt("Would you like to run this in realtime?");

        Simulation sim = Simulation(verbose, realtime);

        sim.runSimulation(n);
    }
}

bool ynPrompt(std::string prompt) {
    char input;
    
    std::cout << prompt << " (y/n):" << std::endl;
    std::cout << "> ";

    std::cin >> input;

    if (input == 'y' || input == 'Y') return true;
    return false;
}
