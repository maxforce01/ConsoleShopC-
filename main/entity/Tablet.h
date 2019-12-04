class Tablet : public Phone {
public:
    Tablet() = default;

    Tablet(long id, const string &name, const string &model, int weight, double price, int engine, int seats,
           int battaryCapacity) : Phone(
            id, name, model, weight, price, engine, seats) {
        this->battaryCapacity = battaryCapacity;
    }


    void setBattaryCapacity(int maxSpeed) {
        this->battaryCapacity = maxSpeed;
    }

    int getBattaryCapacity() {
        return battaryCapacity;
    }

private:
    int battaryCapacity{};
};
