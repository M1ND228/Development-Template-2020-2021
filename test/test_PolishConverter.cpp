#include "PolishConverter.h"

#include <gtest.h>


TEST(PolishConverter, can_create_PolishConverter)
{
	ASSERT_NO_THROW(PolishConverter<char> pc); 
}

TEST(PolishConverter, can_input_expression_in_PolishConverter)
{
	PolishConverter<char> pc;
	ASSERT_NO_THROW(pc.input("(1 + 2) * 2"););
}

TEST(PolishConverter, can_input_expression_square_brackets_in_PolishConverter)
{
	PolishConverter<char> pc;
	ASSERT_NO_THROW(pc.input("[1 + 2] * 2"););
}

TEST(PolishConverter, can_input_expression_curly_brackets_in_PolishConverter)
{
	PolishConverter<char> pc;
	ASSERT_NO_THROW(pc.input("{1 + 2} * 2"););
}

TEST(PolishConverter, can_input_expression_all_brackets_in_PolishConverter)
{
	PolishConverter<char> pc;
	ASSERT_NO_THROW(pc.input("{2 *[1 + 5] - (1 + 2) * 2}"););
}

TEST(PolishConverter, can_input_error_excess_parenthesis_opening_expression_in_PolishConverter)
{
	PolishConverter<char> pc;
	ASSERT_ANY_THROW(pc.input("(1 + 2) * (2"););
}

TEST(PolishConverter, can_input_error_excess_parenthesis_closing_expression_in_PolishConverter)
{
	PolishConverter<char> pc;
	ASSERT_ANY_THROW(pc.input("(1 + 2) * (2))"););
}

TEST(PolishConverter, can_input_error_excess_not_paired_brackets_in_PolishConverter)
{
	PolishConverter<char> pc;
	ASSERT_ANY_THROW(pc.input("{1 + 2) * 2"););
}

TEST(PolishConverter, can_input_error_excess_not_paired_brackets_square_and_curly_in_PolishConverter)
{
	PolishConverter<char> pc;
	ASSERT_ANY_THROW(pc.input("([1 + 2} * (2))"););
}

TEST(PolishConverter, can_input_incorrect_symbol_in_PolishConverter)
{
	PolishConverter<char> pc;
	ASSERT_ANY_THROW(pc.input("? ^ 3"););
}

TEST(PolishConverter, can_input_incorrect_symbol_russian_in_PolishConverter)
{
	PolishConverter<char> pc;
	ASSERT_ANY_THROW(pc.input("À ^ 3"););
}

TEST(PolishConverter, can_input_Var_in_PolishConverter)
{
	PolishConverter<char> pc;
	pc.input("(1 + 2) * a");
	ASSERT_NO_THROW(pc.AddVar('a', 2););
}

TEST(PolishConverter, can_input_Var_in_doesnt_exist_PolishConverter)
{
	PolishConverter<char> pc;
	pc.input("(1 + 2) * 3");
	ASSERT_ANY_THROW(pc.AddVar('a', 2););
}

TEST(PolishConverter, can_ConvertToPolish)
{
	PolishConverter<char> pc;
	pc.input("(1 + 2) * 3");
	ASSERT_NO_THROW(pc.ConvertToPolish());
}

TEST(PolishConverter, compare_values_after_Calculate_integer_numbers)
{
	PolishConverter<char> pc;
	pc.input("(100 + 900) * 3");
	std::string res_polsk = pc.ConvertToPolish();
	double res = pc.Calculate(res_polsk);

	ASSERT_DOUBLE_EQ(3000,res);
}

TEST(PolishConverter, compare_values_after_Calculate_double_numbers)
{
	PolishConverter<char> pc;
	pc.input("(1.57 + 98.43) * 0.1");
	std::string res_polsk = pc.ConvertToPolish();
	double res = pc.Calculate(res_polsk);

	ASSERT_DOUBLE_EQ(10, res);
}

TEST(PolishConverter, compare_values_after_Calculate_double_and_integer_numbers)
{
	PolishConverter<char> pc;
	pc.input("(1.57 + 98.43) ^ 2");
	std::string res_polsk = pc.ConvertToPolish();
	double res = pc.Calculate(res_polsk);

	ASSERT_DOUBLE_EQ(10000, res);
}

TEST(PolishConverter, compare_values_after_Calculate_double_and_integer_numbers_and_use_Var)
{
	PolishConverter<char> pc;
	pc.input("(1.57 + 98.43) ^ a");
	pc.AddVar('a', 2);
	std::string res_polsk = pc.ConvertToPolish();
	double res = pc.Calculate(res_polsk);

	ASSERT_DOUBLE_EQ(10000, res);
}


TEST(PolishConverter, compare_values_after_Calculate_use_positive_module)
{
	PolishConverter<char> pc;
	pc.input("|2| + 8");
	std::string res_polsk = pc.ConvertToPolish();
	double res = pc.Calculate(res_polsk);

	ASSERT_DOUBLE_EQ(10, res);
}

TEST(PolishConverter, compare_values_after_Calculate_use_negative_module)
{
	PolishConverter<char> pc;
	pc.input("|-2| + 8");
	std::string res_polsk = pc.ConvertToPolish();
	double res = pc.Calculate(res_polsk);

	ASSERT_DOUBLE_EQ(10, res);
}

TEST(PolishConverter, compare_values_after_Calculate_use_unar_minus)
{
	PolishConverter<char> pc;
	pc.input("(1 + 2) ^ (-9)");
	std::string res_polsk = pc.ConvertToPolish();
	double res = pc.Calculate(res_polsk);

	ASSERT_DOUBLE_EQ(1.129830963909753, res);
}

TEST(PolishConverter, convert_StrToDouble)
{
	PolishConverter<char> pc;
	double res = pc.StrToDouble("153.863");
	ASSERT_DOUBLE_EQ(153.863, res);
}

TEST(PolishConverter, convert_StrToInt)
{
	PolishConverter<char> pc;
	int res = pc.StrToInt("986");
	ASSERT_EQ(986, res);
}

TEST(PolishConverter, test_excute_calc_plus)
{
	PolishConverter<char> pc;
	int res = pc.excute_calc(149.5, 0.5, '+');
	ASSERT_DOUBLE_EQ(150, res);
}

TEST(PolishConverter, test_excute_calc_minus)
{
	PolishConverter<char> pc;
	int res = pc.excute_calc(15, 15, '-');
	ASSERT_DOUBLE_EQ(0, res);
}

TEST(PolishConverter, test_excute_calc_multiply)
{
	PolishConverter<char> pc;
	int res = pc.excute_calc(2, 2, '*');
	ASSERT_DOUBLE_EQ(4, res);
}

TEST(PolishConverter, test_excute_calc_divide)
{
	PolishConverter<char> pc;
	int res = pc.excute_calc(100, 0.1, '/');
	ASSERT_DOUBLE_EQ(1000, res);
}

TEST(PolishConverter, test_excute_calc_degree)
{
	PolishConverter<char> pc;
	int res = pc.excute_calc(2, 10, '^');
	ASSERT_DOUBLE_EQ(1024, res);
}

TEST(PolishConverter, test_excute_calc_degree_double)
{
	PolishConverter<char> pc;
	int res = pc.excute_calc(2, 0.5, '^');
	ASSERT_DOUBLE_EQ(1, res);
}

TEST(PolishConverter, test_correctInput_symbol)
{
	PolishConverter<char> pc;
	int ind = pc.correctInput('z');
	ASSERT_EQ(0, ind);
}

TEST(PolishConverter, test_correctInput_operator)
{
	PolishConverter<char> pc;
	int ind = pc.correctInput('+');
	ASSERT_EQ(10, ind);
}

TEST(PolishConverter, test_correctInput_number)
{
	PolishConverter<char> pc;
	int ind = pc.correctInput('2');
	ASSERT_EQ(11, ind);
}

TEST(PolishConverter, test_correctInput_bracket_open)
{
	PolishConverter<char> pc;
	int ind = pc.correctInput('(');
	ASSERT_EQ(1, ind);
}

TEST(PolishConverter, test_correctInput_bracket_close)
{
	PolishConverter<char> pc;
	int ind = pc.correctInput(')');
	ASSERT_EQ(2, ind);
}

TEST(PolishConverter, test_correctInput_bracket_figure_open)
{
	PolishConverter<char> pc;
	int ind = pc.correctInput('{');
	ASSERT_EQ(3, ind);
}

TEST(PolishConverter, test_correctInput_bracket_figure_close)
{
	PolishConverter<char> pc;
	int ind = pc.correctInput('}');
	ASSERT_EQ(4, ind);
}

TEST(PolishConverter, test_correctInput_bracket_square_open)
{
	PolishConverter<char> pc;
	int ind = pc.correctInput('[');
	ASSERT_EQ(5, ind);
}

TEST(PolishConverter, test_correctInput_bracket_square_close)
{
	PolishConverter<char> pc;
	int ind = pc.correctInput(']');
	ASSERT_EQ(6, ind);
}

TEST(PolishConverter, test_correctInput_space)
{
	PolishConverter<char> pc;
	int ind = pc.correctInput(' ');
	ASSERT_EQ(7, ind);
}

TEST(PolishConverter, test_correctInput_module)
{
	PolishConverter<char> pc;
	int ind = pc.correctInput('|');
	ASSERT_EQ(-2, ind);
}

TEST(PolishConverter, test_correctInput_point)
{
	PolishConverter<char> pc;
	int ind = pc.correctInput('.');
	ASSERT_EQ(8, ind);
}

TEST(PolishConverter, test_correctInput_incorect_symbol)
{
	PolishConverter<char> pc;
	int ind = pc.correctInput('@');
	ASSERT_EQ(-1, ind);
}

TEST(PolishConverter, test_priorit_brackets_open)
{
	PolishConverter<char> pc;
	int ind = pc.priorit('(');
	ASSERT_EQ(0, ind);
}

TEST(PolishConverter, test_priorit_brackets_close)
{
	PolishConverter<char> pc;
	int ind = pc.priorit(')');
	ASSERT_EQ(1, ind);
}

TEST(PolishConverter, test_priorit_plus)
{
	PolishConverter<char> pc;
	int ind = pc.priorit('+');
	ASSERT_EQ(2, ind);
}

TEST(PolishConverter, test_priorit_minus)
{
	PolishConverter<char> pc;
	int ind = pc.priorit('-');
	ASSERT_EQ(2, ind);
}

TEST(PolishConverter, test_priorit_multiply)
{
	PolishConverter<char> pc;
	int ind = pc.priorit('*');
	ASSERT_EQ(3, ind);
}

TEST(PolishConverter, test_priorit_divide)
{
	PolishConverter<char> pc;
	int ind = pc.priorit('/');
	ASSERT_EQ(3, ind);
}

TEST(PolishConverter, test_priorit_degree)
{
	PolishConverter<char> pc;
	int ind = pc.priorit('^');
	ASSERT_EQ(4, ind);
}

TEST(PolishConverter, test_priorit_incorrect)
{
	PolishConverter<char> pc;
	int ind = pc.priorit('d');
	ASSERT_EQ(-1, ind);
}