//
// Created by maxforce01 on 04.12.2019.
//

#include "Command.h"

class InvalidCommand : public Command {
public:
    InvalidCommand(string commands) {
        this->commands = commands;
    }

    string execute(Request request) override {
        return commands;
    }

    string toString() override {
        return "invalid command";
    }

private:
    string commands;
};