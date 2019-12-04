#pragma once

#include <utility>
#include "../core/Util.h"
#include "../service/ProductService.h"
#include "../service/BucketService.h"

class Context {
private:
    ProductService *productService{};
    BucketService *bucketService{};
public:
    Context() {
        productService = new ProductService(new ProductDao);
        bucketService = new BucketService(new BucketDao);
    }

    Context(ProductService *prods, BucketService *bucks) {
        this->productService = prods;
        this->bucketService = bucks;
    }

    ProductService getProductService() {
        return *productService;
    }

    BucketService getBucketService() {
        return *bucketService;
    }
};

