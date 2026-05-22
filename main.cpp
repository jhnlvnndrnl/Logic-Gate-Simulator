#include "Gates.h"
#include "UI.h"
#include "UserProfile.h"

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// POLYMORPHISM: LogicGate* can point to any child gate object.
int main() {
    UserProfile user;
    string userName;

    cout << "Enter your name: ";
    getline(cin, userName);
    user.setUserName(userName);

    cout << "\nWelcome, " << user.getUserName() << "!\n";

    int mode;

    do {
        try {
            showMenu(user.getUserName());
            mode = readNumber("Invalid input!");

            if (mode < 1 || mode > 3) {
                throw invalid_argument("Invalid Choice!");
            }

            if (mode == 3) {
                cout << "\nGoodbye!\n";
                break;
            }

            showGateMenu();
            int gateChoice = readNumber("Invalid gate input!");

            if (gateChoice == 8) {
                continue;
            }

            if (mode == 1) {
                LogicGate* gate = createGate(gateChoice);

                printSection("GATE INFORMATION");
                gate->showInfo();
                gate->displaySymbol();
                gate->explain();
                gate->truthTable();
                printLine('-');

                delete gate;
                continue;
            }

            int a, b;

            cout << "Enter A (0 or 1): ";
            a = readNumber("Invalid input!");

            if (a != 0 && a != 1) {
                throw invalid_argument("Invalid input!");
            }

            cout << "Enter B (0 or 1): ";
            b = readNumber("Invalid input!");

            if (b != 0 && b != 1) {
                throw invalid_argument("Invalid input!");
            }

            LogicGate* gate = createGate(gateChoice);

            printSection("COMPUTATION RESULT");
            gate->showInfo();
            gate->displaySymbol();
            cout << "A = " << a << " | B = " << b << "\n";
            cout << "OUTPUT = " << gate->evaluate(a, b) << "\n";
            printLine('-');

            delete gate;
        } catch (invalid_argument& error) {
            cout << error.what() << "\n";
            clearInput();
        }
    } while (true);

    return 0;
}
