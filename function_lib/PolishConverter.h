#pragma once
#include "Stack.h"
#include <iostream>
#include <string>
#include <math.h>

template<typename T>
class PolishConverter
{
public:
	PolishConverter();
	~PolishConverter();

	int priorit(char ch);
	int correctInput(char ch);
	double excute_calc(double k1, double k2, char pst);

	void input(std::string inf);

	void AddVar(char ch, int value);

	std::string ConvertToPolish(std::string inf);
	std::string ConvertToPolish();

	double Calculate(std::string pst);
	
	double StrToDouble(std::string str);
	int StrToInt(std::string str);

	void print();
private:
	stack<char> expression;
};

template<typename T>
inline PolishConverter<T>::PolishConverter()
{
}

template<typename T>
inline PolishConverter<T>::~PolishConverter()
{
}

template<typename T>
inline int PolishConverter<T>::correctInput(char ch)
{
	int key = ch;
	if ((key > 64 && key < 91) || (key > 96 && key < 123) ||
		key == 94) {
		return 0;
	} // Встречен Заглавные/прописные/степень

	if (key > 41 && key < 48 && key != 46) { return 10; } // Оператор
	if (key > 47 && key < 58) { return 11; } //Цифра

	switch (key)
	{
		// Круглые
	case 40: return 1;
	case 41: return 2;
		// Фигурные
	case 123: return 3;
	case 125: return 4;
		// Квадратные
	case 91: return 5;
	case 93: return 6;
		// Пробел
	case 32: return 7;
		// Модуль
	case 124: return -2;
		// Точка
	case 46: return 8;
	default:
		return -1;
		break;
	}
}


template<typename T>
inline int PolishConverter<T>::priorit(char ch)
{
	switch (ch)
	{
	case '(': return 0;
	case '{': return 0;
	case '[': return 0;
	
	case ')': return 1;
	case '}': return 1;
	case ']': return 1;

	case '+': return 2;
	case '-': return 2;
	case '*': return 3;
	case '/': return 3;
	case '^': return 4;
	default: return -1;
	}
}   

template<typename T>
inline void PolishConverter<T>::input(std::string inf)
{
	std::string tmp;
	std::string copyInf;
	copyInf = inf;
	int unar;
	int brackets[3] = { 0 };
	for (int i = 0; i < copyInf.size(); i++)
	{
		char ch = copyInf[i];
		int checkSym = correctInput(ch);
		int nextInd = correctInput(copyInf[i + 1]);
		if (checkSym == 1 && nextInd == 10)
		{
			brackets[0]++;
			tmp.append(std::string(1, ch));
			unar = copyInf[i + 2] + '0';
			tmp.append(std::string(1, '1'));
			tmp.append(std::string(1, ' '));
			tmp.append(std::string(1, '/'));
			tmp.append(std::string(1, ' '));
			tmp.append(std::string(1, copyInf[i + 2]));
			i += 2;
			continue;
		}
		switch (checkSym)
		{
		case -1:
			throw std::logic_error("Input error: uncorect symbol");
			break;
		case 0:
			break;
		case 10:
			break;
		case 11:
			break;
		case 1:
			brackets[0]++;
			break;
		case 2:
			brackets[0]--;
			break;
		case 3:
			brackets[1]++;
			break;
		case 4:
			brackets[1]--;
			break;
		case 5:
			brackets[2]++;
			break;
		case 6:
			brackets[2]--;
			break;
		case 7: 
			break;
		case 8:
			break;
		case -2:
			if (nextInd == 11 || nextInd == 7)
			{
				continue;
			}
			if(nextInd == 10)
			{
				i++;
				continue;
			}
			break;
		default:
			throw std::logic_error("Input error: uncorect symbol");
			break; 
		}
		tmp.append(std::string(1, ch));
	}
	
	if (brackets[0] != 0 || brackets[1] != 0 || brackets[2] != 0) { throw std::logic_error("Input error: incorrectly placed brackets"); }


	for (int i = 0; i < tmp.size(); i++)
	{
		expression.push(tmp[i]);
	}

}

template<typename T>
inline void PolishConverter<T>::AddVar(char ch, int value)
{
	char temp;
	char num = value + '0';
	bool isFindVal = false;
	stack<char> copy;
	while (!expression.empty()) {
		copy.push(expression.top());
		expression.pop();
	}
	while (!copy.empty())
	{
		if (copy.top() == ch)
		{
			isFindVal = true;
			expression.push(num);		// Превратить int в char
		}else{ expression.push(copy.top()); }
		temp = copy.top();
		copy.pop();
	}
	if (isFindVal == false) { throw std::logic_error("Logic error: value is not found in expression"); }
}

template<typename T>
inline std::string PolishConverter<T>::ConvertToPolish(std::string inf)
{
	stack<char> stackHelper;
	std::string res = "";
	for (int i = 0; i < inf.size(); i++)
	{
		char ch = inf[i];
		int k = priorit(ch);

		if (k == -1)
			res.append(std::string(1, ch));
		else
			if (stackHelper.empty() || k == 0 || k > priorit(stackHelper.top()))
				stackHelper.push(ch);
			else
			{
				if (ch == ')' || ch == '}' || ch == ']')
					while (true)
					{
						char sym = stackHelper.top();
						stackHelper.pop();
						if (sym != '(' && sym != '{' && sym != '[')
							res.append(std::string(1, sym));
						else
							break;
					}	
				else
				{
					while (!stackHelper.empty())
					{
						char lastStackEl = stackHelper.top();
						stackHelper.pop();
						if (priorit(lastStackEl) >= k)
							res.append(std::string(1, lastStackEl));
					}
					stackHelper.push(ch);
				}
			}
	}
	while (!stackHelper.empty())
	{
		char lastStackEl = stackHelper.top();
		stackHelper.pop();
		if(lastStackEl == '(' || lastStackEl == ')' || lastStackEl == '{' || lastStackEl == '}' || lastStackEl == '[' || lastStackEl == ']') { continue; }
		res.append(std::string(1, lastStackEl));
	}

	return res;
}

template<typename T>
inline std::string PolishConverter<T>::ConvertToPolish()
{
	stack<char> stackHelper;

	std::string copy = "";
	std::string copyCorrect = "";
	int i = 0;
	while (!expression.empty()) {
		copy += expression.top();
		expression.pop();
		i++;
	}
	int size = i;
	while(i != 0){
		expression.push(copy[i - 1]);
		copyCorrect += copy[i - 1];
		i--;
	}

	std::string res = "";
	for (int i = 0; i < size; i++)
	{
		char ch = copyCorrect[i];
		int k = priorit(ch);

		if (k == -1) {
			res.append(std::string(1, ch));
		}
		else
			if (stackHelper.empty() || k == 0 || k > priorit(stackHelper.top()))
				stackHelper.push(ch);
			else
			{
				
				if (ch == ')' || ch == '}' || ch == ']')
					while (true)
					{
						char sym = stackHelper.top();
						stackHelper.pop();
						if (sym != '(' && sym != '{' && sym != '[')
							res.append(std::string(1, sym));
						else
							break;
					}
				else
				{
					while (!stackHelper.empty())
					{
						char lastStackEl = stackHelper.top();
						stackHelper.pop();
						if (priorit(lastStackEl) >= k)
							res.append(std::string(1, lastStackEl));
					}
					stackHelper.push(ch);
				}
			}
	}
	while (!stackHelper.empty())
	{
		char lastStackEl = stackHelper.top();
		stackHelper.pop();
		if (lastStackEl == '(' || lastStackEl == ')' || lastStackEl == '{' || lastStackEl == '}' || lastStackEl == '[' || lastStackEl == ']') { continue; }
		res.append(std::string(1, lastStackEl));
	}

	return res;
}

template<typename T>
inline double PolishConverter<T>::Calculate(std::string pst)
{
	stack<double> stack2;
	for (int i = 0; i < pst.size(); i++)
	{
		std::string correctNum;
		char ch = pst[i];
		char longNum[10] = "";
		int priority = correctInput(ch);
		int nextPriority = correctInput(pst[i + 1]);

		if (priority == 7) { continue; }
		else {
			if (priority == 11 && nextPriority == 11)
			{
				bool isDouble = false;
				int j = i;
				int p = 0;
				while (correctInput(pst[j]) != 10 || correctInput(pst[j]) != 7)
				{
					if (correctInput(pst[j] == 8)) { isDouble = true; }
					if (correctInput(pst[j]) == 10) { break; }
					if (correctInput(pst[j]) == 7) { break; }
					longNum[p] = pst[j];
					p++; j++;
				}
				for (int g = 0; g < p; g++) { correctNum += longNum[g]; }
				i += p - 1;
				if(isDouble){ stack2.push(StrToDouble(correctNum)); }
				else{ stack2.push(StrToInt(correctNum)); }
			}
			else {
				if (priority == 11 && nextPriority != 8)
				{
					stack2.push(ch - 48);
				}
				else {
					if (priority == 11 && nextPriority == 8)
					{
						int j = i;
						int p = 0;
						while (correctInput(pst[j]) != 10 || correctInput(pst[j]) != 7)
						{
							if (correctInput(pst[j]) == 10) { break; }
							if (correctInput(pst[j]) == 7) { break; }
							longNum[p] = pst[j];
							p++; j++;
						}
						for (int g = 0; g < p; g++) { correctNum += longNum[g]; }
						i += p - 1;
						stack2.push(StrToDouble(correctNum));
					}
					else
					{
						double k1 = stack2.top();
						stack2.pop();

						double k2 = stack2.top();
						stack2.pop();

						double res = excute_calc(k2, k1, ch);
						stack2.push(res);
					}
				}
			}
		}

	}
	return stack2.top();
}

template<typename T>
inline double PolishConverter<T>::StrToDouble(std::string str)
{
	double res = std::stod(str);
	return res;
}

template<typename T>
inline int PolishConverter<T>::StrToInt(std::string str)
{
	return stoi(str);
}

template<typename T>
inline double PolishConverter<T>::excute_calc(double k1, double k2, char pst)
{
	switch (pst)
	{
	case '+': return k1 + k2;
	case '-': return k1 - k2;
	case '*': return k1 * k2;
	case '/': return k1 / k2;
	case '^': return pow(k1,k2);
	default: return -1;
	}
}

template<typename T>
inline void PolishConverter<T>::print()
{
	char temp ;
	stack<char> copy;
	while (!expression.empty()) {
		copy.push(expression.top());
		expression.pop();
	}
	while (!copy.empty())
	{
		expression.push(copy.top());
		temp = copy.top();
		copy.pop();
		std::cout << temp;
	}
}
