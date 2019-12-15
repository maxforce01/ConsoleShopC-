#include "Command.h"
#include "../core/Context.h"

class SaveStateCommand : public Command {

public:
    explicit SaveStateCommand(Context context) {
        this->context = context;
    }

    string execute(Request request) override {
        context.getProductService().saveProductList();
        context.getOrderService().saveState();
        return std::__cxx11::string();
    }

    string toString() override {
        return "--save - serialize all items into the file";
    }

private:
    Context context;
};

