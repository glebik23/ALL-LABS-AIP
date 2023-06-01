#include <iostream>
#include <string>

using namespace std;

class Car {
protected:
    string model;
    int MaxSkorost;
public:
    Car(string model, int MaxSkorost) {
        this->model = model;
        this->MaxSkorost = MaxSkorost;
    }
    virtual void print() {
        cout << "Модель: " << model << endl;
        cout << "Максимальная скорость: " << MaxSkorost << " км/ч" << endl;
    }
};

class Lorry : public Car {
private:
    int gruz;
public:
    Lorry(string model, int MaxSkorost, int gruz) : Car(model, MaxSkorost) {
        this->gruz = gruz;
    }
    void print() override {
        Car::print();
        cout << "Грузоподъёмность: " << gruz << " тонн" << endl;
    }
};

int main()
{
    setlocale(0, "Ru");
    Car car("BMW", 250);
    Lorry lorry("Volvo", 180, 20);

    car.print();
    cout << endl;
    lorry.print();

    Car* carPtr = &car;
    Car* lorryPtr = &lorry;

    cout << endl;
    carPtr->print();
    cout << endl;
    lorryPtr->print();

    return 0;
}