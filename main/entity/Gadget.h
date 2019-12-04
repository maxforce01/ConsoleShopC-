#pragma once

#include <string>
#include <utility>

using std::string;

class Gadget {
public:
    Gadget() = default;

    Gadget(long id, string name, string model, int weight, double price) {
        this->id = id;
        this->name = std::move(name);
        this->model = std::move(model);
        this->diagonal = weight;
        this->price = price;
    }

    void setName(string name) {
        this->name = name;
    }

    void setModel(string name) {
        this->model = name;
    }

    void setId(long name) {
        this->id = name;
    }

    void setPrice(double name) {
        this->price = name;
    }

    void setDiagonal(int name) {
        this->diagonal = name;
    }

    string getName() const {
        return name;
    }

    string getModel() const {
        return model;
    }

    long getId() const {
        return id;
    }

    int getDiagonal() const {
        return diagonal;
    }

    double getPrice() const {
        return price;
    }

private:
    string name;
    string model;
    int diagonal{};
    long id{};
    double price{};
};

struct less_car : std::binary_function<const Gadget *, const Gadget *, bool> {
    bool operator()(const Gadget *a, const Gadget *b) const {
        return a->getId() < a->getId() && a->getName() < b->getName() && a->getModel() < b->getModel() &&
               a->getPrice() < b->getPrice() && a->getDiagonal() < b->getDiagonal();
    }
};


