#include "Command.h"
#include "../core/Context.h"
#include "../entity/Order.h"
#include <ctime>

//
// Created by maxforce01 on 12.12.2019.
//
class BuyProductsCommand : public Command {
private:
    Context context;
public:
    BuyProductsCommand(Context context) {
        this->context = context;
    }

    string execute(Request request) override {
        int payAmount;
        cout << "Your payment = " + to_string(context.getBucketService().getPayAmount());
        cout << "Enter your payment \n";
        payAmount = Util::enterInteger();
        if (payAmount < context.getBucketService().getPayAmount()) {
            return "Not enough money";
        }
        Order order;
        order.setDate(currentDateTime());
        order.setTotalPrice(payAmount);
        context.getOrderService().add(order);
        context.getBucketService().clear();
        return "Successful";
    }

    string toString() override {
        return "--buy {payment} - buy all products from cart";
    }

    const std::string currentDateTime() {
        time_t now = time(0);
        struct tm tstruct;
        char buf[80];
        tstruct = *localtime(&now);
        strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);

        return buf;
    }
};