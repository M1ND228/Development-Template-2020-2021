#include "gtest.h"
#include "Converter.h"

/* Классические тестовые ситуации
* Словари I, V, XC...
* От большего к меньшему
* От меньшего к большему
* IVIXCIM в перемешку
*/

TEST(Converter, can_create_Converter)
{
	EXPECT_NO_THROW(Converter con);
}

TEST(Converter, can_create_Converter_with_roman)
{
	EXPECT_NO_THROW(Converter con("VII"));
}

TEST(Converter, can_create_Converter_with_roman_invalid_data_all)
{
	EXPECT_ANY_THROW(Converter con("FFF"));
}

TEST(Converter, can_create_Converter_with_roman_invalid_data_begin_word)
{
	EXPECT_ANY_THROW(Converter con("PVII"));
}

TEST(Converter, can_create_Converter_with_roman_invalid_data_end_word)
{
	EXPECT_ANY_THROW(Converter con("IIIS"));
}

TEST(Converter, can_create_Converter_with_roman_invalid_data_empty)
{
	EXPECT_ANY_THROW(Converter con(""));
}

TEST(Converter, can_create_Converter_with_arabien_int)
{
	EXPECT_NO_THROW(Converter con(125));
}

TEST(Converter, can_create_Converter_with_arabien_string)
{
	EXPECT_NO_THROW(Converter con("125"));
}

TEST(Converter, can_create_Converter_with_negative_numb_int)
{
	EXPECT_ANY_THROW(Converter con(-5));
}

TEST(Converter, can_create_Converter_with_negative_numb_string)
{
	EXPECT_ANY_THROW(Converter con("-5"));
}

TEST(Converter, convert_roma_to_arab_special_situation_input_I)
{
	Converter con("I");

	EXPECT_EQ(1, con.Get_A_Val());
}

TEST(Converter, convert_roma_to_arab_special_situation_input_IV)
{
	Converter con("IV");

	EXPECT_EQ(4, con.Get_A_Val());
}

TEST(Converter, convert_roma_to_arab_special_situation_input_V)
{
	Converter con("V");

	EXPECT_EQ(5, con.Get_A_Val());
}

TEST(Converter, convert_roma_to_arab_special_situation_input_IX)
{
	Converter con("IX");

	EXPECT_EQ(9, con.Get_A_Val());
}

TEST(Converter, convert_roma_to_arab_special_situation_input_X)
{
	Converter con("X");

	EXPECT_EQ(10, con.Get_A_Val());
}

TEST(Converter, convert_roma_to_arab_special_situation_input_XL)
{
	Converter con("XL");

	EXPECT_EQ(40, con.Get_A_Val());
}

TEST(Converter, convert_roma_to_arab_special_situation_input_L)
{
	Converter con("L");

	EXPECT_EQ(50, con.Get_A_Val());
}

TEST(Converter, convert_roma_to_arab_special_situation_input_XC)
{
	Converter con("XC");

	EXPECT_EQ(90, con.Get_A_Val());
}

TEST(Converter, convert_roma_to_arab_special_situation_input_C)
{
	Converter con("C");

	EXPECT_EQ(100, con.Get_A_Val());
}

TEST(Converter, convert_roma_to_arab_special_situation_input_CD)
{
	Converter con("CD");

	EXPECT_EQ(400, con.Get_A_Val());
}

TEST(Converter, convert_roma_to_arab_special_situation_input_D)
{
	Converter con("D");

	EXPECT_EQ(500, con.Get_A_Val());
}

TEST(Converter, convert_roma_to_arab_special_situation_input_CM)
{
	Converter con("CM");

	EXPECT_EQ(900, con.Get_A_Val());
}

TEST(Converter, convert_roma_to_arab_special_situation_input_M)
{
	Converter con("M");

	EXPECT_EQ(1000, con.Get_A_Val());
}

TEST(Converter, convert_roma_to_arab_correct_input)
{
	Converter con("VIII");

	EXPECT_EQ(8, con.Get_A_Val());
}

TEST(Converter, convert_roma_to_arab_NOcorrect_input_Get_A)
{
	Converter con("VIIIII");

	EXPECT_EQ(10, con.Get_A_Val());
}

TEST(Converter, convert_roma_to_arab_NOcorrect_input_reverse_sequence_Get_A)
{
	Converter con("IVXC");

	EXPECT_EQ(94, con.Get_A_Val());
}

TEST(Converter, convert_roma_to_arab_NOcorrect_input_mixed_situation_Get_A)
{
	Converter con("VXCICDV");

	EXPECT_EQ(501, con.Get_A_Val());
}

TEST(Converter, convert_roma_to_arab_NOcorrect_input_Get_R)
{
	Converter con("VIIIII");

	EXPECT_EQ("X", con.Get_R_Val());
}

TEST(Converter, convert_roma_to_arab_NOcorrect_input_reverse_sequence_Get_R)
{
	Converter con("LVV");

	EXPECT_EQ("LX", con.Get_R_Val());
}

TEST(Converter, convert_roma_to_arab_NOcorrect_input_mixed_situation_Get_R)
{
	Converter con("VXCICDV");

	EXPECT_EQ("DI", con.Get_R_Val());
}

TEST(Converter, convert_roma_to_arab_NOcorrect_input_ALLmixed_situation_Get_R)
{
	Converter con("IXIXIXXXIIIM");

	EXPECT_EQ("ML", con.Get_R_Val());
}

TEST(Converter, convert_arab_to_roma_correct_input)
{
	Converter con(6);

	EXPECT_EQ("VI", con.Get_R_Val());
}

TEST(Converter, convert_arab_to_roma_correct_input_string)
{
	Converter con("6");

	EXPECT_EQ("VI", con.Get_R_Val());
}

TEST(Converter, convert_arab_to_roma_NOcorrect_input_minimum_value)
{

	EXPECT_ANY_THROW(Converter con(-3));
}

TEST(Converter, convert_arab_to_roma_NOcorrect_input_max_value_int)
{

	EXPECT_ANY_THROW(Converter con(4000));
}

TEST(Converter, convert_arab_to_roma_NOcorrect_input_max_value_string)
{

	EXPECT_ANY_THROW(Converter con("4000"));
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

TEST(Converter, test_CheckInput_input_arabien)
{
	Converter con;
	
	EXPECT_EQ(0, con.CheckInput("238"));
}

TEST(Converter, test_CheckInput_input_roma)
{
	Converter con;

	EXPECT_EQ(1, con.CheckInput("LV"));
}

TEST(Converter, test_CheckInput_input_invalid_string_begin)
{
	Converter con;

	EXPECT_EQ(-1, con.CheckInput("FV"));
}

TEST(Converter, test_CheckInput_input_invalid_string_end)
{
	Converter con;

	EXPECT_EQ(-1, con.CheckInput("VIA"));
}

TEST(Converter, test_CheckInput_input_invalid_string_all)
{
	Converter con;

	EXPECT_EQ(-1, con.CheckInput("AFAF"));
}


