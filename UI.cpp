#include "UI.h"

#include <iostream>
#include <limits>
#include <stdexcept>

using namespace std;

void printLine(char symbol) {
    for (int i = 0; i < 40; i++) {
        cout << symbol;
    }
    cout << "\n";
}

void printHeader(string title) {
    cout << "\n";
    printLine('=');
    cout << " " << title << "\n";
    printLine('=');
}

void printSection(string title) {
    cout << "\n";
    printLine('-');
    cout << " " << title << "\n";
    printLine('-');
}

void showMenu(string user) {
    printHeader("LOGIC GATE SIMULATOR");
    cout << " User: " << user << "\n";
    printLine('-');
    cout << "1. DEFINITION MODE\n";
    cout << "2. COMPUTATION MODE\n";
    cout << "3. Exit\n";
    printLine('=');
    cout << "Enter choice: ";
}

void showGateMenu() {
    printHeader("SELECT GATE");
    cout << "1. AND\n";
    cout << "2. OR\n";
    cout << "3. NOT\n";
    cout << "4. NAND\n";
    cout << "5. NOR\n";
    cout << "6. XOR\n";
    cout << "7. XNOR\n";
    cout << "8. Main Menu\n";
    printLine('=');
    cout << "Choice: ";
}

int readNumber(string errorMessage) {
    int number;

    if (!(cin >> number)) {
        throw invalid_argument(errorMessage);
    }

    return number;
}

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
