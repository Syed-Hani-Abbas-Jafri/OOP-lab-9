#include <iostream>
using namespace std;

class Activity {
public:
    virtual double calculateCaloriesBurned() const = 0;
    virtual ~Activity() {}
};

class Running : public Activity {
private:
    double distance;
    double time;

public:
    Running(double d, double t) : distance(d), time(t) {}

    double calculateCaloriesBurned() const override {
        return distance * 60;
    }
};

class Cycling : public Activity {
private:
    double speed;
    double time;

public:
    Cycling(double s, double t) : speed(s), time(t) {}

    double calculateCaloriesBurned() const override {
        return speed * time * 30;
    }
};

int main() {
    Activity* a1;
    Activity* a2;

    Running run(5.0, 30.0);
    Cycling cycle(20.0, 1.0);

    a1 = &run;
    a2 = &cycle;

    cout << "Fitness Activity Tracker:" << endl;
    cout << "Running Calories Burned: "
         << a1->calculateCaloriesBurned() << " kcal" << endl;

    cout << "Cycling Calories Burned: "
         << a2->calculateCaloriesBurned() << " kcal" << endl;

    return 0;
}
