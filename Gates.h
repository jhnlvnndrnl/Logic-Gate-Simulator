#ifndef GATES_H
#define GATES_H

#include "LogicGate.h"

// INHERITANCE: Each gate class inherits from LogicGate.
class ANDGate : public LogicGate {
public:
    ANDGate();
    bool evaluate(bool a, bool b) override;
    void displaySymbol() override;
    void truthTable() override;
    void explain() override;
};

class ORGate : public LogicGate {
public:
    ORGate();
    bool evaluate(bool a, bool b) override;
    void displaySymbol() override;
    void truthTable() override;
    void explain() override;
};

class NOTGate : public LogicGate {
public:
    NOTGate();
    bool evaluate(bool a, bool b) override;
    void displaySymbol() override;
    void truthTable() override;
    void explain() override;
};

class NANDGate : public LogicGate {
public:
    NANDGate();
    bool evaluate(bool a, bool b) override;
    void displaySymbol() override;
    void truthTable() override;
    void explain() override;
};

class NORGate : public LogicGate {
public:
    NORGate();
    bool evaluate(bool a, bool b) override;
    void displaySymbol() override;
    void truthTable() override;
    void explain() override;
};

class XORGate : public LogicGate {
public:
    XORGate();
    bool evaluate(bool a, bool b) override;
    void displaySymbol() override;
    void truthTable() override;
    void explain() override;
};

class XNORGate : public LogicGate {
public:
    XNORGate();
    bool evaluate(bool a, bool b) override;
    void displaySymbol() override;
    void truthTable() override;
    void explain() override;
};

LogicGate* createGate(int gateChoice);

#endif
