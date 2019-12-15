//
// Created by maxforce01 on 12.12.2019.
//

#include "Command.h"
#include "../core/Context.h"

class AllOrdersCommand : public Command {
private:
    Context context;
public:
    AllOrdersCommand(Context context) {
        this->context = context;
    }

    string execute(Request request) override {
        return context.getOrderService().getAll();
    }

    string toString() override {
        return "--orders - all orders;";
    }
};