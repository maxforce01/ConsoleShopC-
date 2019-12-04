#pragma once

#include "iostream"
#include "../core/Request.h"

using namespace std;

class Command {
public:
    virtual string execute(Request request) = 0;
    virtual string toString() = 0;
};

