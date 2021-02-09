#include "gtest.h"
#include "Converter.h"

TEST(Converter, can_create_Converter)
{
	EXPECT_NO_THROW(Converter con);
}

TEST(Converter, can_create_Converter_with_roman)
{
	EXPECT_NO_THROW(Converter con("V||"));
}

TEST(Converter, can_create_Converter_with_arabien)
{
	EXPECT_NO_THROW(Converter con(125));
}

TEST(Converter, can_convert_roma_to_arab_correct_input)
{
	Converter con("VIII");

	EXPECT_EQ(8, con.Get_A_Val());
}

TEST(Converter, can_convert_roma_to_arab_NOcorrect_input)
{
	Converter con("VIIIII");

	EXPECT_EQ(10, con.Get_A_Val());
}

TEST(Converter, can_convert_arab_to_roma_correct_input)
{
	Converter con(6);

	EXPECT_EQ("VI", con.Get_R_Val());
}

TEST(Converter, can_convert_arab_to_roma_NOcorrect_input_minimum_value)
{

	EXPECT_ANY_THROW(Converter con(-3));
}

TEST(Converter, can_convert_arab_to_roma_NOcorrect_input_max_value)
{

	EXPECT_ANY_THROW(Converter con(4000));
}

TEST(Converter, can_get_arabic)
{
	Converter con("XXXVII");

	EXPECT_EQ(37, con.Get_A_Val());
}

TEST(Converter, can_get_roma)
{
	Converter con(25);

	EXPECT_EQ("XXV", con.Get_R_Val());
}


