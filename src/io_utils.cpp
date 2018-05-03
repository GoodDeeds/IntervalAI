#include "io_utils.h"
#include <fstream>

using namespace intervalai;

void intervalai::displayUnknownMode() {
    std::cout << "Unrecognized Abstract Interpreter mode" << std::endl;
    std::cout << "Available modes : auto, step" << std::endl;
}

void intervalai::displayHelp(std::string name) {
    displayTitle();
    std::cout << "Usage : " << name << " [-v] [-h] [-m <mode>] <goto-binary>"
              << std::endl
              << std::endl;
    std::cout << "This program generates a goto-binary generated by CPROVER, "
                 "and verifies assertions using abstract interpretation with "
                 "the integer interval domain.\nOnly programs consisting "
                 "entirely of integer variables are supported."
              << std::endl
              << std::endl;
    std::cout << "Options : " << std::endl
              << "-m <mode> - specify mode. The two possible modes are auto "
                 "and step. "
                 "In auto, the program runs on the input and provides the "
                 "final result. In step, the program runs on the input "
                 "stepwise, and provides an opportunity to inspect the state "
                 "after each step and visualize the execution of instructions"
              << std::endl
              << "-h - view help" << std::endl
              << "-v - view about" << std::endl;
}

void intervalai::displayAbout() {
    displayTitle();
    std::cout << "Use -h flag for help" << std::endl;
}

bool intervalai::fileExists(std::string name) {
    std::ifstream gotofile(name.c_str());
    return gotofile.good();
}

void intervalai::displayUnknownFile(std::string name) {
    std::cout << "Could not open file : " << name << std::endl;
}

void intervalai::displayResult(bool safe) {
    if (safe) {
        std::cout << "All assertions passed. The program is safe as per the "
                     "given specification."
                  << std::endl;
    } else {
        std::cout << "An assertion failed. The program might not be safe as "
                     "per the given specification."
                  << std::endl;
    }
}

void intervalai::displayTitle() {
    std::cout << "IntervalAI : An restricted Abstract Interpreter based on the "
                 "integer interval domain"
              << std::endl;
    std::cout << "By : Sukrut Rao, Prateek Kumar" << std::endl << std::endl;
}