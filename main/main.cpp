#include <stdio.h>
#include "Converter.h"

int main() {
	
	// Input Keyboard
	Converter con;
	std::cin >> con;
	std::cout << con;
	
	std::cout << std::endl;

	// Test CheckInput
	std::cout << "Rules: 0 - Arabien, 1 - Roman, -1 - Error\n";
	std::cout << "350 = " << con.CheckInput("350") << std::endl;
	std::cout << "VIII = " << con.CheckInput("VIII") << std::endl;
	std::cout << "3V = " << con.CheckInput("3V") << std::endl;
	std::cout << "PPC = " << con.CheckInput("PPC") << std::endl;
	std::cout << "CPXII = " << con.CheckInput("CPXII") << std::endl;
	
	std::cout << std::endl;

	Converter con2(5);
	std::cout << con2;

	Converter con22("5");
	std::cout << con22;

	// Testing situation

	Converter con3("XC");
	std::cout << con3;

	Converter con4("II");
	con4.OutputConsole();

	Converter con5("IIV");
	con5.OutputConsole();

	Converter con6("IIIII");
	con6.OutputConsole();

	Converter con7("VVMI");	// MXI 
	con7.OutputConsole();

	Converter con8("MXL");
	con8.OutputConsole();

	Converter con9("MMM");
	con9.OutputConsole();

	Converter con10("CCCXL");
	con10.OutputConsole();

	Converter con11("VXL");	// XLV
	con11.OutputConsole();

	Converter con12("XLV");
	con12.OutputConsole();

	Converter con13("IXIXIXXXIIIM"); // ML
	con13.OutputConsole();

	Converter con14("FFF"); // Error
	con14.OutputConsole();

	std::cout << std::endl;

  return 0;
}