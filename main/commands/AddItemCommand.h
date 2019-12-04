//
// Created by maxforce01 on 13.10.2019.
//
#include "Command.h"
#include "../entity/Tablet.h"


class AddItemCommand : public Command {
public:
    explicit AddItemCommand(Context context) {
        this->context = std::move(context);
    }

    string execute(Request request) override {
        if (request.getArgs().size() < 2) {
            return "invalid request";
        }
        Gadget *gadget = switchGadget(request);
        if (gadget == nullptr) {
            return "no such item";
        }
        int count = atoi(request.getArg(1).c_str());
        if (count <= 0) {
            return "invalid value";
        }
        context.getProductService().addProduct(gadget, count);
        return "success";
    }

    string toString() override {
        return "--add {id} - creating new product";
    }

private:
    Context context;

    Gadget *switchGadget(Request request) {
        Gadget *gadget = nullptr;
        string req = request.getArg(0);
        if (req == "smartphone") {
            gadget = new SmartPhone();
            setParameters(gadget);
        } else if (req == "tablet") {
            gadget = new Tablet();
            setParameters(gadget);
        }
        return gadget;
    }

    void setParameters(Gadget *gadget) {
        gadget->setPrice(getPrice());
        gadget->setName(getName());
        gadget->setModel(getModel());
        gadget->setDiagonal(getDiagonal());
    }

    string getName() {
        string name;
        cout << "Enter name" << endl;
        cin >> name;
        return name;
    }

    string getModel() {
        string name;
        cout << "Enter model" << endl;
        cin >> name;
        return name;
    }

    double getPrice() {
        return Util::enterDouble();
    }

    int getDiagonal() {
        return Util::enterInteger();
    }
};
