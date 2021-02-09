#include <stdio.h>
#include "Converter.h"

int main() {
	Converter con;
	std::cin >> con;
	std::cout << con;

	Converter con2(3);
	std::cout << con2;

	Converter con3("VIII");
	std::cout << con3;

	Converter con4("VVV");
	con4.OutputConsole();

	Converter con5("IIII");
	con5.OutputConsole();

  return 0;
}