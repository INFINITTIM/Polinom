#include "PCalculator.h"

void Calculator::DisplayPolynomials()
{
    std::cout << "—охраненные полиномы:" << std::endl;
    for (size_t i = 0; i < polynomials.size(); ++i)
    {
        std::cout << i + 1 << ") " << polynomials[i] << std::endl;
    }
}

void Calculator::RunCalculator()
{
    system("cls");

    std::string Menu[] = { "NEW\n", "ADD\n", "SUB\n", "MULT\n" };

    int active_menu = 0;

    char ch;
    while (true)
    {
        ResetDisplay(Menu, active_menu);

        ch = _getch();
        switch (ch) {
        case 27:
            exit(0);
        case 72:
            if (active_menu > 0) {
                active_menu--;
            }
            break;
        case 80:
            if (active_menu < size(Menu) - 1) {
                active_menu++;
            }
            break;
        }

        if (ch == 13 && active_menu == 0) {
            GotoXY(15, 0);
            std::cout << " ----> ¬ведите моном в формате coeff x y z: ";
            double coeff_m;
            int x_m;
            int y_m;
            int z_m;
            std::cin >> coeff_m >> x_m >> y_m >> z_m;

            if (coeff_m == 0 && ch == 13)
            {
                system("cls");
                ResetDisplay(Menu, active_menu);
            }
            else
            {

                Monom m(coeff_m, x_m, y_m, z_m);
                Polinom p;
                p += m;
                polynomials.push_back(p);
                system("cls");
                ResetDisplay(Menu, active_menu);
            }
        }
        if (active_menu == 1 && ch == 13)
        {
            GotoXY(15, 1);
            std::cout << " ----> ¬ведите индексы двух полиномов дл€ их сложени€: ";
            int p1;
            int p2;
            std::cin >> p1 >> p2;
            Polinom p;
            p = polynomials[p1 - 1] + polynomials[p2 - 1];
            polynomials.push_back(p);
            system("cls");
            ResetDisplay(Menu, active_menu);
        }
        if (active_menu == 2 && ch == 13)
        {
            GotoXY(15, 2);
            std::cout << " ----> ¬ведите индексы двух полиномов дл€ их вычитани€: ";
            int p1;
            int p2;
            std::cin >> p1 >> p2;
            Polinom p;
            p = polynomials[p1 - 1] - polynomials[p2 - 1];
            polynomials.push_back(p);
            system("cls");
            ResetDisplay(Menu, active_menu);
        }
        if (active_menu == 3 && ch == 13)
        {
            GotoXY(15, 3);
            std::cout << " ----> ¬ведите индексы двух полиномов дл€ их умножени€: ";
            int p1;
            int p2;
            std::cin >> p1 >> p2;
            Polinom p;
            p = polynomials[p1 - 1] * polynomials[p2 - 1];
            polynomials.push_back(p);
            system("cls");
            ResetDisplay(Menu, active_menu);
        }
    }
}

void Calculator::ResetDisplay(std::string Menu[], int active_menu)
{
    int x = 10, y = 0;
    GotoXY(x, y);
    for (int i = 0; i < 4; i++)
    {
        if (i == active_menu)
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        else
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        GotoXY(x, y++);
        std::cout << Menu[i] << std::endl;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    DisplayPolynomials();
}