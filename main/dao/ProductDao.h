#pragma once

#include "map"
#include <vector>
#include "../entity/Gadget.h"
#include "../serialize/Serializer.h"
#include "../serialize/SerializeProduct.h"

using namespace std;

class ProductDao {
public:
    ProductDao() = default;

    void add(Gadget *car, int count) {
        products.insert(make_pair(car, count));
    }

    _Rb_tree_iterator<pair<Gadget *const, int>> findIter(Gadget *pGadget) {
        for (_Rb_tree_iterator<pair<Gadget *const, int>> it = products.begin(); it != products.end(); ++it) {
            if (it.operator*().first->getId() == pGadget->getId()) {
                return it;
            }
        }
    }

    void remove(Gadget *gadget) {
        products.erase(findIter(gadget));
    }


    void update(Gadget *car, int count) {
        remove(car);
        products.insert(make_pair(car, count));
    }

    Gadget *find(long id) {
        for (auto &it : findAll()) {
            if (it.first->getId() == id) {
                return it.first;
            }
        }
        return nullptr;
    }

    int findCountById(long id) {
        for (auto &it : findAll()) {
            if (it.first->getId() == id) {
                return it.second;
            }
        }
        return 0;
    }

    multimap<Gadget *, int, less_car> findAll() {
        return products;
    }

    void saveToJson() {
        vector<SerializeProduct> serializeProducts;
        for (auto product:products) {
            SerializeProduct serializeProduct(product.first, product.second);
            serializeProducts.push_back(serializeProduct);
        }
        Serializer::toJson("products.json", serializeProducts);
    }

    void loadFromJson() {
        vector<SerializeProduct> serializeProducts = Serializer::fromJson("products.json");
        for (auto serObject: serializeProducts) {
            add(serObject.getGadget(), serObject.getCount());
        }
    }

private:
    multimap<Gadget *, int, less_car> products;
};

