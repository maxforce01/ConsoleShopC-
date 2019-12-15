#pragma once

#include "../dao/BucketDao.h"

using namespace std;

class BucketService {
public:
    explicit BucketService(BucketDao *productDao) {
        this->productDao = productDao;
    }

    string getBucket() {
        map<Gadget *, int> m = productDao->findAll();
        string products;
        for (auto &it : m)
            products += "id: " + to_string(it.first->getId()) + " Model: " + it.first->getModel() + " Brand: " +
                        it.first->getName() + " Price: " + to_string(it.first->getPrice()) + "Count: " +
                        to_string(it.second) + "\n";
        return products;
    }

    void addProduct(Gadget *car, int count) {
        productDao->add(car, count);
    }

    int getPayAmount() {
        int amount = 0;
        for (auto product: productDao->findAll()) {
            amount += product.first->getPrice() * product.second;
        }
        return amount;
    }

    void clear() {
        productDao->clear();
    }

private:
    BucketDao *productDao;
};

