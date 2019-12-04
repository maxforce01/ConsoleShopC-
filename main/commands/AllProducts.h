#include "Command.h"

class AllProducts : public Command {
public:
    AllProducts(Context context) {
        this->context = context;
    }

    string execute(Request requset) override {
        ProductService productService = context.getProductService();
        return productService.getProducts();
    }

    string toString() override {
        return "--all - print all products";
    }

private:
    Context context;
};

