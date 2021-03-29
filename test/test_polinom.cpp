#include <polinom.h>
#include <gtest.h>

TEST(Polinom, can_default_constructor_create)
{
	EXPECT_NO_THROW(Polinom m);
}

TEST(Polinom, can_parameters_constructor_create)
{
	Monom m1(1,1,1,1);
	Monom m2(2,2,2,2);
	std::vector<Monom> m = { m1, m2 };
	EXPECT_NO_THROW(Polinom p(m));
}
TEST(Polinom, can_copy_constructor_create)
{
	Monom m1(1, 1, 1, 1);
	Monom m2(2, 2, 2, 2);
	std::vector<Monom> m = { m1, m2 };
	Polinom p1(m);
	EXPECT_NO_THROW(Polinom p2(p1));
}

TEST(Polinom, can_work_operator_PlusRavno_monom)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 1, 1, 1);
	Monom m3(1, 1, 1, 1);
	std::vector<Monom> m = { m1, m2, };
	Polinom p(m);
	EXPECT_NO_THROW(p += m3);
}

TEST(Polinom, can_work_operator_PlusRavno_polinom)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 1, 1, 1);
	Monom m3(1, 1, 1, 1);
	Monom m4(3, 2, 1, 5);
	std::vector<Monom> mon1 = { m1, m2, m3, m4 };
	std::vector<Monom> mon2 = { m4, m2, m3, m1 };
	Polinom p1(mon1);
	Polinom p2(mon2);
	EXPECT_NO_THROW(p1 += p2);
}

TEST(Polinom, can_work_operator_Plus_monom)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 1, 1, 1);
	Monom m3(1, 1, 1, 1);
	std::vector<Monom> m = { m1, m2, };
	Polinom p(m);
	EXPECT_NO_THROW(p + m3);
}

TEST(Polinom, can_work_operator_Plus_polinom)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 1, 1, 1);
	Monom m3(1, 1, 1, 1);
	Monom m4(3, 2, 1, 5);
	std::vector<Monom> mon1 = { m1, m2, m3, m4 };
	std::vector<Monom> mon2 = { m4, m2, m3, m1 };
	Polinom p1(mon1);
	Polinom p2(mon2);
	EXPECT_NO_THROW(p1 + p2);
}

TEST(Polinom, can_work_operator_MinusRavno_monom)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 1, 1, 1);
	Monom m3(1, 1, 1, 1);
	std::vector<Monom> m = { m1, m2, };
	Polinom p(m);
	EXPECT_NO_THROW(p -= m3);
}

TEST(Polinom, can_work_operator_MinusRavno_polinom)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 1, 1, 1);
	Monom m3(1, 1, 1, 1);
	Monom m4(3, 2, 1, 5);
	std::vector<Monom> mon1 = { m1, m2, m3, m4 };
	std::vector<Monom> mon2 = { m4, m2, m3, m1 };
	Polinom p1(mon1);
	Polinom p2(mon2);
	EXPECT_NO_THROW(p1 -= p2);
}

TEST(Polinom, can_work_operator_Minus_monom)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 1, 1, 1);
	Monom m3(1, 1, 1, 1);
	std::vector<Monom> m = { m1, m2, };
	Polinom p(m);
	EXPECT_NO_THROW(p - m3);
}

TEST(Polinom, can_work_operator_Minus_polinom)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 1, 1, 1);
	Monom m3(1, 1, 1, 1);
	Monom m4(3, 2, 1, 5);
	std::vector<Monom> mon1 = { m1, m2, m3, m4 };
	std::vector<Monom> mon2 = { m4, m2, m3, m1 };
	Polinom p1(mon1);
	Polinom p2(mon2);
	EXPECT_NO_THROW(p1 - p2);
}

TEST(Polinom, can_work_operator_UmnogitRavno_monom)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 1, 1, 1);
	Monom m3(1, 1, 1, 1);
	std::vector<Monom> m = { m1, m2, };
	Polinom p(m);
	EXPECT_NO_THROW(p *= m3);
}

TEST(Polinom, can_work_operator_UmnogitRavno_polinom)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 1, 1, 1);
	Monom m3(1, 1, 1, 1);
	Monom m4(3, 2, 1, 5);
	std::vector<Monom> mon1 = { m1, m2, m3, m4 };
	std::vector<Monom> mon2 = { m4, m2, m3, m1 };
	Polinom p1(mon1);
	Polinom p2(mon2);
	EXPECT_NO_THROW(p1 *= p2);
}

TEST(Polinom, can_work_operator_Umnogit_monom)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 1, 1, 1);
	Monom m3(1, 1, 1, 1);
	std::vector<Monom> m = { m1, m2, };
	Polinom p(m);
	EXPECT_NO_THROW(p * m3);
}

TEST(Polinom, can_work_operator_Umnogit_polinom)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 1, 1, 1);
	Monom m3(1, 1, 1, 1);
	Monom m4(3, 2, 1, 5);
	std::vector<Monom> mon1 = { m1, m2, m3, m4 };
	std::vector<Monom> mon2 = { m4, m2, m3, m1 };
	Polinom p1(mon1);
	Polinom p2(mon2);
	EXPECT_NO_THROW(p1 * p2);
}

TEST(Polinom, can_work_operator_Srevnenie_polinom)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 1, 1, 1);
	Monom m3(1, 1, 1, 1);
	Monom m4(3, 2, 1, 5);
	std::vector<Monom> mon1 = { m1, m2, m3, m4 };
	std::vector<Monom> mon2 = { m4, m2, m3, m1 };
	Polinom p1(mon1);
	Polinom p2(mon2);
	EXPECT_TRUE(p1 == p2);
}

TEST(Polinom, check_return_operator_Srevnenie_polinom_true)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 1, 1, 1);
	Monom m3(1, 1, 1, 1);
	Monom m4(3, 2, 1, 5);
	std::vector<Monom> mon1 = { m1, m2, m3, m4 };
	std::vector<Monom> mon2 = { m4, m2, m3, m1 };
	Polinom p1(mon1);
	Polinom p2(mon2);
	EXPECT_TRUE(p1 == p2);
}

TEST(Polinom, check_return_operator_Srevnenie_polinom_false)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 1, 1, 1);
	Monom m3(1, 1, 1, 1);
	Monom m4(3, 2, 1, 5);
	std::vector<Monom> mon1 = { m1, m2, m3 };
	std::vector<Monom> mon2 = { m4, m2, m3, m1 };
	Polinom p1(mon1);
	Polinom p2(mon2);
	EXPECT_FALSE(p1 == p2);
}

TEST(Polinom, can_work_operator_Prisvoit_polinom)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 1, 1, 1);
	Monom m3(1, 1, 1, 1);
	Monom m4(3, 2, 1, 5);
	std::vector<Monom> mon1 = { m1, m2, m3, m4 };
	std::vector<Monom> mon2 = { m4, m2, m3, m1 };
	Polinom p1(mon1);
	Polinom p2(mon2);
	EXPECT_NO_THROW(p1 = p2);
}

TEST(Polinom, to_str_works)
{
	Monom m(1, 2, 3, 4);
	Monom m4(1, 1, 1, 1);
	std::vector<Monom> monoms1 = { m, m4 };
	Polinom p(monoms1);
	EXPECT_NO_THROW(p.to_str());
}

TEST(Polinom, check_return_string_toStr)
{
	Monom m1(2, 5, 2, 4);
	Monom m2(1, 1, 1, 1);
	Monom m3(3, 2, 2, 2);
	std::vector<Monom> m = { m1, m2 };
	Polinom p(m);
	EXPECT_EQ("2 * a^5 * b^2 * c^4 +a * b * c ", p.to_str());
}

TEST(Polinom, check_return_value_Resault)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 1, 1, 1);
	std::vector<Monom> m = { m1, m2 };
	Polinom p(m);
	EXPECT_EQ(520, p.Resault(2, 2, 2));
}

TEST(Polinom, can_work_DeletPolinom)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 1, 1, 1);
	std::vector<Monom> m = { m1, m2 };
	Polinom p(m);
	EXPECT_NO_THROW(p.DeletPolinom());
}

TEST(Polinom, check_values_after_DeletePolinom)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 1, 1, 1);
	Monom m3(0, 0, 0, 0);
	std::vector<Monom> m_1 = { m1, m2 };
	std::vector<Monom> m_2 = { m3 };
	Polinom p1(m_1);
	p1.DeletPolinom();
	Polinom p2(m_2);
	EXPECT_TRUE(p1 == p2);
}