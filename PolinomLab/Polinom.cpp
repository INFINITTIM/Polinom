#include "Polinom.h"

#pragma once

Polinom::Polinom()
{
}

Polinom::Polinom(const Polinom& p) : List<Monom>(p)
{
}

Polinom::Polinom(Monom* m, int size)
{
	for (int i = 0; i < size; i++)
	{
		InsLast(m[i]);
	}
}

Polinom::~Polinom()
{
}

void Polinom::operator+=(Monom m)
{
	if (pFirst == nullptr)
		InsLast(m);
	else
	{
		if (m > pFirst->val)
			InsFirst(m);
		else if (m < pLast->val)
			InsLast(m);
		else
		{
			for (Reset(); !IsEnd(); GoNext())
			{
				if (m > pCurr->val)
				{
					InsCurr(m);
					return;
				}
				if (m == pCurr->val)
				{
					double c = pCurr->val.coeff + m.coeff;
					if (c != 0.0)
						pCurr->val.coeff = c;
					else
						DelCurr();
					return;
				}
			}
		}
	}
}


void Polinom::AddMonom(Monom m)
{
	if (pFirst == nullptr)
		InsLast(m);
	else
	{
		if (m > pFirst->val)
			InsFirst(m);
		else if (m < pLast->val)
			InsLast(m);
		else
		{
			for (Reset(); !IsEnd(); GoNext())
			{
				if (m > pCurr->val)
				{
					InsCurr(m);
					return;
				}
				if (m == pCurr->val)
				{
					double c = pCurr->val.coeff + m.coeff;
					if (c != 0.0)
						pCurr->val.coeff = c;
					else
						DelCurr();
					return;
				}
			}
		}
	}
}

//написать более быстрый алгоритм сложения похожий на слияние двух упорядоченных массивов 
// в сортировке слиянием двигая pCurr у обоих 
// 1) p.pCurr->val = res.pCurr->val;
// 2) случай когда нужно добавить перед звеном pCurr; у res pCurr не подвинется pCurr;
// 3) случай когда у нижнего степень меньше то просто двигаем верхний pCurr то есть у res;

// написать более эффективное добавление полинома

// * задания
// умножение на моном 
// 
//Polinom Polinom::AddPolinom2(Polinom p)
//{
//	Polinom res(*this);
//	
//}

void Polinom::AddPolinom(Polinom p)
{
	Polinom::iterator i(p.begin());

	for (; i != p.end(); ++i)
	{
		AddMonom(*i);
	}
}

void Polinom::AddConst(double t)
{
	Monom a(t, 0, 0, 0);
	AddMonom(a);
}

void Polinom::operator*=(double t)
{
	if (t == 0.0)
	{
		//Clear();
	}
	Polinom::iterator i(this->begin());
	for (; i != this->end(); ++i)
	{
		(*i).coeff *= t;
	}
}
void Polinom::MultConst(double t)
{
	Polinom::iterator i(this->begin());
	for (; i != this->end(); ++i)
	{
		(*i).coeff *= t;
	}
}

void Polinom::operator*=(Monom m)
{
	Polinom::iterator i(this->begin());
	for (; i != this->end(); ++i)
	{
		(*i).coeff *= m.coeff;
		(*i).x += m.x;
		(*i).y += m.y;
		(*i).z += m.z;
	}
}
void Polinom::MultMonom(Monom m)
{
	Polinom::iterator i(this->begin());
	for (; i != this->end(); ++i)
	{
		(*i).coeff *= m.coeff;
		(*i).x += m.x;
		(*i).y += m.y;
		(*i).z += m.z;
	}
}
void Polinom::MultPolinom(Polinom p)
{
	Polinom d;
	Polinom::iterator i(p.begin());
	Polinom::iterator j(this->begin());

	for (; i != p.end(); ++i)
	{
		j = this->begin();
		for (; j != this->end(); ++j)
		{
			double coefff = (*j).coeff * (*i).coeff;
			int xx = (*i).x + (*j).x;
			int yy = (*i).y + (*j).y;
			int zz = (*i).z + (*j).z;

			d.AddMonom({ coefff, xx, yy, zz });
		}
	}

	while (pFirst != nullptr) {
		DelFirst();
	}

	Polinom::iterator m(d.begin());

	for (; m != d.end(); ++m)
	{
		this->AddMonom(*m);
	}
}

Polinom Polinom::operator+(Polinom p)
{
	Polinom res(*this);
	for (p.Reset(); !p.IsEnd(); p.GoNext())
	{
		Monom tmp = p.getCurr();
		res.AddMonom(tmp);
	}
	return res;
}


