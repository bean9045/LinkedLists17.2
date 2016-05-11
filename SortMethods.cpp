#include <iostream>

using std::string;

#include "SortMethods.h"
#include "ListMethods.h"

SortMethods::SortMethods() : listMethodsPtr(new ListMethods)
{}

SortMethods::~SortMethods()
{
	delete listMethodsPtr;
}

void SortMethods::sortListDec()
{
	listMethodsPtr->nodePtr = nullptr;

	bool swapping;
	double tempScore;
	string tempName;

	if (!listMethodsPtr->head)
	{
		return;
	}

	do
	{
		listMethodsPtr->nodePtr = listMethodsPtr->head;
		swapping = false;

		while (listMethodsPtr->nodePtr->next)
		{
			if (listMethodsPtr->nodePtr->testScore < listMethodsPtr->nodePtr->next->testScore)
			{
				tempScore = listMethodsPtr->nodePtr->testScore;
				listMethodsPtr->nodePtr->testScore = listMethodsPtr->nodePtr->next->testScore;
				listMethodsPtr->nodePtr->next->testScore = tempScore;

				tempName = listMethodsPtr->nodePtr->name;
				listMethodsPtr->nodePtr->name = listMethodsPtr->nodePtr->next->name;
				listMethodsPtr->nodePtr->next->name = tempName;

				listMethodsPtr->nodePtr = listMethodsPtr->nodePtr->next;
				swapping = true;

			} else
			{
				listMethodsPtr->nodePtr = listMethodsPtr->nodePtr->next;
			}
		}
	} while (swapping);
}

void SortMethods::sortListAcc()
{
	listMethodsPtr->nodePtr = nullptr;

	bool swapping;
	double tempScore;
	string tempName;

	if (!listMethodsPtr->head)
	{
		return;
	}

	do
	{
		listMethodsPtr->nodePtr = listMethodsPtr->head;
		swapping = false;

		while (listMethodsPtr->nodePtr->next)
		{
			if (listMethodsPtr->nodePtr->testScore > listMethodsPtr->nodePtr->next->testScore)
			{
				tempScore = listMethodsPtr->nodePtr->testScore;
				listMethodsPtr->nodePtr->testScore = listMethodsPtr->nodePtr->next->testScore;
				listMethodsPtr->nodePtr->next->testScore = tempScore;

				tempName = listMethodsPtr->nodePtr->name;
				listMethodsPtr->nodePtr->name = listMethodsPtr->nodePtr->next->name;
				listMethodsPtr->nodePtr->next->name = tempName;

				listMethodsPtr->nodePtr = listMethodsPtr->nodePtr->next;
				swapping = true;

			} else
			{
				listMethodsPtr->nodePtr = listMethodsPtr->nodePtr->next;
			}
		}
	} while (swapping);
}

void SortMethods::sortListAlpha()
{
	listMethodsPtr->nodePtr = nullptr;

	bool swapping;
	string name;
	string nextName;
	string tempName;
	double tempScore;

	if (!listMethodsPtr->head)
	{
		return;
	}

	do
	{
		listMethodsPtr->nodePtr = listMethodsPtr->head;
		swapping = false;

		while (listMethodsPtr->nodePtr->next)
		{
			name = listMethodsPtr->nodePtr->name;

			for (unsigned int i = 0; i < name.length(); i++)
			{
				name[i] = toupper(name[i]);
			}

			nextName = listMethodsPtr->nodePtr->next->name;

			for (unsigned int i = 0; i < nextName.length(); i++)
			{
				nextName[i] = toupper(nextName[i]);
			}

			if (name > nextName)
			{
				tempName = listMethodsPtr->nodePtr->name;
				listMethodsPtr->nodePtr->name = listMethodsPtr->nodePtr->next->name;
				listMethodsPtr->nodePtr->next->name = tempName;

				tempScore = listMethodsPtr->nodePtr->testScore;
				listMethodsPtr->nodePtr->testScore = listMethodsPtr->nodePtr->next->testScore;
				listMethodsPtr->nodePtr->next->testScore = tempScore;

				listMethodsPtr->nodePtr = listMethodsPtr->nodePtr->next;
				swapping = true;

			} else
			{
				listMethodsPtr->nodePtr = listMethodsPtr->nodePtr->next;
			}
		}
	} while (swapping);
}

ListMethods* SortMethods::getListMethodsPtr()
{
	return listMethodsPtr;
}
