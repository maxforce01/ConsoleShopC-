#pragma once

#include <utility>
#include "../core/Util.h"
#include "../service/ProductService.h"
#include "../service/BucketService.h"
#include "../service/OrderService.h"

class Context {
private:
    ProductService *productService{};
    BucketService *bucketService{};
    OrderService *orderService;
public:
    Context() {
        productService = new ProductService(new ProductDao);
        bucketService = new BucketService(new BucketDao);
    }

    Context(ProductService *pService, BucketService *pService1, OrderService *pService2) {
        this->productService = pService;
        this->bucketService = pService1;
        this->orderService = pService2;
    }

    ProductService getProductService() {
        return *productService;
    }

    BucketService getBucketService() {
        return *bucketService;
    }

    OrderService getOrderService() {
        return *orderService;
    }

};

