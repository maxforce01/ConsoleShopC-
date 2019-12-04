//
// Created by maxforce01 on 04.12.2019.
//

#include "Command.h"
#include "../core/Context.h"

class SaveProductIntoBucket : public Command {
public:
    SaveProductIntoBucket(Context context) {
        this->context = context;
    }

    string execute(Request request) override {
        if (request.getArgs().empty()) {
            return "Incorrect args";
        }
        int id = atoi(request.getArg(0).c_str());
        if (id <= 0) {
            return "invalid value";
        }
        if (context.getProductService().getProduct(id) == nullptr) {
            return "Invalid id";
        }
        int count = 1;
        if (request.getArgs().size() > 1) {
            count = atoi(request.getArg(1).c_str());
            if (id <= 0) {
                return "invalid value";
            }
        }
        int productCount = context.getProductService().getProductCount(id);
        if (productCount > count && productCount-count>=0) {
            Gadget *gadget = context.getProductService().getProduct(id);
            context.getBucketService().addProduct(gadget, count);
            context.getProductService().updateProduct(gadget,productCount-count);
            return "Success!";
        }
        return "Invalid count";
    }

    string toString() override {
        return "--saveItem {id} - add item to the bucket";
    }

private:
    Context context;
};