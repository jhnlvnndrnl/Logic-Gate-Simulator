#ifndef LOGIC_GATE_H
#define LOGIC_GATE_H

#include <string>

using namespace std;

// ABSTRACTION: This base class has pure virtual functions.
class LogicGate {
private:
    string name;
    string formula;

public:
    LogicGate(string n, string f);
    virtual ~LogicGate();

    // ENCAPSULATION: private data is accessed using getters and setters.
    void setName(string n);
    void setFormula(string f);
    string getName();
    string getFormula();

    virtual bool evaluate(bool a, bool b) = 0;
    virtual void displaySymbol() = 0;
    virtual void truthTable() = 0;
    virtual void explain() = 0;

    void showInfo();
};

#endif
