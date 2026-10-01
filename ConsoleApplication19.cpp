#include <iostream>
#include <string>

using namespace std;

class Vehicle {
protected:
    string* brand;
    int* year;
    double* engineVolume;
    bool* isRunning;

public:
    Vehicle(string b = "Неизвестно", int y = 2000, double v = 1.5, bool r = false) {
        cout << "[Vehicle Constructor]" << endl;
        brand = new string(b);
        year = new int(y);
        engineVolume = new double(v);
        isRunning = new bool(r);
    }

    Vehicle(const Vehicle&) = delete;
    Vehicle& operator=(const Vehicle&) = delete;

    virtual ~Vehicle() {
        cout << "[Vehicle Destructor]" << endl;
        delete brand;
        delete year;
        delete engineVolume;
        delete isRunning;
    }

    void setBrand(string b) { *brand = b; }
    void setYear(int y) { *year = y; }
    void setEngineVolume(double v) { *engineVolume = v; }
    void setIsRunning(bool r) { *isRunning = r; }

    string getBrand() { return *brand; }
    int getYear() { return *year; }
    double getEngineVolume() { return *engineVolume; }
    bool getIsRunning() { return *isRunning; }

    void toggleEngine() {
        *isRunning = !*isRunning;
        cout << "Двигатель " << *brand << (*isRunning ? " заведён." : " заглушен.") << endl;
    }

    virtual void info() {
        cout << "Марка: " << *brand << ", год: " << *year
            << ", объём: " << *engineVolume << " л"
            << ", заведён: " << (*isRunning ? "да" : "нет") << endl;
    }
};

class Car : public Vehicle {
protected:
    int* doorsCount;

public:
    Car(string b = "Неизвестно", int y = 2000, double v = 1.5, bool r = false, int d = 4)
        : Vehicle(b, y, v, r) {
        cout << "[Car Constructor]" << endl;
        doorsCount = new int(d);
    }

    Car(const Car&) = delete;
    Car& operator=(const Car&) = delete;

    ~Car() override {
        cout << "[Car Destructor]" << endl;
        delete doorsCount;
    }

    void setDoorsCount(int d) { *doorsCount = d; }
    int getDoorsCount() { return *doorsCount; }

    void info() override {
        cout << "Автомобиль " << *brand << ", год: " << *year
            << ", объём: " << *engineVolume << " л"
            << ", дверей: " << *doorsCount
            << ", заведён: " << (*isRunning ? "да" : "нет") << endl;
    }
};

class Truck : public Vehicle {
protected:
    double* payload;

public:
    Truck(string b = "Неизвестно", int y = 2000, double v = 1.5, bool r = false, double p = 5.0)
        : Vehicle(b, y, v, r) {
        cout << "[Truck Constructor]" << endl;
        payload = new double(p);
    }

    Truck(const Truck&) = delete;
    Truck& operator=(const Truck&) = delete;

    ~Truck() override {
        cout << "[Truck Destructor]" << endl;
        delete payload;
    }

    void setPayload(double p) { *payload = p; }
    double getPayload() { return *payload; }

    void info() override {
        cout << "Грузовик " << *brand << ", год: " << *year
            << ", объём: " << *engineVolume << " л"
            << ", грузоподъёмность: " << *payload << " т"
            << ", заведён: " << (*isRunning ? "да" : "нет") << endl;
    }
};

class ElectricCar : public Car {
protected:
    double* batteryCapacity;

public:
    ElectricCar(string b = "Неизвестно", int y = 2000, double v = 1.5,
        bool r = false, int d = 4, double c = 60.0)
        : Car(b, y, v, r, d) {
        cout << "[ElectricCar Constructor]" << endl;
        batteryCapacity = new double(c);
    }

    ElectricCar(const ElectricCar&) = delete;
    ElectricCar& operator=(const ElectricCar&) = delete;

    ~ElectricCar() override {
        cout << "[ElectricCar Destructor]" << endl;
        delete batteryCapacity;
    }

    void setBatteryCapacity(double c) { *batteryCapacity = c; }
    double getBatteryCapacity() { return *batteryCapacity; }

    void info() override {
        cout << "Электромобиль " << *brand << ", год: " << *year
            << ", дверей: " << *doorsCount
            << ", батарея: " << *batteryCapacity << " кВт·ч"
            << ", заведён: " << (*isRunning ? "да" : "нет") << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    Vehicle* v = new Vehicle("Generic", 2015, 1.6);
    v->info();
    v->toggleEngine();
    delete v;

    Car* c = new Car("BMW", 2022, 3.0, false, 5);
    c->info();
    c->toggleEngine();
    delete c;

    Truck* t = new Truck("Volvo", 2018, 12.0, false, 25.0);
    t->info();
    t->toggleEngine();
    delete t;

    ElectricCar* e = new ElectricCar("Tesla", 2023, 0.0, false, 4, 120.0);
    e->info();
    e->toggleEngine();
    delete e;

    Vehicle* fleet[3];
    fleet[0] = new Car("Kia", 2021, 1.6, false, 4);
    fleet[1] = new Truck("MAN", 2019, 15.0, false, 30.0);
    fleet[2] = new ElectricCar("Nissan Leaf", 2022, 0.0, false, 5, 40.0);

    for (int i = 0; i < 3; i++) {
        fleet[i]->info();
        fleet[i]->toggleEngine();
    }

    for (int i = 0; i < 3; i++) {
        delete fleet[i];
    }

    return 0;
}


