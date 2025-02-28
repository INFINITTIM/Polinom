#include <iostream>

#include "Monom.h"
#include "Polinom.h"
#include "iterator.h"
#include "List.h"


using namespace std;

int main()
{
    /*
    Monom a(4.0, 2, 0, 4);
    Monom b(-3.0, 1, 2, 5);
    Monom ab[] = {a,b};
    Polinom p(ab, 2);
    cout << p << endl;
    Polinom p2(p);
    cout << p2 << endl;
    Polinom p3;
    p3 = p;
    cout << p3 << endl;
    Polinom p4;
    p4 = p3 + a;
    cout << p4 << endl;
    */
    
    Monom a(4.0, 2, 3, 4);
    Monom b(-3.0, 1, 2, 5);
    Monom v(-3.0, 5, 2, 5);
    Monom g(-3.0, 2, 2, 5);
    Monom f(3.0, 3, 2, 5);
    Polinom ab;
    Polinom abb;

    cout << a << " " << g << endl;

    ab.AddMonom(a);
    ab.AddMonom(b);
    ab.AddMonom(v);
    ab.AddMonom(g);
    ab.AddMonom(f);
    ab.AddMonom({ -3.0, 3, 4, 3 });

    ab.AddMonom({ 3.0, 3, 4, 3 });

    cout << endl << ab << endl;

    Polinom::iterator i(ab.begin());

    for (; i != ab.end(); ++i)
    {
        if (i == ab.begin())
            cout << *i;
        else
        {
            if ((*i).coeff < 0)
                cout << " ";
            if ((*i).coeff > 0)
                cout << " + ";
            cout << *i;
        }
    }
    cout << endl;

    cout << ab << endl;

    abb += v;
    abb += a;
    abb += g;

    abb += f;

    abb += b;

    abb += { -3.0, 3, 4, 3 };

    abb += { 3.0, 3, 4, 3 };

    cout << abb << endl;

    Polinom abbbb;

    cout << abbbb << endl;

    Polinom abbb(ab);

    ab.AddMonom({ 12.0, 2, 9, 3 });

    cout << abbb << endl;

    abbb.AddPolinom(ab);

    cout << abbb << endl;

    abbbb += { 4.0, 0, 8, 9};

    abbbb.AddPolinom(abbb);

    cout << abbbb << endl;

    abbbb.AddConst(5.3);

    cout << abbbb << endl;

    abbbb.MultConst(5.0);

    cout << abbbb << endl;

    abbbb.MultMonom({ -3.0, 4, 2 ,1 });

    cout << abbbb << endl;

    Polinom d;
    Polinom d1;

    d += a;
    d += b;
    d1 += v;
    d1 += g;

    cout << d << endl;

    cout << d1 << endl;

    Polinom d4;

    Polinom d5(d);

    d.MultPolinom(d1);

    cout << d << endl;

    Polinom d2;
    
    d2 = d + f;

    cout << d2 << endl;

    Polinom d3;

    d3 = d2 + 4.9;

    cout << d3 << endl;


    cout << d5 << endl << d1 << endl;
    d4 = d5 * d1;

    cout << d4 << endl;
}
