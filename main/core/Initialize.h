#include <utility>

#include "Context.h"
#include "../service/ProductService.h"
#include "../service/BucketService.h"
#include "../entity/SmartPhone.h"

using std::string;

class Initialize {
public:
    explicit Initialize() {
        auto *bucks = new BucketService(initBucket());
        auto *prods = new ProductService(initProducts());
        context = new Context(prods, bucks);
    }

    Context getContext() {
        return *context;
    }

private:
    Context *context;

    static BucketDao *initBucket() {
        return new BucketDao();
    }

    static ProductDao *initProducts() {
        auto *productDao = new ProductDao();
        productDao->loadFromJson();
        return productDao;
    }
};