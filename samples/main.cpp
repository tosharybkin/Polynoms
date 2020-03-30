#include "list.h"
#include "polynom.h"
#include <iostream>

using namespace std;


void main()
{
	Polynom p, q;

	cout << "Info: the power of variables shouldn't be less then 0  and more then 9" << endl;
	cout << "Enter the first polynom" << endl;
	cout << "P(x; y; z) = ";
	cin >> p;
	cout << endl;

	cout << "Enter the second polynom" << endl;
	cout << "Q(x; y; z) = ";
	cin >> q;
	cout << endl;


	cout << "Arranged:" << endl << "P(x; y; z) = " << p << endl << "Q(x; y; z) = " << q << endl;
	cout << "P(z; y; z) + Q(x; y; z) = ";
	cout << p + q;
	cout << "P(z; y; z) - Q(x; y; z) = ";
	cout << p - q;
	cout << "Q(z; y; z) - P(x; y; z) = ";
	cout << q - p;

	int n;
	cin >> n;
}