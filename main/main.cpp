#include <iostream>
#include <string>
#include "PolishConverter.h"

int main()
{
	PolishConverter<char> ex;
	std::string abc = "(5 + 5) ^ 2";                  
	double res;

	ex.input(abc);
	ex.print();
	std::cout << "\n";

	abc = ex.ConvertToPolish();
	std::cout << "\n" << abc << "\n";

	res = ex.Calculate(abc);
	std::cout << "\n";
	
	std::cout << res;
	std::cout << "\n";
	
	system("pause");
	return 0;
}