#include "monom.h"
#include <gtest.h>

TEST(Monom, can_default_constructor_create)
{
	EXPECT_NO_THROW(Monom m);
}

TEST(Monom, can_parameters_constructor_create)
{
	EXPECT_NO_THROW(Monom m(10, 1, 1, 1));
}

TEST(Monom, bad_parameters_constructor_create)
{
	EXPECT_ANY_THROW(Monom m(2, 1, 21, 1));
}

TEST(Monom, copy_constructor_copy_elements)
{
	Monom m1(2, 1, 1, 1);
	Monom m2(3, 1, 1, 1);
	EXPECT_EQ(m1, m2);
}

TEST(Monom, can_work_getA)
{
	Monom m;
	EXPECT_NO_THROW(m.Get_A());
}

TEST(Monom, check_return_getA)
{
	Monom m(2, 5, 1, 1);
	EXPECT_EQ(m.Get_A(), 5);
}

TEST(Monom, can_work_getB)
{
	Monom m;
	EXPECT_NO_THROW(m.Get_B());
}

TEST(Monom, check_return_getB)
{
	Monom m(2, 1, 5, 1);
	EXPECT_EQ(m.Get_B(), 5);
}

TEST(Monom, can_work_getC)
{
	Monom m;
	EXPECT_NO_THROW(m.Get_C());
}

TEST(Monom, check_return_getC)
{
	Monom m(2, 1, 1, 5);
	EXPECT_EQ(m.Get_C(), 5);
}

TEST(Monom, can_work_getCoef)
{
	Monom m;
	EXPECT_NO_THROW(m.Get_coef());
}

TEST(Monom, check_return_getCoef)
{
	Monom m(5, 1, 1, 1);
	EXPECT_EQ(m.Get_coef(), 5);
}

TEST(Monom, can_work_operator_comparisons)
{
	Monom m1(1, 1, 1, 1);
	Monom m2(1, 1, 1, 1);
	EXPECT_NO_THROW(m1 == m2);
}

TEST(Monom, check_return_operator_comparisons_true)
{
	Monom m1(2, 1, 1, 1);
	Monom m2(2, 1, 1, 1);
	EXPECT_TRUE(m1 == m2);
}

TEST(Monom, check_return_operator_comparisons_false)
{
	Monom m1(1, 1, 1, 1);
	Monom m2(2, 2, 2, 2);
	EXPECT_FALSE(m1 == m2);
}

TEST(Monom, check_return_operator_Unequal_true)
{
	Monom m1(1, 1, 1, 1);
	Monom m2(2, 2, 2, 2);
	EXPECT_NO_THROW(m1 != m2);
}

TEST(Monom, check_return_operator_Unequal_false)
{
	Monom m1(1, 1, 1, 1);
	Monom m2(1, 1, 1, 1);
	EXPECT_FALSE(m1 != m2);
}


TEST(Monom, check_return_operator_Bolshe_true)
{
	Monom m1(2, 2, 2, 2);
	Monom m2(1, 1, 1, 1);
	EXPECT_NO_THROW(m1 > m2);
}

TEST(Monom, check_return_operator_Bolshe_false)
{
	Monom m1(1, 1, 1, 1);
	Monom m2(2, 2, 2, 2);
	EXPECT_FALSE(m1 > m2);
}

TEST(Monom, check_return_operator_Menshe_true)
{
	Monom m1(1, 1, 1, 1);
	Monom m2(2, 2, 2, 2);
	EXPECT_TRUE(m1 < m2);
}

TEST(Monom, check_return_operator_Menshe_false)
{
	Monom m1(2, 2, 2, 2);
	Monom m2(1, 1, 1, 1);
	EXPECT_FALSE(m1 < m2);
}

TEST(Monom, check_return_operator_Bolshe_OR_Ravno_true)
{
	Monom m1(5, 5, 5, 5);
	Monom m2(1, 1, 1, 1);
	EXPECT_TRUE(m1 >= m2);
}

TEST(Monom, check_return_operator_Bolshe_OR_Ravno_false)
{
	Monom m1(1, 1, 1, 1);
	Monom m2(5, 5, 5, 5);
	EXPECT_FALSE(m1 >= m2);
}

TEST(Monom, check_return_operator_Menshe_OR_Ravno_true)
{
	Monom m1(1, 1, 1, 1);
	Monom m2(2, 2, 2, 2);
	EXPECT_TRUE(m1 <= m2);
}

TEST(Monom, check_return_Menshe_OR_Ravno_false)
{
	Monom m1(2, 2, 2, 2);
	Monom m2(1, 1, 1, 1);
	EXPECT_FALSE(m1 <= m2);
}

TEST(Monom, can_plus_two_similar_monoms_work)
{
	Monom m1(1, 1, 1, 1);
	Monom m2(1, 1, 1, 1);
	EXPECT_NO_THROW(m1 + m2);
}

TEST(Monom, can_plus_two_NOTsimilar_monoms_NOTwork)
{
	Monom m1(1, 1, 1, 1);
	Monom m2(2, 3, 2, 3);
	EXPECT_ANY_THROW(m1 + m2);
}

TEST(Monom, check_return_values_operator_plus)
{
	Monom m1(1, 1, 1, 1);
	Monom m2(1, 1, 1, 1);
	Monom otvet(2, 1, 1, 1);
	EXPECT_EQ(otvet, m1 + m2);
}

TEST(Monom, can_work_operator_minus)
{
	Monom m1(5, 1, 1, 1);
	Monom m2(1, 1, 1, 1);
	EXPECT_NO_THROW(m1 - m2);
}

TEST(Monom, can_work_operator_minus_NOTsimilar)
{
	Monom m1(5, 1, 1, 1);
	Monom m2(1, 1, 2, 1);
	EXPECT_ANY_THROW(m1 - m2);
}

TEST(Monom, check_return_values_operator_minus)
{
	Monom m1(5, 1, 1, 1);
	Monom m2(1, 1, 1, 1);
	Monom otvet(4, 1, 1, 1);
	EXPECT_EQ(otvet, m1 - m2);
}

TEST(Monom, can_work_operator_minusRavno)
{
	Monom m1(2, 1, 1, 1);
	Monom m2(1, 1, 1, 1);
	EXPECT_NO_THROW(m1 -= m2);
}

TEST(Monom, can_work_operator_minusRavno_NOTsimilar)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(2, 3, 10, 4);
	EXPECT_ANY_THROW(m1 -= m2);
}

TEST(Monom, check_return_values_operator_minusRavno)
{
	Monom m1(3, 1, 1, 1);
	Monom m2(1, 1, 1, 1);
	Monom otvet(2, 1, 1, 1);
	EXPECT_EQ(otvet, m1 -= m2);
}

TEST(Monom, can_work_operator_add_minus)
{
	Monom m(1, 1, 1, 1);
	EXPECT_NO_THROW(-m);
}

TEST(Monom, check_return_values_operator_add_minus)
{
	Monom m1(1, 1, 1, 1);
	Monom otvet(-1, 1, 1, 1);
	EXPECT_NO_THROW(otvet, -m1);
}

TEST(Monom, can_work_operator_plusRavno_similar)
{
	Monom m1(1, 1, 1, 1);
	Monom m2(1, 1, 1, 1);
	EXPECT_NO_THROW(m1 += m2);
}

TEST(Monom, can_work_operator_plusRavno_NOTsimilar)
{
	Monom m1(1, 1, 1, 1);
	Monom m2(5, 10, 5, 10);
	EXPECT_ANY_THROW(m1 += m2);
}

TEST(Monom, check_return_values_operator_plusRavno)
{
	Monom m1(1, 1, 1, 1);
	Monom m2(1, 1, 1, 1);
	Monom otvet(2, 1, 1, 1);
	EXPECT_EQ(otvet, m1 += m2);
}

TEST(Monom, can_work_operator_Umnogity_similar)
{
	Monom m1(1, 1, 1, 1);
	Monom m2(1, 1, 1, 1);
	EXPECT_NO_THROW(m1 * m2);
}

TEST(Monom, check_return_values_operator_Umnogity)
{
	Monom m1(1, 2, 1, 6);
	Monom m2(1, 2, 1, 6);
	Monom otvet(1, 4, 2, 12);
	EXPECT_EQ(otvet, m1 * m2);
}

TEST(Monom, can_work_operator_UmnogityRavno)
{
	Monom m1(1, 1, 1, 1);
	Monom m2(1, 1, 1, 1);
	EXPECT_NO_THROW(m1 *= m2);
}

TEST(Monom, check_return_values_operator_UmnogityRavno)
{
	Monom m1(1, 2, 3, 4);
	Monom m2(1, 2, 3, 4);
	Monom otvet(1, 4, 6, 8);
	EXPECT_EQ(otvet, m1 *= m2);
}

TEST(Monom, can_work_Resault)
{
	Monom m1(5, 2, 1, 4);
	EXPECT_NO_THROW(m1.Resault(5, 2, 1));
}

TEST(Monom, check_return_values_Resault)
{
	Monom m1(1, 2, 3, 4);
	EXPECT_EQ(512, m1.Resault(2, 2, 2));
}

TEST(Monom, can_work_ConvertString)
{
	Monom m1(1, 1, 1, 1);
	EXPECT_NO_THROW(m1.ConvertString());
}

TEST(Monom, chec_return_string_ConvertString)
{
	Monom m1(1, 2, 5, 3);
	EXPECT_EQ("a^2 * b^5 * c^3 ", m1.ConvertString());
}

