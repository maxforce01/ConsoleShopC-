#pragma once

class Order {
private:
    long id;
    string date;
    double totalPrice;
public:
    long getId() const {
        return id;
    }

    void setId(long id) {
        Order::id = id;
    }

    const string &getDate() const {
        return date;
    }

    void setDate(const string &date) {
        Order::date = date;
    }

    double getTotalPrice() const {
        return totalPrice;
    }

    void setTotalPrice(double totalPrice) {
        Order::totalPrice = totalPrice;
    }

    json toJson() {
        return json::parse("{ "" \"id\": " + std::to_string(getId()) +
        R"(, "date": ")" + getDate() + "\"" ", \"price\": " +std::to_string(getTotalPrice()) + "}");
    }
};

