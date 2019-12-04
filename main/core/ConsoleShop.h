#include <iostream>
#include "Initialize.h"
#include "Controller.h"
#include "Context.h"

class ConsoleShop {
public:
    static void startProgram() {
        string command;
        auto *init = new Initialize();
        auto *controller = new Controller(init->getContext());
        cout<<controller->executeCommand("printCommands")<<endl;
        while (true) {
            cout << "Enter command \n";
            std::getline(std::cin >> std::ws, command);
            if (command == "exit") {
                break;
            }
            cout << controller->executeCommand(command) << endl;
        }
        controller->executeCommand("--state");
    }

};

