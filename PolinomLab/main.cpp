#include <iostream>
#include <vector>
#include <conio.h>  // ��� _getch() � Windows
#include <windows.h>
#include <sstream> // ��� stringstream
#include "Monom.h"  // ���������, ��� ���� � ����� Monom.h ����������
#include "Polinom.h" // ���������, ��� ���� � ����� Polinom.h ����������

class Calculator
{
    void GotoXY(short x, short y)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x, y });
    }
public:
    std::vector<Polinom> polynomials;

    void RunCalculator()
    {
        system("cls");

        std::string Menu[] = { "NEW\n", "ADD\n", "SUB\n", "MULT\n" };

        int active_menu = 0;
        int touch_index = 0;

        char ch;
        while (true)
        {
            int x = 10, y = 0;
            GotoXY(x, y);
            for (int i = 0; i < size(Menu); i++)
            {
                if (i == active_menu)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                else
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                GotoXY(x, y++);
            }

            ch = _getch();
            switch (ch) {
            case 27: // Esc
                exit(0);
            case 72: // ������� �����
                if (active_menu > 0) {
                    active_menu--; // ��������� ������, ���� �� ������ 0
                }
                break; // ��������� break
            case 80: // ������� ����
                if (active_menu < size(Menu) - 1) {
                    active_menu++; // ����������� ������, ���� �� ������ ������� ���� - 1
                }
                break;
            }

            if (ch == 13 && active_menu == 0)
            {
                touch_index++;
                GotoXY(15, 0);
                std::cout << " ----> ������� ����� � ������� coeff x y z: ";
                double coeff_m;
                int x_m;
                int y_m;
                int z_m;
                std::cin >> coeff_m >> x_m >> y_m >> z_m;
                if (coeff_m == 0)
                {

                    std::cout << Menu[1] << std::endl;
                }
            }
        }
    }

    void DisplayPolynomials()
    {
        std::cout << "����������� ��������:" << std::endl;
        for (size_t i = 0; i < polynomials.size(); ++i)
        {
            std::cout << i + 1 << ") " << polynomials[i] << std::endl;
        }
    }
    /*
    std::vector<Polinom> polynomials;

    void RunCalculator()
    {
        while (true)
        {
            system("cls"); // ������� ������� ����� ������ �������
            DisplayPolynomials();
            std::cout << "\n������� ������� (add, sub, mul, new, exit): ";
            std::string command;
            std::cin >> command;

            if (command == "exit")
            {
                break;
            }
            else if (command == "new")
            {
                Polinom newPolinom = CreatePolynomialFromInput();
                polynomials.push_back(newPolinom);
            }
            else if (command == "add" || command == "sub" || command == "mul")
            {
                PerformOperation(command);
            }
            else
            {
                std::cout << "�������� �������." << std::endl;
            }

            // �������� ������� ������� ����� ��������� ���������
            std::cout << "������� ����� ������� ��� �����������...";
            _getch(); // ��� ����������� ������������ ��� ������ ��, ���� �� ����������� Windows
        }
    }

private:
    void DisplayPolynomials()
    {
        std::cout << "����������� ��������:" << std::endl;
        for (size_t i = 0; i < polynomials.size(); ++i)
        {
            std::cout << i + 1 << ") " << polynomials[i] << std::endl;
        }
    }

    Polinom CreatePolynomialFromInput()
    {
        Polinom polinom;
        std::string input;
        std::cout << "������� ����� (coeff x y z, ��������: 2 1 0 2) ��� 'done' ��� ����������: " << std::endl;
        std::cin.ignore(); // �������� ����� ����� ����������� �����

        while (true)
        {
            std::getline(std::cin, input);

            if (input == "done")
            {
                break;
            }

            std::stringstream ss(input);
            double coeff;
            int x, y, z;

            if (ss >> coeff >> x >> y >> z)
            {
                Monom monom(coeff, x, y, z);
                polinom += monom;
            }
            else
            {
                std::cout << "������������ ���� ������. ���������� ��� ���." << std::endl;
            }
        }

        return polinom;
    }

    void PerformOperation(const std::string& operation)
    {
        if (polynomials.size() < 2)
        {
            std::cout << "������������ ��������� ��� ���������� ��������. ����� ��� ������� 2." << std::endl;
            return;
        }

        int index1, index2;
        std::cout << "������� ������� ��������� ��� �������� (��������, 1 2): ";
        std::cin >> index1 >> index2;

        if (index1 <= 0 || index1 > polynomials.size() || index2 <= 0 || index2 > polynomials.size())
        {
            std::cout << "�������� ������� ���������." << std::endl;
            return;
        }

        Polinom& p1 = polynomials[index1 - 1];
        Polinom& p2 = polynomials[index2 - 1];
        Polinom result;

        if (operation == "add")
        {
            result = p1 + p2;
        }
        else if (operation == "sub")
        {
            result = p1 - p2;
        }
        else if (operation == "mul")
        {
            result = p1 * p2;
        }

        std::cout << "���������: " << result << std::endl;

        // ���������� ��������� ��������� ��� ���
        std::cout << "��������� ���������? (y/n): ";
        char choice;
        std::cin >> choice;

        if (choice == 'y')
        {
            polynomials.push_back(result);
        }
    }

    friend std::ostream& operator<<(std::ostream& os, Calculator& calc)
    {
        for (int i = 0; i < calc.polynomials.size(); i++)
        {
            os << i + 1 << ") " << calc.polynomials[i] << std::endl;
        }
        return os;
    }*/
};

void GotoXY(short x, short y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x, y });
}

int main()
{
    setlocale(LC_ALL, "ru_RU");
    Calculator c;
    c.RunCalculator();
}