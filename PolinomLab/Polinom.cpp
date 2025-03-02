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

bool Polinom::operator==(const Polinom& p) const{
	if (size != p.size)
		return false;
	if (size == 0 && p.size == 0)
		return true;
	Node<Monom>* node = pFirst;
	Node<Monom>* pnode = p.pFirst;
	while (node != nullptr)
	{
		if (node->val.coeff != pnode->val.coeff ||
			node->val.x != pnode->val.x ||
			node->val.y != pnode->val.y ||
			node->val.z != pnode->val.z)
			return false;
		node = node->pNext;
		pnode = pnode->pNext;
	}
	return true;
}

bool Polinom::operator!=(const Polinom& p) const {
	return (!(*this == p));
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

//�������� ����� ������� �������� �������� ������� �� ������� ���� ������������� �������� 
// � ���������� �������� ������ pCurr � ����� 
// 1) p.pCurr->val = res.pCurr->val;
// 2) ������ ����� ����� �������� ����� ������ pCurr; � res pCurr �� ���������� pCurr;
// 3) ������ ����� � ������� ������� ������ �� ������ ������� ������� pCurr �� ���� � res;

// �������� ����� ����������� ���������� ��������

// * �������
// ��������� �� ����� 
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
	if (size == 0)
		return;
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
	if (size == 0)
		return *this;
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
	if (size == 0)
		return;
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
	if (size == 0)
		return;
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
	if (size == 0)
		return *this;
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
	if (size == 0)
		return;
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
	if (size == 0)
		return;
	if (p.size == 0)
	{
		Clear();
		return;
	}
	Polinom res;
	for (p.Reset(); !p.IsEnd(); p.GoNext())
	{
		Polinom tmp(*this);
		Monom m = p.getCurr();
		Polinom pp = tmp * m;
		res += pp;
	}
	Clear();
	*this += res;
}

void Polinom::operator*=(Polinom p)
{
	if (size == 0 || p.size == 0)
		return;
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
	if (size == 0 || p.size == 0)
		return *this;
	Polinom res;
	Polinom tmp(*this);
	for (p.Reset(); !p.IsEnd(); p.GoNext())
	{
		Monom m = p.getCurr();
		res += tmp * m;
	}
	return res;
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

