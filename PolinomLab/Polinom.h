#pragma once

#include <iostream>

#include "Node.h"
#include "List.h"
#include "Monom.h"

using namespace std;

class Polinom : public List<Monom>
{
public:

	Polinom();
	Polinom(const Polinom& p);
	Polinom(Monom* m, int size);
	~Polinom();

	Polinom& operator=(const Polinom& p);

	Polinom operator+(double t);
	Polinom operator+(Monom m);
	Polinom operator+(Polinom p);

	Polinom operator-(double t);
	Polinom operator-(Monom m);
	Polinom operator-(Polinom p);

	Polinom operator*(double t);
	Polinom operator*(Monom m);
	Polinom operator*(Polinom p);

	void operator+=(double t);
	void operator+=(Monom m);
	void operator+=(Polinom p);

	void operator-=(double t);
	void operator-=(Monom m);
	void operator-=(Polinom p);

	void operator*=(double t);
	void operator*=(Monom m);
	void operator*=(Polinom p);

	void AddConst(double t);
	void AddMonom(Monom m);
	void AddPolinom(Polinom p);

	void SubConst(double t);
	void SubMonom(Monom m);
	void SubPolinom(Polinom p);

	void MultConst(double t);
	void MultMonom(Monom m);
	void MultPolinom(Polinom p);

	friend ostream& operator<<(ostream& out,Polinom& p)
	{
		if (p.size == 0)
			out << "";
		else
		{
			Polinom::iterator i(p.begin());
			for (; i != p.end(); ++i)
			{
				if (i == p.begin())
					out << *i;
				else
				{
					if ((*i).coeff < 0)
						out << " ";
					if ((*i).coeff > 0)
						out << " + ";
					out << *i;
				}
			}
			return out;
		}
	}
};