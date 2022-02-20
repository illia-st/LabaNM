#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include "Solver.h"
#include "Log.h"
#include "Operations.h"

enum class Method {
    DICHOTOMY,
    NEWTON,
    SIMPLE_ITERATION
};

void invitation();
Method chooseMethod();


int main()
{
    Solver * solver = new Solver();
    try {
        invitation();
        while (true) {
            std::string answer = "";
            std::cout << "Do you want to change the epsilon's value. Default value is 0.001.(YES or NO) > ";
            std::cin >> answer;
            if (answer == "YES") {
                double temp_epsilon;
                std::cout << "Enter a new value > ";
                while (!(std::cin >> temp_epsilon)) {
                    std::cin.clear();
                    std::cin.ignore(10'000, '\n');
                    std::cout << "The value isn't correct. Try again > ";
                }
                solver->Set_Epsilon(temp_epsilon);
            }
            else if (answer != "NO") {
                std::cin.clear();
                std::cin.ignore(10'000, '\n');
                continue;
            }
            Method method = chooseMethod();
            switch (method) {
                case Method::DICHOTOMY:
                    solver->Dichotomy();
                    break;
                case Method::NEWTON:
                    solver->Newton();
                    break;
                case Method::SIMPLE_ITERATION:
                    solver->Simple_Method();
                    break;
            }
        }
    }
    catch (...) {
        //delete solver;
    }
    delete solver;
    return 0;
}
void invitation() {
    std::cout << std::setw(40) << "Hello" << std::endl;
    std::cout << "In this laboratory work you can choose one of the three solving non-linear equation methods." << std::endl;
    std::cout << "You will be represented their efficiency and given a possibility to change the approximation" << std::endl;
}
Method chooseMethod() {
    while (true) {
        std::cout << "Choose a method by typing 'DICHOTOMY', 'NEWTON' or 'SIMPLE ITERATION' > ";
        std::cin.clear();
        std::cin.ignore(10'000, '\n');
        std::string line;
        std::getline(std::cin, line, '\n');
        if (line == "DICHOTOMY") {
            return Method::DICHOTOMY;
        }
        else if (line == "NEWTON") {
            return Method::NEWTON;
        }
        else if (line == "SIMPLE ITERATION") {
            return Method::SIMPLE_ITERATION;
        }
        std::cin.clear();
        std::cin.ignore(10'000, '\n');
    }
}
