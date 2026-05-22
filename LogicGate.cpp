#include "LogicGate.h"

#include <iostream>

using namespace std;

LogicGate::LogicGate(string n, string f) {
    setName(n);
    setFormula(f);
}

LogicGate::~LogicGate() {}

void LogicGate::setName(string n) {
    name = n;
}

void LogicGate::setFormula(string f) {
    formula = f;
}

string LogicGate::getName() {
    return name;
}

string LogicGate::getFormula() {
    return formula;
}

void LogicGate::showInfo() {
    cout << "Gate: " << getName() << "\n";
    cout << "Formula: " << getFormula() << "\n";
}
