//
// Created by maxforce01 on 03.12.2019.
//

#include "Command.h"
#include "../core/Context.h"

class DeleteItemCommand : public Command {
public:
    DeleteItemCommand(Context context) {
        this->context = context;
    }

    string toString() override {
        return "--delete {id} - deleting item from product list";
    }

private:
    string execute(Request request) override {
        if (request.getArgs().empty()) {
            return "Incorrect args";
        }
        int id = atoi(request.getArg(0).c_str());
        if (id <= 0) {
            return "invalid value";
        }
        if(context.getProductService().getProduct(id) == nullptr){
            return "Invalid id";
        }
        Gadget* gadget = context.getProductService().getProduct(id);
        context.getProductService().deleteProduct(gadget);
        return "Success!";
    }

    Context context;
};