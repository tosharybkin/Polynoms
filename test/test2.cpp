#include "gtest.h"
#include "polynom.h"



TEST(Polynom, can_use_constr)
{
	ASSERT_NO_THROW(Polynom p());
}


TEST(Polynom, can_correct_use_toStr)
{
	Polynom p;
	Monom m(123, 123);

	p.AddMonom(m);

	EXPECT_EQ(p.toStr(), "123x^1y^2z^3");
}

TEST(Polynom, can_sort_monoms)
{
	Polynom p, q, res;
	Monom m(1, 321);
	Monom n(1, 987);

	p.AddMonom(m);
	q.AddMonom(n);

	res = p + q;

	EXPECT_EQ(res.toStr(), "1x^9y^8z^7 + 1x^3y^2z^1");
}

TEST(Polynom, can_add_monom)
{
	Polynom p;
	Monom m(123, 123);

	p.AddMonom(m);

	EXPECT_EQ(p.toStr(), "123x^1y^2z^3");
}

TEST(Polynom, can_use_plus)
{
	Polynom p, q, res;
	Monom m(1, 123);
	Monom n(1, 123);

	p.AddMonom(m);
	q.AddMonom(n);

	res = p + q;

	EXPECT_EQ(res.toStr(), "2x^1y^2z^3");
}

TEST(Polynom, can_use_minus)
{
	Polynom p, q, res;
	Monom m(2, 123);
	Monom n(1, 123);

	p.AddMonom(m);
	q.AddMonom(n);

	res = p - q;

	EXPECT_EQ(res.toStr(), "1x^1y^2z^3");
}

