#include "Phone.h"

using std::string;

class SmartPhone : public Phone {
public:
    SmartPhone()
            : Phone() {

    }

    SmartPhone(long id, string name, string model, int weight, double price, int engine, int seats, int maxSpeed)
            : Phone(id, name, model, weight, price, engine, seats) {
        this->battaryCapacity = maxSpeed;
    }

    void setBattaryCapacity(int maxSpeed) {
        this->battaryCapacity = maxSpeed;
    }

    int getBattaryCapacity() {
        return battaryCapacity;
    }

private:
    int battaryCapacity;
};

