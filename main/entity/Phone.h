#include "Gadget.h"

using std::string;

class Phone : public Gadget {
public:
    Phone(): Gadget() {

    }

    Phone(long id, string name, string model, int weight, double price, int engine, int seats)
            : Gadget(id, name, model, weight, price) {
        this->camera = engine;
        this->simCount = seats;
    }

    int getCamera() {
        return camera;
    }

    int getSimCount() {
        return simCount;
    }

    void setCamera(int engine) {
        this->camera = engine;
    }

    void setSimCount(int seats) {
        this->simCount = seats;
    }

private:
    int camera;
    int simCount;
};

