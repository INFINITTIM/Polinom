#pragma once

#include "Polinom.h"

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
		AddMonom(m[i]);
	}
}

Polinom::~Polinom()
{
}

Polinom& Polinom::operator=(const Polinom& p)
{
	if (*this == p) 
		return *this;
	else
	{
		List<Monom>::operator=(p);
		return *this;
	}
}


void Polinom::operator+=(double t)
{
	Monom a(t, 0, 0, 0);
	AddMonom(a);
}

Polinom Polinom::operator+(double t)
{
	Monom a(t, 0, 0, 0);
	AddMonom(a);
	return *this;
}

void Polinom::AddConst(double t)
{
	Monom a(t, 0, 0, 0);
	AddMonom(a);
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

Polinom Polinom::operator+(Monom m)
{
	Polinom res(*this);

	if (pFirst == nullptr)
		res.InsLast(m);
	else
	{
		if (m > res.pFirst->val)
			res.InsFirst(m);
		else if (m < res.pLast->val)
			res.InsLast(m);
		else
		{
			for (res.Reset(); !res.IsEnd(); res.GoNext())
			{
				if (m > res.pCurr->val)
				{
					res.InsCurr(m);
					return res;
				}
				if (m == res.pCurr->val)
				{
					double c = res.pCurr->val.coeff + m.coeff;
					if (c != 0.0)
						res.pCurr->val.coeff = c;
					else
						res.DelCurr();
					return res;
				}
			}
		}
	}
	return res;
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

void Polinom::operator+=(Polinom p)
{
	if (p.size == 0)
		return;
	else
	{
		Polinom::iterator i(p.begin());

		for (; i != p.end(); ++i)
		{
			AddMonom(*i);
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

Polinom Polinom::operator+(Polinom p)
{
	if (p.size == 0)
		return *this;
	else
	{
		Polinom::iterator i(p.begin());

		for (; i != p.end(); ++i)
		{
			AddMonom(*i);
		}
		return *this;
	}
}

void Polinom::AddPolinom(Polinom p)
{
	if (p.size == 0)
		return;
	else
	{
		Polinom::iterator i(p.begin());

		for (; i != p.end(); ++i)
		{
			AddMonom(*i);
		}
	}
}

void Polinom::operator*=(double t)
{
	if (t == 0.0)
	{
		Clear();
	}
	else
	{
		Polinom::iterator i(this->begin());
		for (; i != this->end(); ++i)
		{
			(*i).coeff *= t;
		}
	}
}

Polinom Polinom::operator*(double t)
{
	if (t == 0.0)
	{
		Clear();
	}
	else
	{
		Polinom::iterator i(this->begin());
		for (; i != this->end(); ++i)
		{
			(*i).coeff *= t;
		}
	}
	return *this;
}

void Polinom::MultConst(double t)
{
	if (t == 0.0)
	{
		Clear();
	}
	else
	{
		Polinom::iterator i(this->begin());
		for (; i != this->end(); ++i)
		{
			(*i).coeff *= t;
		}
	}
}

void Polinom::operator*=(Monom m)
{
	if (m.coeff == 0.0)
	{
		Clear();
	}
	else
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
}

Polinom Polinom::operator*(Monom m)
{
	if (m.coeff == 0.0)
	{
		Clear();
	}
	else
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
	return *this;
}

void Polinom::MultMonom(Monom m)
{
	if (m.coeff == 0.0)
	{
		Clear();
	}
	else
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

Polinom Polinom::operator*(Polinom p)
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

	return d;
}

Polinom Polinom::operator-(double t)
{
	t *= (-1.0);
	Monom a(t, 0, 0, 0);
	AddMonom(a);
	return *this;
}

Polinom Polinom::operator-(Monom m)
{
	m.coeff *= (-1);
	AddMonom(m);
	return *this;
}

Polinom Polinom::operator-(Polinom p)
{
	Polinom::iterator i(p.begin());

	for (; i != p.end(); ++i)
	{
		(*i).coeff *= (-1);
		AddMonom(*i);
	}
	return *this;
}

void Polinom::operator-=(double t)
{
	t *= (-1.0);
	Monom a(t, 0, 0, 0);
	AddMonom(a);
}

void Polinom::operator-=(Monom m)
{
	m.coeff *= (-1);
	AddMonom(m);
}

void Polinom::operator-=(Polinom p)
{
	Polinom::iterator i(p.begin());

	for (; i != p.end(); ++i)
	{
		(*i).coeff *= (-1);
		AddMonom(*i);
	}
}

void Polinom::SubConst(double t)
{
	t *= (-1.0);
	Monom a(t, 0, 0, 0);
	AddMonom(a);
}

void Polinom::SubMonom(Monom m)
{
	m.coeff *= (-1);
	AddMonom(m);
}

void Polinom::SubPolinom(Polinom p)
{
	Polinom::iterator i(p.begin());

	for (; i != p.end(); ++i)
	{
		(*i).coeff *= (-1);
		AddMonom(*i);
	}
}

