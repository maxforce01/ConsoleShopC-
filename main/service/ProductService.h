#pragma once

#include "../dao/ProductDao.h"

using namespace std;

class ProductService {
public:
    explicit ProductService(ProductDao *productDao) {
        this->productDao = productDao;
    }

    multimap<Gadget *, int, less_car> findAll() {
        return productDao->findAll();
    }

    string getProducts() {
        multimap<Gadget *, int, less_car> m = productDao->findAll();
        string products;
        for (auto &it : m)
            products += "id: " + to_string(it.first->getId()) + " Model: " + it.first->getModel() + " Brand: " +
                        it.first->getName() + " Price: " + to_string(it.first->getPrice()) + "Count: " +
                        to_string(it.second) + "\n";
        return products;
    }

    void addProduct(Gadget *car, int count) {
        long id = findMaxId();
        car->setId(id + 1);
        productDao->add(car, count);
    }

    void updateProduct(Gadget *car, int count) {
        productDao->update(car, count);
    }

    void saveProductList() {
        productDao->saveToJson();
    }

    void deleteProduct(Gadget *gadget) {
        productDao->remove(gadget);
    }

    Gadget *getProduct(long id) {
        return productDao->find(id);
    }

    int getProductCount(long id){
        return productDao->findCountById(id);
    }

private:
    ProductDao *productDao;

    long findMaxId() {
        long max = 1;
        for (auto &it : productDao->findAll()) {
            if (it.first->getId() > max) {
                max = it.first->getId();
            }
        }
        return max;
    }
};

