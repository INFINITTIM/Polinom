#include <iostream>
#include <vector>
#include <conio.h> // ��� _getch() � Windows (��� ����������� ������������ ��� ������ ��)
#include "Monom.h"
#include "Polinom.h"

class Calculator
{
public:
    std::vector<Polinom> p;

    void RunCalculator()
    {
        while (true)
        {
            if (_kbhit()) // ���������, ���� �� ������ �������
                if (_getch() == 27) // ���� ������, ���������, ESC �� ���
                {
                    std::cout << "����� �� ���������." << std::endl;
                    break;
                }
                else
                {

                }
        }
    }

    friend std::ostream& operator<<(std::ostream& os, Calculator& calc)
    {
        for (int i = 0; i < calc.p.size(); i++)
        {
            os << i + 1 << ") " << calc.p[i] << std::endl;
        }
        return os;
    }
};

int main() {
    setlocale(LC_ALL, "ru_RU");

    Calculator c;
    //std::cout << c;
    c.RunCalculator();
    return 0;
}