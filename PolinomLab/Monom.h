#pragma once

#include <iostream>

using namespace std;

struct Monom
{
	double coeff;
	int x, y, z;

	bool operator<=(const Monom& m) const;
	bool operator<(const Monom& m) const;
	bool operator>(const Monom& m) const;
	bool operator>=(const Monom& m) const;
	bool operator==(const Monom& m) const;
	bool operator!=(const Monom& m) const;

	Monom();
	Monom(double _coeff, int _x, int _y, int _z);

	friend ostream& operator<<(ostream& out, const Monom& m)
	{
		if (m.coeff < 0)
			out << "- " << m.coeff * (-1.0);
		if (m.coeff > 0)
			out << m.coeff;
		if (m.x != 0)
			out << "x^" << m.x;
		if (m.y != 0)
			out << "y^" << m.y;
		if (m.z != 0)
			out << "z^" << m.z;
		return out;
	}

};

