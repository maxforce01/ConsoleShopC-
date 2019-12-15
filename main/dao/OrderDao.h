#pragma once

#include <vector>
#include "../entity/Order.h"

using namespace std;

class OrderDao {
private:
    vector<Order> orders;
public:
    OrderDao() = default;

    OrderDao(vector<Order> orders) {
        this->orders = orders;
    }

    void add(Order order) {
        orders.push_back(order);
    }

    Order find(long id) {
        for (auto order: orders) {
            if (order.getId() == id) {
                return order;
            }
        }
    }

    vector<Order> findAll() {
        return orders;
    }

    void saveToJson() {
        Serializer::toJson("orders.json", orders);
    }

    void loadFromJson() {
        orders = Serializer::ordersFromJson("orders.json");
    }
};

