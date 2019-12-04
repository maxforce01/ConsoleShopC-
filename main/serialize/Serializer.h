#pragma once

#include "SerializeProduct.h"
#include <vector>

class Serializer {
public:
    static void toJson(string filename, std::vector<SerializeProduct> products) {
        json globalJson = json::parse("{}");
        std::fstream fst;
        fst.open(filename);
        for (auto product:products) {
            globalJson[std::to_string(product.getGadget()->getId())] = product.toJson();
        }
        fst << globalJson;
        fst.close();
    }

    static std::vector<SerializeProduct> fromJson(string filename) {
        std::fstream fst;
        std::vector<SerializeProduct> returnProducts;
        fst.open(filename);
        json globalJson;
        fst >> globalJson;
        for (json products:globalJson) {
            SerializeProduct serializeProduct;
            for (json product:products) {
                if (product.is_object()) {
                    Gadget *gadget = new Gadget();
                    gadget->setId(product["id"].get<long>());
                    gadget->setDiagonal(product["diagonal"].get<int>());
                    gadget->setPrice(product["price"].get<double>());
                    gadget->setName(product["name"].get<std::string>());
                    gadget->setModel(product["model"].get<std::string>());
                    serializeProduct.setGadget(gadget);
                } else {
                    serializeProduct.setCount(product.back());
                }
            }
            returnProducts.push_back(serializeProduct);
        }
        return returnProducts;
    }
};