#include "monom.h"

using namespace std;

Monom::Monom(int _coef, int x, int y, int z)
{
	coef = _coef;
	power = x * 100 + y * 10 + z;
}

Monom::Monom(int _coef, int _power)
	: coef(_coef), power(_power) {}

int Monom::GetCoef() const
{
	return coef;
}

int Monom::GetX() const
{
	return (power / 100);
}

int Monom::GetY() const
{
	return ((power % 100) / 10);
}

int Monom::GetZ() const
{
	return (power % 10);
}

string Monom::toStr()
{
	string res;

	if ((this->GetCoef() == 0) || (this->GetPower() == 0))
		res += to_string(this->GetCoef());
	else
		res += to_string(this->GetCoef())
		+ "x^" + to_string(this->GetX())
		+ "y^" + to_string(this->GetY())
		+ "z^" + to_string(this->GetZ());

	return res;
}

int Monom::GetPower() const
{
	return power;
}

void Monom::SetCoeff(int _coef)
{
	coef = _coef;
}

Monom Monom::operator*(const Monom& m)
{
	Monom temp;
	temp.coef = this->coef * m.coef;

	int x = this->GetX() + m.GetX();
	int y = this->GetY() + m.GetY();
	int z = this->GetZ() + m.GetZ();

	temp.power = x * 100 + y * 10 + z;

	return temp;
}

void Monom::SetPower(int x, int y, int z)
{
	power = x * 100 + y * 10 + z;
}
