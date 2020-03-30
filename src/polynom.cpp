#include "polynom.h"
#include "monom.h"

using namespace std;


Polynom::Polynom()
{
	list.GetHead()->m = Monom(0, -1);
}

void Polynom::AddMonom(const Monom& _m)
{
	Node* current = list.GetHead()->next;
	Node* previous = list.GetHead();

	while (_m.GetPower() < current->m.GetPower())
	{
		previous = current;
		current = current->next;
	}

	if (_m.GetPower() == current->m.GetPower())
	{
		current->m.SetCoeff(current->m.GetCoef() + _m.GetCoef());
		if (current->m.GetCoef() == 0)
		{
			List::DeleteNext(previous);
		}
	}
	else
	{
		List::Insert(previous, new Node(_m));
	}
}

Polynom Polynom:: operator + (Polynom& P)
{
	Polynom Q(*this);
	Node* p = P.list.GetHead()->next;
	Node* q = Q.list.GetHead()->next;
	Node* q1 = Q.list.GetHead();

	while (true)
	{
		if (p->m.GetPower() == q->m.GetPower())
		{
			if (p->m.GetPower() == -1)
			{
				break;
			}
			else
			{
				q->m.SetCoeff(q->m.GetCoef() + p->m.GetCoef());
				p = p->next;

				if (q->m.GetCoef() == 0)
				{
					List::DeleteNext(q1);
					q = q1->next;
				}
				else
				{
					q1 = q;
					q = q->next;
				}
			}
		}
		else
		{
			if (p->m.GetPower() < q->m.GetPower())
			{
				q1 = q;
				q = q->next;
			}
			else
			{
				List::Insert(q1, new Node(p->m));
				q1 = q1->next;
				p = p->next;
			}
		}
	}
	return Q;
}

Polynom Polynom::operator * (double a)
{
	if (a == 0)
	{
		Polynom Q;

		return Q;
	}

	Polynom Q(*this);
	Node* current = Q.list.GetHead()->next;

	while (current->m.GetPower() != -1)
	{
		current->m.SetCoeff(current->m.GetCoef() * a);
		current = current->next;
	}

	return Q;
}

Polynom Polynom::operator - (Polynom& p)
{
	return *this + p * (-1);

}


string Polynom::toStr()
{
	string res;

	Node* current = this->list.GetHead()->next;
	res += current->m.toStr();
	current = current->next;

	while (current->m.GetPower() != -1)
	{
		if (current->m.GetCoef() > 0)
			res += " + " + current->m.toStr();
		else
			res += " " + current->m.toStr();
		current = current->next;
	}

	return res;
}


