#include "Gates.h"

#include <iostream>
#include <stdexcept>

using namespace std;

ANDGate::ANDGate() : LogicGate("AND Gate", "F = A . B") {}

bool ANDGate::evaluate(bool a, bool b) {
    return a && b;
}

void ANDGate::displaySymbol() {
    cout << R"(

        A ----|\
              | )---- A.B
        B ----|/

        )";
}

void ANDGate::truthTable() {
    cout << "\nAND TRUTH TABLE\n";
    cout << "A | B | F\n";
    cout << "----------\n";
    for (int a = 0; a <= 1; a++)
        for (int b = 0; b <= 1; b++)
            cout << a << " | " << b << " | " << (a && b) << "\n";
}

void ANDGate::explain() {
    cout << "AND outputs 1 only if BOTH inputs are 1.\n";
}

ORGate::ORGate() : LogicGate("OR Gate", "F = A + B") {}

bool ORGate::evaluate(bool a, bool b) {
    return a || b;
}

void ORGate::displaySymbol() {
    cout << R"(

        A ----\
               )---- A+B
        B ----/

        )";
}

void ORGate::truthTable() {
    cout << "\nOR TRUTH TABLE\n";
    cout << "A | B | F\n";
    cout << "----------\n";
    for (int a = 0; a <= 1; a++)
        for (int b = 0; b <= 1; b++)
            cout << a << " | " << b << " | " << (a || b) << "\n";
}

void ORGate::explain() {
    cout << "OR outputs 1 if AT LEAST one input is 1.\n";
}

NOTGate::NOTGate() : LogicGate("NOT Gate", "F = A'") {}

bool NOTGate::evaluate(bool a, bool b) {
    (void)b;
    return !a;
}

void NOTGate::displaySymbol() {
    cout << R"(

        A ----|>o---- A'

        )";
}

void NOTGate::truthTable() {
    cout << "\nNOT TRUTH TABLE\n";
    cout << "A | F\n";
    cout << "------\n";
    for (int a = 0; a <= 1; a++)
        cout << a << " | " << !a << "\n";
}

void NOTGate::explain() {
    cout << "NOT inverts the input.\n";
}

NANDGate::NANDGate() : LogicGate("NAND Gate", "F = (A . B)'") {}

bool NANDGate::evaluate(bool a, bool b) {
    return !(a && b);
}

void NANDGate::displaySymbol() {
    cout << R"(

        A ----|\
              | )o--- (A.B)'
        B ----|/

        )";
}

void NANDGate::truthTable() {
    cout << "\nNAND TRUTH TABLE\n";
    cout << "A | B | F\n";
    cout << "----------\n";
    for (int a = 0; a <= 1; a++)
        for (int b = 0; b <= 1; b++)
            cout << a << " | " << b << " | " << !(a && b) << "\n";
}

void NANDGate::explain() {
    cout << "NAND is NOT of AND.\n";
}

NORGate::NORGate() : LogicGate("NOR Gate", "F = (A + B)'") {}

bool NORGate::evaluate(bool a, bool b) {
    return !(a || b);
}

void NORGate::displaySymbol() {
    cout << R"(

        A ----\
               )o--- (A+B)'
        B ----/

        )";
}

void NORGate::truthTable() {
    cout << "\nNOR TRUTH TABLE\n";
    cout << "A | B | F\n";
    cout << "----------\n";
    for (int a = 0; a <= 1; a++)
        for (int b = 0; b <= 1; b++)
            cout << a << " | " << b << " | " << !(a || b) << "\n";
}

void NORGate::explain() {
    cout << "NOR is NOT of OR.\n";
}

XORGate::XORGate() : LogicGate("XOR Gate", "F = A'B + AB'") {}

bool XORGate::evaluate(bool a, bool b) {
    return a ^ b;
}

void XORGate::displaySymbol() {
    cout << R"(

        A ----\
             ))---- A'B + AB'
        B ----/

        )";
}

void XORGate::truthTable() {
    cout << "\nXOR TRUTH TABLE\n";
    cout << "A | B | F\n";
    cout << "----------\n";
    for (int a = 0; a <= 1; a++)
        for (int b = 0; b <= 1; b++)
            cout << a << " | " << b << " | " << (a ^ b) << "\n";
}

void XORGate::explain() {
    cout << "XOR outputs 1 when inputs are DIFFERENT.\n";
}

XNORGate::XNORGate() : LogicGate("XNOR Gate", "F = AB + A'B'") {}

bool XNORGate::evaluate(bool a, bool b) {
    return !(a ^ b);
}

void XNORGate::displaySymbol() {
    cout << R"(

        A ----\
             ))o--- Y
        B ----/

        )";
}

void XNORGate::truthTable() {
    cout << "\nXNOR TRUTH TABLE\n";
    cout << "A | B | F\n";
    cout << "----------\n";
    for (int a = 0; a <= 1; a++)
        for (int b = 0; b <= 1; b++)
            cout << a << " | " << b << " | " << !(a ^ b) << "\n";
}

void XNORGate::explain() {
    cout << "XNOR outputs 1 when inputs are THE SAME.\n";
}

LogicGate* createGate(int gateChoice) {
    switch (gateChoice) {
        case 1: return new ANDGate();
        case 2: return new ORGate();
        case 3: return new NOTGate();
        case 4: return new NANDGate();
        case 5: return new NORGate();
        case 6: return new XORGate();
        case 7: return new XNORGate();
        default: throw invalid_argument("Invalid gate!");
    }
}
