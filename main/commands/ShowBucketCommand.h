//
// Created by maxforce01 on 04.12.2019.
//

#include "Command.h"
#include "../core/Context.h"

class ShowBucketCommand : public Command {
public:
    ShowBucketCommand(Context context) {
        this->context = context;
    }

    string execute(Request request) override {
        return context.getBucketService().getBucket();
    }

    string toString() override {
        return "--bucket - print all products from bucket";
    }

private:
    Context context;
};