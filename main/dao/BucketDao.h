#pragma once

#include "map"
#include "../entity/Gadget.h"

using namespace std;

class BucketDao {
public:
    explicit BucketDao(map<Gadget *, int> products) {
        this->products = products;
    }

    BucketDao() = default;

    void add(Gadget *car, int count) {
        products.insert(make_pair(car, count));
    }

    void remove(Gadget *car) {
        products.erase(car);
    }

    void update(Gadget *car, int count) {
        remove(car);
        add(car, count);
    }

    Gadget *find(long id) {
        for (auto &it : findAll()) {
            if (it.first->getId() == id) {
                return it.first;
            }
        }
        return new Gadget();
    }

    map<Gadget *, int> findAll() {
        return products;
    }

    void clear(){
        products.clear();
    }

private:
    map<Gadget *, int> products;

    int findCount(Gadget *car) {
        return (*products.find(car)).second;
    }
};


