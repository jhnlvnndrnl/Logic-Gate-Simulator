#ifndef UI_H
#define UI_H

#include <string>

using namespace std;

void printLine(char symbol);
void printHeader(string title);
void printSection(string title);
void showMenu(string user);
void showGateMenu();
int readNumber(string errorMessage);
void clearInput();

#endif