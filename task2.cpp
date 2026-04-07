#include <iostream>
#include <string>
using namespace std;

class SmartDevice {
public:
    virtual void   turnOn()    = 0;   
    virtual void   turnOff()   = 0;   
    virtual string getStatus() = 0;  

    virtual ~SmartDevice() {}
};

class LightBulb : public SmartDevice {
private:
    bool isOn;
    int  brightness;  
public:
    LightBulb(int b = 75) : isOn(false), brightness(b) {}

    void turnOn() override {
        isOn = true;
        cout << "[LightBulb] Turned ON  | Brightness: "
             << brightness << "%" << endl;
    }

    void turnOff() override {
        isOn = false;
        cout << "[LightBulb] Turned OFF" << endl;
    }

    void setBrightness(int b) {
        brightness = (b < 0) ? 0 : (b > 100) ? 100 : b;
        cout << "[LightBulb] Brightness set to " << brightness << "%" << endl;
    }

    string getStatus() override {
        return string("[LightBulb] Status : ") +
               (isOn ? "ON" : "OFF") +
               " | Brightness: " + to_string(brightness) + "%";
    }
};

class Thermostat : public SmartDevice {
private:
    bool   isOn;
    double temperature;   
public:
    Thermostat(double temp = 22.0) : isOn(false), temperature(temp) {}

    void turnOn() override {
        isOn = true;
        cout << "[Thermostat] Turned ON  | Temp: "
             << temperature << " C" << endl;
    }

    void turnOff() override {
        isOn = false;
        cout << "[Thermostat] Turned OFF" << endl;
    }

    void setTemperature(double t) {
        temperature = t;
        cout << "[Thermostat] Temperature set to " << t << " C" << endl;
    }

    string getStatus() override {
        return string("[Thermostat] Status : ") +
               (isOn ? "ON" : "OFF") +
               " | Temp: " + to_string(temperature) + " C";
    }
};

int main() {
    LightBulb  bulb(60);
    Thermostat thermo(24.0);

    SmartDevice* devices[] = { &bulb, &thermo };
    int count = sizeof(devices) / sizeof(devices[0]);

    cout << " Turning all devices ON " << endl;
    for (int i = 0; i < count; i++)
        devices[i]->turnOn();

    cout << "\n Adjusting settings " << endl;
    bulb.setBrightness(90);
    thermo.setTemperature(20.5);

    cout << "\n Current statuses " << endl;
    for (int i = 0; i < count; i++)
        cout << devices[i]->getStatus() << endl;

    cout << "\n Turning all devices OFF " << endl;
    for (int i = 0; i < count; i++)
        devices[i]->turnOff();

    cout << "\n Final statuses " << endl;
    for (int i = 0; i < count; i++)
        cout << devices[i]->getStatus() << endl;

    return 0;
}