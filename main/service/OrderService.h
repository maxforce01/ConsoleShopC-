#include "../dao/OrderDao.h"

class OrderService {
private:
    OrderDao *orderDao;
public:
    OrderService() = default;

    OrderService(OrderDao *orderDao1) {
        orderDao = orderDao1;
    }

    string getAll() {
        string orders;
        for (auto order:orderDao->findAll()) {
            orders += "Order: id = " + to_string(order.getId()) + ", total payment = " +
                      to_string(order.getTotalPrice()) + ", date = " + order.getDate() + "\n";
        }
        return orders;
    }

    void add(Order order) {
        long id;
        if (orderDao->findAll().empty()) {
            id = 1;
        } else {
            id = orderDao->findAll().back().getId() + 1;
        }
        order.setId(id);
        orderDao->add(order);
    }

    void saveState(){
        orderDao->saveToJson();
    }
};