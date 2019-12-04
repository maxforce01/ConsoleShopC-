#pragma once

#include "iostream"
#include "vector"
#include "regex"

using namespace std;

class Request {
public:
    explicit Request(string request) {
        if (request.find_first_of(' ') != -1) {
            int index = request.find_first_of(' ');
            command = request.substr(0, index);
            request = request.substr(index + 1);
            arguments = split(request, ' ');
        } else {
            command = request;
        }

    }

    string getCommand() {
        return command;
    }

    string getArg(int index) {
        return arguments[index];
    }

    vector<string> getArgs() {
        return arguments;
    }

private:
    string command;
    vector<string> arguments;

    std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
        std::stringstream ss(s);
        std::string item;
        while (std::getline(ss, item, delim)) {
            if (item.length() > 0) {
                elems.push_back(item);
            }
        }
        return elems;
    }


    std::vector<std::string> split(const std::string &s, char delim) {
        std::vector<std::string> elems;
        split(s, delim, elems);
        return elems;
    }
};

