#define BufLength 80
#include "ttext.h"
#include <iostream>
#include <fstream>
#include <cstring>


static char StrBuf[BufLength + 1];
static int TextLevel;

TText::TText(PTTextLink pl) 
{
	if (pl == nullptr) 
		pl = new TTextLink();
	pCurrent = pFirst = pl;
}

// навигация

void TText::GoFirstLink()
{
	while (!Path.empty())
		Path.pop(); //очистка стека
	pCurrent = pFirst;
	if (pCurrent == nullptr)
		throw "Text error";
}

void TText::GoDownLink()
{
	if ((pCurrent != nullptr) && (pCurrent->pDown != nullptr))
	{
		Path.push(pCurrent);
		pCurrent = pCurrent->pDown;
	}
	else
		throw "Text error";
}

void TText::GoNextLink()
{
	if ((pCurrent != nullptr) && (pCurrent->pNext != nullptr))
	{
		Path.push(pCurrent);
		pCurrent = pCurrent->pNext;
	}
	else
		throw "Text error";
}

void TText::GoPrevLink()
{
	if (Path.empty())
		throw "Text no prev";
	else
	{
		pCurrent = Path.top();
		Path.pop();
	}
}

//доступ
std::string TText::GetLine()
{
	if (pCurrent == nullptr)
		return std::string("");
	else 
		return pCurrent->Str;
}

void TText::SetLine(std::string s)
{
	if (pCurrent == nullptr)
	{
		throw std::logic_error("Text error");
	}
	else
	{
		strncpy(pCurrent->Str, s.c_str(), s.size() + 1);
	}
	pCurrent->Str[s.size() ] = '\0';
}

// модификация
void TText::InsDownLine(std::string s)
{
	if (pCurrent == nullptr)
		throw "Text error";
	else
	{
		PTTextLink pd = pCurrent->pDown;
		PTTextLink pl = new TTextLink("", pd, nullptr);
		strncpy(pl->Str, s.c_str(), TextLineLength);
		pl->Str[TextLineLength - 1] = '\0';
		pCurrent->pDown = pl;
	}
}

void TText::InsDownSection(std::string s)
{
	if (pCurrent == nullptr)
		throw "Text error";
	else
	{
		PTTextLink pd = pCurrent->pDown;
		PTTextLink pl = new TTextLink("", nullptr, pd);
		strncpy(pl->Str, s.c_str(), TextLineLength);
		pl->Str[TextLineLength - 1] = '\0';
		pCurrent->pDown = pl;
	}
}

void TText::InsNextLine(std::string s)
{
	if (pCurrent == nullptr)
		throw "Text error";
	else {
		PTTextLink pd = pCurrent->pNext;
		PTTextLink pl = new TTextLink("", pd, nullptr);
		strncpy(pl->Str, s.c_str(), TextLineLength);
		pl->Str[TextLineLength - 1] = '\0';
		pCurrent->pNext = pl;
	}
}

void TText::InsNextSection(std::string s)
{
	if (pCurrent == nullptr)
		throw "Text error";
	else {
		PTTextLink pd = pCurrent->pNext;
		PTTextLink pl = new TTextLink("", nullptr, pd);
		strncpy(pl->Str, s.c_str(), TextLineLength);
		pl->Str[TextLineLength - 1] = '\0';
		pCurrent->pNext = pl;
	}
}

void TText::DelDownLine()
{
	if (pCurrent == nullptr)
		throw "Text error";
	else if(pCurrent->pDown != nullptr)
	{
		PTTextLink pl1 = pCurrent->pDown;
		PTTextLink pl2 = pl1->pNext;
		if (pl1->pDown == nullptr)
			pCurrent->pDown = pl2;
	}
}

void TText::DelDownSection()
{
	if (pCurrent == nullptr)
		throw "Text error";
	else if (pCurrent->pDown != nullptr)
	{
		PTTextLink pl1 = pCurrent->pDown;
		PTTextLink pl2 = pl1->pNext;
		pCurrent->pDown = pl2;
	}
}

void TText::DelNextLine() 
{
	if (pCurrent == nullptr)
		throw "Text error";
	else if (pCurrent->pNext != nullptr)
	{
		PTTextLink pl1 = pCurrent->pNext;
		PTTextLink pl2 = pl1->pNext;
		if (pl1->pNext == nullptr)
			pCurrent->pNext = pl2;
	}
}

void TText::DelNextSection()
{
	if (pCurrent == nullptr)
		throw "Text error";
	else if (pCurrent->pNext != nullptr) {
		PTTextLink pl1 = pCurrent->pNext;
		PTTextLink pl2 = pl1->pNext;
		pCurrent->pNext = pl2;
	}
}

int TText::Reset()
{
	while (!St.empty())
		St.pop();
	pCurrent = pFirst;
	if (pCurrent != nullptr)
	{
		St.push(pCurrent);
		if (pCurrent->pNext != nullptr)
			St.push(pCurrent->pNext);
		if (pCurrent->pDown != nullptr)
			St.push(pCurrent->pDown);
	}
	return IsTextEnded();
}

int TText::IsTextEnded()const
{
	return !St.size();
}

int TText::GoNext()
{
	if (!IsTextEnded())
	{
		pCurrent = St.top();
		St.pop();
		if (pCurrent->pNext != nullptr)
			St.push(pCurrent->pNext);
		if (pCurrent->pDown != nullptr)
			St.push(pCurrent->pDown);
	}
	return IsTextEnded();
}

PTTextLink TText::GetFirstAtom(PTTextLink pl)
{
	PTTextLink tmp = pl;
	while (!tmp->IsAtom())
	{
		St.push(tmp);
		tmp = tmp->GetDown();
	}
	return tmp;
}

PTText TText::GetCopy()
{
	PTTextLink pl1, pl2, pl = pFirst, cpl = nullptr;

	if (pFirst != nullptr)
	{
		while (!St.empty())
			St.pop();
		while (1)
		{
			if (pl != nullptr)
			{
				pl = GetFirstAtom(pl);
				St.push(pl);
				pl = pl->GetDown();
			}
			else if (St.empty())
				break;
			else
			{
				pl1 = St.top(); St.pop();
				if (strstr(pl1->Str, "Copy") == nullptr)
				{
					pl2 = new TTextLink("Copy", pl1, cpl);
					St.push(pl2);
					pl = pl1->pNext;
					cpl = nullptr;
				}
				else 
				{
					pl2 = pl1->GetNext();
					strcpy(pl1->Str, pl2->Str);
					pl1->pNext = cpl;
					cpl = pl1;
				}
			}
		}
	}
	return new TText(cpl);
}

// печать текста
void TText::Print()
{
	TextLevel = 0;
	PrintText(pFirst);
}

void TText::PrintText(PTTextLink ptl)
{
	PTTextLink pl1, pl2, pl = pFirst, cpl = nullptr;


	unsigned int count = 0;
	std::string res[100];

	if (ptl != nullptr)
	{
		while (!St.empty())
		{
			St.pop();
		}
		while (1)
		{
			if (pl != nullptr)
			{		
				for (int space = 0; space < TextLevel; space++)
				{
					res[count] += "  ";
				}
				res[count] += pl->Str;
				count++;
				St.push(pl);
				
				if (pl->GetNext() != nullptr && St.size() > 1)
				{
					pl = pl->GetNext();
					St.push(pl);
				}
				else
				{
					if (pl->GetDown() != nullptr)
					{
						pl = pl->GetDown();
						St.push(pl);
						TextLevel++;
					}
					else
					{
						while (!St.empty())
						{
							pl = St.top(); St.pop();
						}
						if (pl->GetNext() != nullptr)
						{
							pl = pl->GetNext();
							St.push(pl);
							TextLevel = 0;
						}
						else { break; }
					}
				}
			}
		}
	}

	for (int i = 0; i < count; i++)
	{
		std::cout << res[i] << "\n";
	}
}

/*for (int i = 0; i < TextLevel; i++)
		{
			std::cout << "  ";
		}
		
		std::cout << " " << ptl->Str << std::endl;
		++TextLevel; PrintText(ptl->GetDown());
		--TextLevel; PrintText(ptl->GetNext());*/
void TText::workOutputFile(std::ofstream& txt, PTTextLink ptl)
{
	if (ptl != NULL)
	{
		for (int i = 0; i < TextLevel; i++)
		{
			txt << " ";
		}
		txt << ptl->Str << std::endl;
		TextLevel++; workOutputFile(txt, ptl->GetDown());
		TextLevel--; workOutputFile(txt, ptl->GetNext());
	}
}

void TText::Write(char* pFileName)
{
	std::ofstream TxtFile;
	TxtFile.open(pFileName);
	TextLevel = 0;
	workOutputFile(TxtFile, pFirst);
}
