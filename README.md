# Logic Gate Simulator

A simple C++ console program that demonstrates the seven basic logic gates: AND, OR, NOT, NAND, NOR, XOR, and XNOR. The program can show each gate's definition, ASCII symbol, truth table, and compute an output from user inputs.

## OOP Concepts Used

- **Encapsulation** - private data with setters and getters
- **Inheritance** - each gate class inherits from `LogicGate`
- **Polymorphism** - a `LogicGate*` can point to any gate object
- **Abstraction** - `LogicGate` uses pure virtual functions

## Compile and Run

```bash
g++ -std=c++11 *.cpp -o main
./main
```

## Reference

Logic gate definitions and behavior were based on:  
[GeeksforGeeks - Logic Gates](https://www.geeksforgeeks.org/digital-logic/logic-gates/)