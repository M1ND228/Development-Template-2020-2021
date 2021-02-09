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

	friend std::ostream& operator<< (std::ostream& out, const Converter& converter);
	friend std::istream& operator>> (std::istream& in, Converter& converter);

	void OutputConsole();
	
	std::string Get_R_Val();
	int			Get_A_Val();

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
	R.val = R_;
	A = ConvertRomToArab(R);
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
	int const  arab_[] = { 1,   4,    5,   9,    10,  40,  50,   90,  100, 400,  500, 900,  1000 };
	char const* roman_[] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };

	std::string num = R.val;

	const int m = countof(arab_) - 1;
	int arab = 0;
	int len = num.length(), n = m, i = 0, pir;

	while (n >= 0 && i < len)
	{
		pir = n & 1;
		if ((num[i] == roman_[n][0]) && (!pir || num[i + 1] == roman_[n][1]))
		{
			arab += arab_[n];
			i += 1 + pir;
		}
		else n--;
	}

	arabien res;
	res.val = arab;
	R = ConvertArabToRom(res);
	
	return res;
}


inline roman Converter::ConvertArabToRom(arabien A_)
{
	int num = A_.val;
	roman res;

	int roman_value_list[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	std::string roman_char_list[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

	for (int i = 0; i < 13; i++) 
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
	std::cout << "Input roman: ";
	in >> converter.R.val;
	std::cout << "Input arab: ";
	in >> converter.A.val;

	return in;
}

inline void Converter::OutputConsole()
{
	std::cout << "Roman - " << R.val << " Arab - " << A.val << "\n";
}

inline std::string Converter::Get_R_Val()
{
	return R.val;
}

inline int Converter::Get_A_Val()
{
	return A.val;
}
