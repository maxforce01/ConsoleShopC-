#pragma once

#include "../../libs/json/single_include/nlohmann/json.hpp"
#include "../entity/Gadget.h"
#include <fstream>
#include <utility>
using json = nlohmann::json;

class SerializeProduct {
private:
    Gadget *gadget;
    int count = 0;
public:
    SerializeProduct() = default;

    SerializeProduct(Gadget *gadget, int count) : gadget(std::move(gadget)), count(count) {

    }

    Gadget* getGadget() const {
        return gadget;
    }

    void setGadget(Gadget *gadget) {
        SerializeProduct::gadget = gadget;
    }

    int getCount() const {
        return count;
    }

    void setCount(int count) {
        SerializeProduct::count = count;
    }
    json toJson() {
        json jsonObject;
        jsonObject["object"] = json::parse("{ "
                                           " \"id\": " + std::to_string(gadget->getId()) +
                                           ", \"name\": \"" + gadget->getName() + "\""
                                           ", \"model\": \""+gadget->getModel()+ "\""
                                           ", \"price\": "+std::to_string(gadget->getPrice())+""
                                           ", \"diagonal\": "+std::to_string(gadget->getDiagonal())+"}");
        jsonObject["count"] = count;
        return jsonObject;
    }
};
