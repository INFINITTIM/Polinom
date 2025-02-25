#include "Monom.h"

Monom::Monom() : coeff(0.0), x(0), y(0), z(0)
{
}

Monom::Monom(double _coeff, int _x, int _y, int _z) : coeff(_coeff), x(_x), y(_y), z(_z)
{
}

bool Monom::operator<=(const Monom& m) const
{
	if (x < m.x)
		return true;
	else if (x == m.x)
	{
		if (y < m.y)
			return true;
		else if (y == m.y)
		{
			if (z <= m.z)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

bool Monom::operator<(const Monom& m) const
{
	if (x < m.x)
		return true;
	else if (x == m.x)
	{
		if (y < m.y)
			return true;
		else if (y == m.y)
		{
			if (z < m.z)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

bool Monom::operator>=(const Monom& m) const
{
	if (x < m.x)
		return false;
	else if (x == m.x)
	{
		if (y < m.y)
			return false;
		else if (y == m.y)
		{
			if (z < m.z)
				return false;
			else
				return true;
		}
		else
			return true;
	}
	else
		return true;
}

bool Monom::operator>(const Monom& m) const
{
	if (x < m.x)
		return false;
	else if (x == m.x)
	{
		if (y < m.y)
			return false;
		else if (y == m.y)
		{
			if (z <= m.z)
				return false;
			else
				return true;
		}
		else
			return true;
	}
	else
		return true;
}

bool Monom::operator==(const Monom& m) const
{
	if (x == m.x)
	{
		if (y == m.y)
		{
			if (z == m.z)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool Monom::operator!=(const Monom& m) const
{
	return (!(*this == m));
}