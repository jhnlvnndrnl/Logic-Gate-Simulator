#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

// ABSTRACT BASE CLASS
class PhysicsModule {
protected:
    string moduleName;

public:
    PhysicsModule(string name) {
        moduleName = name;
    }

    // VIRTUAL DESTRUCTOR
    virtual ~PhysicsModule() {}

    // COMMON TITLE DISPLAY
    virtual void displayTitle() {
        cout << "\n====================================\n";
        cout << " " << moduleName << "\n";
        cout << "====================================\n";
    }

    // PURE VIRTUAL FUNCTION
    virtual void calculate() = 0;
};


// OSCILLATION
class Oscillation : public PhysicsModule {
private:
    double mass;
    double springConstant;

public:
    Oscillation() : PhysicsModule("OSCILLATION MODULE") {}

    void calculate() override {
        displayTitle();

        cout << "Enter mass (kg): ";
        cin >> mass;

        cout << "Enter spring constant (N/m): ";
        cin >> springConstant;

        double frequency =
        (1.0 / (2.0 * M_PI)) * sqrt(springConstant / mass);

        cout << fixed << setprecision(2);

        cout << "\nOscillation Frequency: "
            << frequency << " Hz\n";
    }
};

// FLUIDS 
class Fluids : public PhysicsModule {
private:
    double density;
    double volume;

public:
    Fluids() : PhysicsModule("FLUIDS MODULE") {}

    void calculate() override {
        displayTitle();

        cout << "Enter density (kg/m^3): ";
        cin >> density;

        cout << "Enter volume (m^3): ";
        cin >> volume;

        double mass = density * volume;

        cout << fixed << setprecision(2);

        cout << "\nFluid Mass: "
            << mass << " kg\n";
    }
};

// HEAT TRANSFER MODULE
class HeatTransfer : public PhysicsModule {
private:
    double mass;
    double specificHeat;
    double temperatureChange;

public:
    HeatTransfer() : PhysicsModule("HEAT TRANSFER MODULE") {}

    void calculate() override {
        displayTitle();

        cout << "Enter mass (kg): ";
        cin >> mass;

        cout << "Enter specific heat capacity: ";
        cin >> specificHeat;

        cout << "Enter temperature change: ";
        cin >> temperatureChange;

        double heat =
        mass * specificHeat * temperatureChange;

        cout << fixed << setprecision(2);

        cout << "\nHeat Energy: "
            << heat << " Joules\n";
    }
};

// WAVES MODULE
class Waves : public PhysicsModule {
private:
    double frequency;
    double wavelength;

public:
    Waves() : PhysicsModule("WAVES MODULE") {}

    void calculate() override {
        displayTitle();

        cout << "Enter frequency (Hz): ";
        cin >> frequency;

        cout << "Enter wavelength (m): ";
        cin >> wavelength;

        double velocity =
        frequency * wavelength;

        cout << fixed << setprecision(2);

        cout << "\nWave Velocity: "
            << velocity << " m/s\n";
    }
};

// ELECTROSTATICS MODULE
class Electrostatics : public PhysicsModule {
private:
    double q1;
    double q2;
    double distance;

public:
    Electrostatics() : PhysicsModule("ELECTROSTATICS MODULE") {}

    void calculate() override {
        displayTitle();

        const double k = 8.99e9;

        cout << "Enter charge q1 (C): ";
        cin >> q1;

        cout << "Enter charge q2 (C): ";
        cin >> q2;

        cout << "Enter distance (m): ";
        cin >> distance;

        double force =
        (k * q1 * q2) / pow(distance, 2);

        cout << fixed << setprecision(2);

        cout << "\nElectrostatic Force: "
            << force << " N\n";
    }
};

// MAGNETISM MODULE
class Magnetism : public PhysicsModule {
private:
    double current;
    double magneticField;
    double length;

public:
    Magnetism() : PhysicsModule("MAGNETISM MODULE") {}

    void calculate() override {
        displayTitle();

        cout << "Enter current (A): ";
        cin >> current;

        cout << "Enter magnetic field (T): ";
        cin >> magneticField;

        cout << "Enter conductor length (m): ";
        cin >> length;

        double force =
        current * magneticField * length;

        cout << fixed << setprecision(2);

        cout << "\nMagnetic Force: "
            << force << " N\n";
    }
};

// OPTICS MODULE
class Optics : public PhysicsModule {
private:
    double focalLength;

public:
    Optics() : PhysicsModule("OPTICS MODULE") {}

    void calculate() override {
        displayTitle();

        cout << "Enter focal length (m): ";
        cin >> focalLength;

        double lensPower =
        1.0 / focalLength;

        cout << fixed << setprecision(2);

        cout << "\nLens Power: "
            << lensPower << " Diopters\n";
    }
};

// MENU CLASS
class Menu {
public:
    void showMenu() {
        cout << "\n====================================\n";
        cout << "   COMPUTER ENGINEERING TOOLBOX\n";
        cout << "====================================\n";
        cout << "1. Oscillations\n";
        cout << "2. Fluids\n";
        cout << "3. Heat Transfer\n";
        cout << "4. Waves\n";
        cout << "5. Electrostatics\n";
        cout << "6. Magnetism\n";
        cout << "7. Optics\n";
        cout << "8. Exit\n";
        cout << "====================================\n";
        cout << "Enter Choice: ";
    }
};

// MAIN FUNCTION
int main() {

    Menu menu;

    int choice;

    do {

        menu.showMenu();
        cin >> choice;

        PhysicsModule* module = nullptr;

        switch(choice) {

            case 1:
                module = new Oscillation();
                break;

            case 2:
                module = new Fluids();
                break;

            case 3:
                module = new HeatTransfer();
                break;

            case 4:
                module = new Waves();
                break;

            case 5:
                module = new Electrostatics();
                break;

            case 6:
                module = new Magnetism();
                break;

            case 7:
                module = new Optics();
                break;

            case 8:
                cout << "\nExiting Program...\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
                break;
        }

        if(module != nullptr) {
            module->calculate();
            delete module;
        }

    } while(choice != 8);

    return 0;
}