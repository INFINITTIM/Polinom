#pragma once

#include <iostream>
#include <vector>
#include <conio.h>  
#include <windows.h>
#include <sstream> 
#include "Monom.h" 
#include "Polinom.h"

class Calculator
{
    void GotoXY(short x, short y)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x, y });
    }
public:
    std::vector<Polinom> polynomials;

    void RunCalculator();

    void DisplayPolynomials();

    void ResetDisplay(std::string Menu[], int active_menu);
};