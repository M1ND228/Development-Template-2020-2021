#include <locale>
#include "monom.h"
#include "polinom.h"

void Menu(Polinom& p1, Polinom& p2, Polinom& res)
{
	std::cout << "p1 = " << p1.to_str() << std::endl;
	std::cout << "p2 = " << p2.to_str() << std::endl;
	std::cout << "res = " << res.to_str() << std::endl << std::endl;
	std::cout << "1) ������� ��������" << std::endl;
	std::cout << "2) ������� ��������" << std::endl;
	std::cout << "3) ����������� ��������" << std::endl;
	std::cout << "4) ��������� ���������" << std::endl;
	std::cout << "5) ������ ����� ��������" << std::endl << std::endl;
	std::cout << "0) �����" << std::endl;
	std::cout << "> ";
}
void calculate_polinom(Polinom& res)
{
	int x, y, z;
	std::cout << "������� a: ";
	std::cin >> x;
	std::cout << "������� b: ";
	std::cin >> y;
	std::cout << "������� c: ";
	std::cin >> z;
	std::cout << res.to_str() << " = " << res.Resault(x, y, z) << std::endl;
}
void input_monom(Monom& m)
{
	int A, B, C, coef;
	std::cout << "���������: ";
	std::cin >> coef;
	std::cout << "������� A: ";
	std::cin >> A;
	std::cout << "������� B: ";
	std::cin >> B;
	std::cout << "������� C: ";
	std::cin >> C;
	Monom monom(coef, A, B, C);
	m = monom;
}

void input_polinom(Polinom& p)
{
	Monom m;

	int num_of_monoms;
	std::cout << "���������� �������: ";
	std::cin >> num_of_monoms;
	for (int i = 0; i < num_of_monoms; i++)
	{
		std::cout << "������� ����� " << i + 1 << std::endl;
		input_monom(m);
		p += m;
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	Polinom p1;
	Polinom p2;
	Polinom res;
	int menuSelection = 0;
	std::cout << "������� p1 � p2:\n";
	input_polinom(p1);
	input_polinom(p2);
	while (true)
	{
		system("cls");
		Menu(p1, p2, res);
		std::cin >> menuSelection;
		switch (menuSelection)
		{
		case 1:
			res = p1 + p2;
			std::cout << p1.to_str() << "  +  " << p2.to_str() << " = " << res.to_str() << std::endl;
			system("pause");
			break;
		case 2:
			res = p1 - p2;
			std::cout << p1.to_str() << "  -  " << p2.to_str() << " = " << res.to_str() << std::endl;
			system("pause");
			break;
		case 3:
			res = p1 * p2;
			std::cout << p1.to_str() << "  *  " << p2.to_str() << " = " << res.to_str() << std::endl;
			system("pause");
			break;
		case 4:
			calculate_polinom(res);
			system("pause");
			break;
		case 5:
			system("cls");
			std::cout << "������� p1 � p2:\n";
			p1.DeletPolinom();
			p2.DeletPolinom();
			res.DeletPolinom();
			input_polinom(p1);
			input_polinom(p2);
			break;
		case 0:
			return 0;
		}

	}
	return 0;
}