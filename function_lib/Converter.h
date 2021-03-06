#ifndef countof
#define countof(array) (sizeof(array) / sizeof((array)[0]))
#endif

#include <string>
#include <iostream>

struct roman
{
	std::string val;
};

struct arabien
{
	int val;
};

class Converter
{
public:
	Converter();
	Converter(std::string R_);
	Converter(int A_);
	~Converter();

	arabien ConvertRomToArab(roman R_);
	roman	ConvertArabToRom(arabien A_);

	void OutputConsole();
	int CheckInput(std::string inText);

	std::string Get_R_Val();
	int			Get_A_Val();

	friend std::ostream& operator<< (std::ostream& out, const Converter& converter);
	friend std::istream& operator>> (std::istream& in, Converter& converter);

private:
	roman	R;
	arabien A;
};

inline Converter::Converter()
{
	R.val = "";
	A.val = 0;
}

inline Converter::Converter(std::string R_)
{
	int num = 0;
	switch (CheckInput(R_))
	{
	case 1:
		R.val = R_;
		A = ConvertRomToArab(R);
		R = ConvertArabToRom(A);		// Edit input Roman Line to correct 
		break;
	case 0:
		num = atoi(R_.c_str());
		if (num < 0 || num > 3999)
		{
			throw std::out_of_range("Input error: The number is out of bounds");
		}
		A.val = num;
		R = ConvertArabToRom(A);
		break;
	case -1:
		throw std::logic_error("Logic error: Invalid data.");
		break;
	default:
		throw std::logic_error("Logic error: Invalid data.");
		break;
	}
}

inline Converter::Converter(int A_)
{
	if (A_ < 0 || A_ > 3999)
	{
		throw std::out_of_range("Input error: The number is out of bounds");
	}
	A.val = A_;
	R = ConvertArabToRom(A);
}

inline Converter::~Converter()
{
}

inline arabien Converter::ConvertRomToArab(roman R_)
{
	int Sum = 0;

	int sizeText = R_.val.size();
	std::string inText = R_.val;

	int  const  arab_[] = { 1000, 900, 500, 400,  100,  90,  50,   40,   10,   9,   5,   4,    1 };
	char const* roman_[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

	arabien res;
	res.val = 0;

	for (int i = 0; i < sizeText; i++)
	{
		for (int j = 0; j < countof(roman_); j++)
		{
			if (inText[i] == roman_[j][0])
			{
				if ((inText[i + 1] == roman_[j][1]) && (i != sizeText - 1))
				{
					Sum += arab_[j];
					i++;
					break;
				}
				else
				{
					if ((j % 2 == 0) || j == 12)
					{
						Sum += arab_[j];
						break;
					}
				}
			}
		}
	}
	
	res.val = Sum;

	return res;
}


inline roman Converter::ConvertArabToRom(arabien A_)
{
	int num = A_.val;
	roman res;
	res.val = "";

	int roman_value_list[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	std::string roman_char_list[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

	for (int i = 0; i < countof(roman_value_list); i++)
	{
		while (num >= roman_value_list[i]) 
		{
			num -= roman_value_list[i];
			res.val += roman_char_list[i];
		}
	}

	return res;
}

std::ostream& operator<<(std::ostream& out, const Converter& converter)
{
	out << "Roman - " << converter.R.val << " Arab - " << converter.A.val << "\n";
	return out;
}

inline std::istream& operator>>(std::istream& in, Converter& converter)
{
	std::string inText = "";
	std::cout << "Input number: ";
	in >> inText;

	switch (converter.CheckInput(inText))
	{
	case 0:
		converter.A.val = atoi(inText.c_str());
	 	converter.R = converter.ConvertArabToRom(converter.A);
		break;
	case 1:
		converter.R.val = inText;
		converter.A = converter.ConvertRomToArab(converter.R);
		converter.R = converter.ConvertArabToRom(converter.A);
		break;
	case -1:
		throw std::logic_error("Logic error: Invalid data.");
		break;
	
	default:
		break;
	}

	return in;
}

inline void Converter::OutputConsole()
{
	std::cout << "Roman - " << R.val << " Arab - " << A.val << "\n";
}

inline int Converter::CheckInput(std::string inText)
{
	// 0 - Арабские, 1 - Римские, -1 - Ошибка
	int codeOut = -1;

	for each (int symCode in inText)
	{
		// 0...9
		if (symCode >= 48 && symCode <= 57)
		{
			if (codeOut == 1) { return -1; }
			codeOut = 0;
		}
		else {
			// I V X L C D M
			if (symCode == 73 || symCode == 86 || symCode == 88 || symCode == 76 || symCode == 67 || symCode == 68 || symCode == 77)
			{
				if (codeOut == 0) { return -1; }
				codeOut = 1;
			}
			else
			{
				return -1;
			}
		}
	}
	return codeOut;
}

inline std::string Converter::Get_R_Val()
{
	return R.val;
}

inline int Converter::Get_A_Val()
{
	return A.val;
}
