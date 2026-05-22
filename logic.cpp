#include <iostream>
#include <string>

using namespace std;

// BASE CLASS
class LogicGate {
protected:
    string name;    
    string formula;

public:
    LogicGate(string n, string f) {
        name = n;
        formula = f;
    }

    virtual ~LogicGate() {}

    virtual bool evaluate(bool a, bool b) = 0;
    virtual void displaySymbol() = 0;
    virtual void truthTable() = 0;
    virtual void explain() = 0;

    void showInfo() {
        cout << "Gate: " << name << "\n";
        cout << "Formula: " << formula << "\n";
    }

    string getName() {
        return name;
    }
};

// AND
class ANDGate : public LogicGate {
public:
    ANDGate() : LogicGate("AND Gate", "F = A . B") {}

    bool evaluate(bool a, bool b) override {
        return a && b;
    }

    void displaySymbol() override {
        cout << R"(

        A --|‾‾‾‾‾‾‾‾\
                        )--- A.B
        B --|________/

        )";
    }

    void truthTable() override {
        cout << "\nAND TRUTH TABLE\n";
        cout << "A | B | F\n";
        cout << "----------\n";
        for (int a = 0; a <= 1; a++)
            for (int b = 0; b <= 1; b++)
                cout << a << " | " << b << " | " << (a && b) << "\n";
    }

    void explain() override {
        cout << "AND outputs 1 only if BOTH inputs are 1.\n";
    }
};

// OR
class ORGate : public LogicGate {
public:
    ORGate() : LogicGate("OR Gate", "F = A + B") {}

    bool evaluate(bool a, bool b) override {
        return a || b;
    }

    void displaySymbol() override {
        cout << R"(

        A --|‾‾‾‾‾‾‾‾‾\
                        >--- A+B
        B --|__________/

        )";
    }

    void truthTable() override {
        cout << "\nOR TRUTH TABLE\n";
        cout << "A | B | F\n";
        cout << "----------\n";
        for (int a = 0; a <= 1; a++)
            for (int b = 0; b <= 1; b++)
                cout << a << " | " << b << " | " << (a || b) << "\n";
    }

    void explain() override {
        cout << "OR outputs 1 if AT LEAST one input is 1.\n";
    }
};

// NOT
class NOTGate : public LogicGate {
public:
    NOTGate() : LogicGate("NOT Gate", "F = A'") {}

    bool evaluate(bool a, bool b) override {
        (void)b;
        return !a;
    }

    void displaySymbol() override {
        cout << R"(

               /\
         A ---/  \
             / NOT \---o--- A'
            /______/

        )";
    }

    void truthTable() override {
        cout << "\nNOT TRUTH TABLE\n";
        cout << "A | F\n";
        cout << "------\n";
        for (int a = 0; a <= 1; a++)
            cout << a << " | " << !a << "\n";
    }

    void explain() override {
        cout << "NOT inverts the input.\n";
    }
};

// NAND
class NANDGate : public LogicGate {
public:
    NANDGate() : LogicGate("NAND Gate", "F = (A . B)'") {}

    bool evaluate(bool a, bool b) override {
        return !(a && b);
    }

    void displaySymbol() override {
        cout << R"(

        A --|‾‾‾‾‾‾‾‾\
                    )--o--- (A.B)'
        B --|________/

        )";
    }

    void truthTable() override {
        cout << "\nNAND TRUTH TABLE\n";
        cout << "A | B | F\n";
        cout << "----------\n";
        for (int a = 0; a <= 1; a++)
            for (int b = 0; b <= 1; b++)
                cout << a << " | " << b << " | " << !(a && b) << "\n";
    }

    void explain() override {
        cout << "NAND is NOT of AND.\n";
    }
};

// NOR
class NORGate : public LogicGate {
public:
    NORGate() : LogicGate("NOR Gate", "F = (A + B)'") {}

    bool evaluate(bool a, bool b) override {
        return !(a || b);
    }

    void displaySymbol() override {
        cout << R"(

        A --|‾‾‾‾‾‾‾‾‾\
                    >--o--- (A+B)'
        B --|__________/

        )";
    }

    void truthTable() override {
        cout << "\nNOR TRUTH TABLE\n";
        cout << "A | B | F\n";
        cout << "----------\n";
        for (int a = 0; a <= 1; a++)
            for (int b = 0; b <= 1; b++)
                cout << a << " | " << b << " | " << !(a || b) << "\n";
    }

    void explain() override {
        cout << "NOR is NOT of OR.\n";
    }
};

// XOR
class XORGate : public LogicGate {
public:
    XORGate() : LogicGate("XOR Gate", "F = A'B + AB'") {}

    bool evaluate(bool a, bool b) override {
        return a ^ b;
    }

    void displaySymbol() override {
        cout << R"(

        A --)|‾‾‾‾‾‾‾‾‾\
            )           >--- A'B + AB'
        B --)|__________/

        )";
    }

    void truthTable() override {
        cout << "\nXOR TRUTH TABLE\n";
        cout << "A | B | F\n";
        cout << "----------\n";
        for (int a = 0; a <= 1; a++)
            for (int b = 0; b <= 1; b++)
                cout << a << " | " << b << " | " << (a ^ b) << "\n";
    }

    void explain() override {
        cout << "XOR outputs 1 when inputs are DIFFERENT.\n";
    }
};

// XNOR
class XNORGate : public LogicGate {
public:
    XNORGate() : LogicGate("XNOR Gate", "F = AB + A'B'") {}

    bool evaluate(bool a, bool b) override {
        return !(a ^ b);
    }

    void displaySymbol() override {
        cout << R"(

        A --)|‾‾‾‾‾‾‾‾‾\
            )           >--o--- Y
        B --)|__________/

        )";
    }

    void truthTable() override {
        cout << "\nXNOR TRUTH TABLE\n";
        cout << "A | B | F\n";
        cout << "----------\n";
        for (int a = 0; a <= 1; a++)
            for (int b = 0; b <= 1; b++)
                cout << a << " | " << b << " | " << !(a ^ b) << "\n";
    }

    void explain() override {
        cout << "XNOR outputs 1 when inputs are THE SAME.\n";
    }
};

// MENU
void showMenu(string user) {
    cout << "\n====================================\n";
    cout << " LOGIC GATE SIMULATOR\n";
    cout << " User: " << user << "\n";
    cout << "====================================\n";
    cout << "1. DEFINITION MODE\n";
    cout << "2. COMPUTATION MODE\n";
    cout << "3. Exit\n";
    cout << "====================================\n";
    cout << "Enter choice: ";
}

// MAIN
int main() {

    string userName;
    cout << "Enter your name: ";
    getline(cin, userName);

    cout << "\nWelcome, " << userName << "!\n";

    int mode;

    do {
        showMenu(userName);

        cin >> mode;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input!\n";
            continue;
        }

        if (mode < 1 || mode > 3) {
            cout << "Invalid Choice!\n";
            continue;
        }

        if (mode == 3) {
            cout << "\nGoodbye!\n";
            break;
        }

        int gateChoice;

        cout << "\nSelect Gate:\n";
        cout << "1 AND\n2 OR\n3 NOT\n4 NAND\n5 NOR\n6 XOR\n7 XNOR\n8 Main Menu\n";
        cout << "Choice: ";
        cin >> gateChoice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid gate input!\n";
            continue;
        }

        if (gateChoice == 8) {
            continue;
        }

        if (gateChoice < 1 || gateChoice > 7) {
            cout << "Invalid gate!\n";
            continue;
        }

        LogicGate* gate = nullptr;

        switch (gateChoice) {
            case 1: gate = new ANDGate(); break;
            case 2: gate = new ORGate(); break;
            case 3: gate = new NOTGate(); break;
            case 4: gate = new NANDGate(); break;
            case 5: gate = new NORGate(); break;
            case 6: gate = new XORGate(); break;
            case 7: gate = new XNORGate(); break;
        }

        if (mode == 1) {

            cout << "\n------------------------------------\n";
            gate->showInfo();
            gate->displaySymbol();
            gate->explain();
            gate->truthTable();
            cout << "------------------------------------\n";

        } else if (mode == 2) {

            int a, b;

            cout << "Enter A (0 or 1): ";
            cin >> a;

            if (cin.fail() || (a != 0 && a != 1)) {
                cout << "Invalid input!\n";
                delete gate;
                continue;
            }

            cout << "Enter B (0 or 1): ";
            cin >> b;

            if (cin.fail() || (b != 0 && b != 1)) {
                cout << "Invalid input!\n";
                delete gate;
                continue;
            }

            cout << "\n------------------------------------\n";
            gate->showInfo();
            gate->displaySymbol();
            cout << "A = " << a << " | B = " << b << "\n";
            cout << "OUTPUT = " << gate->evaluate(a, b) << "\n";
            cout << "------------------------------------\n";
        }

        delete gate;

    } while (true);

    return 0;
}