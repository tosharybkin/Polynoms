#pragma once
#include <iostream>
#include <string>
using namespace std;

class Monom
{
private:
	int coef;
	int power;

public:
	Monom(int _coef, int x, int y, int z);
	Monom(int _coef = 0, int _power = 0);

	int GetCoef() const;
	int GetX() const;
	int GetY() const;
	int GetZ() const;
	int GetPower() const;

	void SetCoeff(int _coef);
	void SetPower(int x, int y, int z);

	Monom operator* (const Monom& m);
	string toStr();

	friend ostream& operator << (ostream& ostr, const Monom& m)
	{
		if ((m.GetCoef() == 0) || (m.GetPower() == 0))
			cout << m.GetCoef();
		else
			ostr << m.GetCoef()
			<< "x^" << m.GetX()
			<< "y^" << m.GetY()
			<< "z^" << m.GetZ();

		return ostr;
	}
};

