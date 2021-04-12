#pragma once

#include <stack>
#include <iostream>
#include <fstream>
#include <string>
#include "defines.h"
#include "textlink.h"


class TText
{
protected: 
	PTTextLink pFirst;
	PTTextLink pCurrent;
	std::stack<PTTextLink> Path; //стек траекториии движения по тексту
	// pCurrent в стек не включается

	std::stack<PTTextLink> St;
	PTTextLink GetFirstAtom(PTTextLink pl);
	void PrintText(PTTextLink ptl);
	PTTextLink ReadText(std::ifstream &TxtFile);

public:
	TText(PTTextLink pl = nullptr);
    ~TText() { pFirst = nullptr; }

	PTText GetCopy();	// копирование текста

	// навигация
	void GoFirstLink(void); // переход к первой строке
	void GoDownLink(void);  // переход к следующей строке по Down
	void GoNextLink(void);  // переход к следующей строке по Next
	void GoPrevLink(void);  // переход к предыдущей позиции в тексте
	
	// доступ
	std:: string GetLine(void);		// чтение текущей строки
	void SetLine(std::string s);			// замена текущей строки 
	
	// модификация
	void InsDownLine(std::string s);    // вставка строки в подуровень
	void InsDownSection(std::string s); // вставка раздела в подуровень
	void InsNextLine(std::string s);    // вставка строки в том же уровне
	void InsNextSection(std::string s); // вставка раздела в том же уровне

	void DelDownLine(void);        // удаление строки в подуровне
	void DelDownSection(void);     // удаление раздела в подуровне
	void DelNextLine(void);        // удаление строки в том же уровне
	void DelNextSection(void);     // удаление раздела в том же уровне

	//итератор
	int Reset(); // установить на первую запись
	int IsTextEnded()const; //таблица завершена?
	int GoNext(); // переход к следующей записи

	//работа с файлами
	void Read(const char *pFileName); // ввод текста из файла
	void Write(char *pFileName);// вывод текста в файл

	// печать
	void Print();

	void wr(std::ofstream& txt, PTTextLink ptl);
};

