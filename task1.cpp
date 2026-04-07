#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string model;
    double rate;
public:
    Vehicle(string m, double r) : model(m), rate(r) {}

    virtual double getDailyRate()   = 0;   
    virtual void   displayDetails() = 0;   
    virtual ~Vehicle() {}                  
}
class Car : public Vehicle {
public:
    Car(string m, double r) : Vehicle(m, r) {}

    double getDailyRate() override {
        return rate;
    }

    void displayDetails() override {
        cout << "--- Car Rental ---"               << endl;
        cout << "Model      : " << model            << endl;
        cout << "Daily Rate : Rs. " << getDailyRate()
             << " / day"                            << endl;
    }
};

class Bike : public Vehicle {
public:
    Bike(string m, double r) : Vehicle(m, r) {}

    double getDailyRate() override {
        return rate;
    }

    void displayDetails() override {
        cout << "--- Bike Rental ---"               << endl;
        cout << "Model      : " << model            << endl;
        cout << "Daily Rate : Rs. " << getDailyRate()
             << " / day"                            << endl;
    }
};

int main() {
    Vehicle* vehicles[] = {
        new Car ("Toyota Corolla", 5000),
        new Car ("Honda Civic",    6500),
        new Bike("Yamaha YZF",     1500),
        new Bike("Honda CD 70",     800)
    };

    int count = sizeof(vehicles) / sizeof(vehicles[0]);

    for (int i = 0; i < count; i++) {
        vehicles[i]->displayDetails();
        cout << endl;
    }

    for (int i = 0; i < count; i++)
        delete vehicles[i];

    return 0;
}