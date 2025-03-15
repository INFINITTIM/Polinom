#include <iostream>
#include <vector>
#include <conio.h> // Для _getch() в Windows (или используйте альтернативы для других ОС)
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
            if (_kbhit()) // Проверяем, была ли нажата клавиша
                if (_getch() == 27) // Если нажата, проверяем, ESC ли это
                {
                    std::cout << "Выход из программы." << std::endl;
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