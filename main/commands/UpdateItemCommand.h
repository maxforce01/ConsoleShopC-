#include "Command.h"
#include "../core/Context.h"


//
// Created by maxforce01 on 04.12.2019.
//
class UpdateItemCommand : public Command {
public:
    UpdateItemCommand(Context context) {
        this->context = context;
    }

    string execute(Request request) override {
        if (request.getArgs().empty()) {
            return "Invalid args";
        }
        int id = atoi(request.getArg(0).c_str());
        if (id <= 0) {
            return "invalid value";
        }
        Gadget *gadget = context.getProductService().getProduct(id);
        if (request.getArgs().size() > 1) {
            switchParam(request.getArg(1), gadget);
        } else {
            setParameters(gadget);
        }
        return "Success!";
    }

    string toString() override {
        return "--update {id} {field or count} - updating item";
    }

private:
    Context context;

    void switchParam(string param, Gadget *gadget) {
        if (param == "name") {
            gadget->setName(getName());
            return;
        }
        if (param == "model") {
            gadget->setModel(getModel());
            return;
        }
        if (param == "price") {
            gadget->setPrice(getPrice());
            return;
        }
        if (param == "diagonal") {
            gadget->setDiagonal(getDiagonal());
            return;
        }
        if(param == "count"){
            context.getProductService().updateProduct(gadget,getCount());
            return;
        }
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
        cout<<"Enter price"<<endl;;
        return Util::enterDouble();
    }

    int getDiagonal() {
        cout<<"Enter diagonal"<<endl;;
        return Util::enterInteger();
    }

    int getCount() {
        cout<<"Enter count"<<endl;;
        return Util::enterInteger();
    }
};