#pragma once
#include "list.h"
#include <string>
#include <sstream>
#include <cstdlib>
#include<iostream>
using namespace std;

class Polynom
{
private:
	List list;
public:
	Polynom();
	void AddMonom(const Monom& m);

	Polynom operator + (Polynom& p);
	Polynom operator * (double a);
	Polynom operator - (Polynom& p);

	string Polynom::toStr();

	friend ostream& operator << (ostream& ostr, Polynom& p)
	{
		Node* current = p.list.GetHead()->next;
		cout << current->m;
		current = current->next;

		while (current->m.GetPower() != -1)
		{
			if (current->m.GetCoef() > 0)
				cout << " + " << current->m;
			else
				cout << " " << current->m;
			current = current->next;
		}

		cout << endl;

		return ostr;
	}

	friend istream& operator >> (istream& istr, Polynom& p);

	friend istream& operator >> (std::istream& istr, Polynom& p)
	{
		string input;
		getline(istr, input);
		string temp_str;

		for (int j = 0; j < input.length(); j++)
		{
			if (input[j] != ' ')
				temp_str.push_back(input[j]);
		}

		for (int i = 0; i < temp_str.length(); i++)
		{
			Monom m;
			int coeff;
			if (temp_str[i] == '+')
				i++;
			int x = 0, y = 0, z = 0;
			if ((isdigit(temp_str[i])) || ((temp_str[i]) == '-') && (isdigit(temp_str[i + 1])))
			{
				string temp;
				while ((temp_str[i] != 'x') && (temp_str[i] != 'y') && (temp_str[i] != 'z') && (i != temp_str.length()))
				{
					temp += temp_str[i];

					if (i != temp_str.length() - 1)
					{
						i++;
					}
					else
						break;

					if ((temp_str[i] == '+') || (temp_str[i] == '-'))
					{
						break;
					}
				}

				istringstream(temp) >> coeff;
				m.SetCoeff(coeff);

				if (((temp_str[i] != 'x') && (temp_str[i] != 'y') && (temp_str[i] != 'z')) && ((temp_str[i] == '+') || (temp_str[i] == '-')))
				{
					m.SetPower(x, y, z);
					p.AddMonom(m);
					i--;

					continue;
				}

				if (((temp_str[i] != 'x') && (temp_str[i] != 'y') && (temp_str[i] != 'z')) && (i == temp_str.length() - 1))
				{
					m.SetPower(x, y, z);
					p.AddMonom(m);
					i--;

					break;
				}
			}
			else
			{
				if ((temp_str[i] == 'x') || (temp_str[i] == 'y') || (temp_str[i] == 'z'))
				{
					m.SetCoeff(1);
				}
				else if ((temp_str[i] == '-') && ((temp_str[i + 1] == 'x') || (temp_str[i + 1] == 'y') || (temp_str[i + 1] == 'z')))
				{
					m.SetCoeff(-1);
					i++;
				}
			}

			if ((temp_str[i] != '+') && (temp_str[i] != '-'))
			{

				if (temp_str[i] == 'x')
				{
					if (i != temp_str.length() - 1)
					{
						i++;

						if ((temp_str[i] != '+') && (temp_str[i] != '-'))
						{
							if ((temp_str[i] != '^'))
							{
								if (!((temp_str[i] != 'y') && (temp_str[i] != 'z')))
									x = 1;
							}
						}
						else
						{
							i--;
							x = 1;
							m.SetPower(x, y, z);
							p.AddMonom(m);

							continue;
						}
					}
					else
					{

						x = 1;
						m.SetPower(x, y, z);
						p.AddMonom(m);
						break;
					}

					if (temp_str[i] == '^')
					{
						if ((isdigit(temp_str[i + 1])))
						{
							i++;
							string temp_x;
							temp_x = temp_str[i];
							istringstream(temp_x) >> x;

							if (i != temp_str.length() - 1)
							{
								i++;
							}
							else
							{
								m.SetPower(x, y, z);
								p.AddMonom(m);

								break;
							}

							if ((temp_str[i] == '+') || (temp_str[i] == '-'))
							{
								i--;
								m.SetPower(x, y, z);
								p.AddMonom(m);

								continue;
							}
						}
					}

				}
			}

			if ((temp_str[i] != '+') && (temp_str[i] != '-'))
			{
				if (temp_str[i] == 'y')
				{
					if (i != temp_str.length() - 1)
					{
						i++;

						if ((temp_str[i] != '+') && (temp_str[i] != '-'))
						{
							if ((temp_str[i] != '^'))
							{
								if (!(temp_str[i] != 'z'))
									y = 1;
							}
						}
						else
						{
							i--;
							y = 1;
							m.SetPower(x, y, z);
							p.AddMonom(m);
							continue;
						}
					}
					else
					{
						y = 1;
						m.SetPower(x, y, z);
						p.AddMonom(m);
						break;
					}

					if (temp_str[i] == '^')
					{
						if (isdigit(temp_str[i + 1]))
						{
							i++;
							string temp_y;
							temp_y = temp_str[i];
							istringstream(temp_y) >> y;
							if (i != temp_str.length() - 1)
							{
								i++;
							}
							else
							{
								m.SetPower(x, y, z);
								p.AddMonom(m);
								break;
							}
							if ((temp_str[i] == '+') || (temp_str[i] == '-'))
							{
								i--;
								m.SetPower(x, y, z);
								p.AddMonom(m);
								continue;
							}
						}
					}
				}
			}

			if ((temp_str[i] != '+') && (temp_str[i] != '-'))
			{
				if (!(temp_str[i] != 'z'))

					if (i != temp_str.length() - 1)
					{
						i++;

						if (!((temp_str[i] != '+') && (temp_str[i] != '-')))
						{
							i--;
							z = 1;
							m.SetPower(x, y, z);
							p.AddMonom(m);

							continue;
						}
					}
					else
					{
						z = 1;
						m.SetPower(x, y, z);
						p.AddMonom(m);

						break;
					}

				if (temp_str[i] == '^')
				{
					if (isdigit(temp_str[i + 1]))
					{
						i++;
						string temp_z;
						temp_z = temp_str[i];
						istringstream(temp_z) >> z;
					}
				}
			}
			m.SetPower(x, y, z);
			p.AddMonom(m);
		}
		return istr;
	}
};
