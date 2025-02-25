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

	Polinom operator+(double t);
	void operator+=(double t);
	void AddConst(double t);

	Polinom operator+(Monom);
	void operator+=(Monom m);
	void AddMonom(Monom m);

	Polinom operator+(Polinom p);
	void operator+=(Polinom p);
	Polinom AddPolinom2(Polinom p);
	void AddPolinom(Polinom p);

	Polinom operator*(double t);
	void operator*=(double t);
	void MultConst(double t);

	Polinom operator*(Monom m);
	void operator*=(Monom m);
	void MultMonom(Monom m);

	Polinom operator*(Polinom p);
	void operator*=(Polinom p);
	void MultPolinom(Polinom p);

	//void DivConst(double t);
	//void DivMonom(Monom m);
	//void DivPolinom(Polinom p);

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