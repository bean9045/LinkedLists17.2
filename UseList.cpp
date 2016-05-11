#include <iostream>

using std::cout;
using std::flush;
using std::endl;
using std::cin;
using std::string;
using std::getline;

#include <cctype>

using std::isalpha;

#include <string.h>

using std::stod;

#include "UseList.h"

UseList::UseList() : sortMethodsPtr(new SortMethods)
{
}

UseList::~UseList()
{
	delete sortMethodsPtr;
}

void UseList::showOptions()
{
	int answer;
	cout << "Press \"1\" to add a new test score.\n"
		 << "Press \"2\" to delete a test score.\n"
		 << "Press \"3\" to sort the test scores from highest to lowest.\n"
		 << "Press \"4\" to sort the test scores from lowest to highest.\n"
		 << "Press \"5\" to sort the test scores alphabetically by name.\n"
		 << "Press \"6\" to display the test scores.\n"
		 << "Press \"7\" to exit. " << endl;

	bool wantsExit;

	do
	{
		bool invalid;

		do
		{
			cout << "To see the options again press \"8\", otherwise select your option by pressing \"1\" through \"7\": " << flush;
			cin >> answer;

			invalid = cin.fail();
			cin.clear();
			cin.ignore(10000, '\n');

		} while (invalid);

		wantsExit = false;

		switch (answer)
		{
			case 1:
			{
				string name;
				cout << "Please enter the name of the student: " << flush;
				getline(cin, name);

				double testScore;
				cout << "Please enter the test score: " << flush;
				cin >> testScore;

				sortMethodsPtr->getListMethodsPtr()->appendNode(name, testScore);

				cout << "Test score entered.\n" << endl;
			}
			break;

			case 2:
			{
				string uInput;
				cout << "Enter the name or score you'd like to delete: " << flush;
				getline(cin, uInput);

				if (isalpha(uInput[0]))
				{
					sortMethodsPtr->getListMethodsPtr()->deleteNameNode(uInput);

				} else
				{
					sortMethodsPtr->getListMethodsPtr()->deleteScoreNode(stod(uInput));
				}

				sortMethodsPtr->getListMethodsPtr()->displayList();
			}
			break;

			case 3:
			{
				sortMethodsPtr->sortListDec();
				sortMethodsPtr->getListMethodsPtr()->displayList();
			}
			break;

			case 4:
			{
				sortMethodsPtr->sortListAcc();
				sortMethodsPtr->getListMethodsPtr()->displayList();
			}
			break;

			case 5:
			{
				sortMethodsPtr->sortListAlpha();
				sortMethodsPtr->getListMethodsPtr()->displayList();
			}
			break;

			case 6:
			{
				sortMethodsPtr->getListMethodsPtr()->displayList();
			}
			break;

			case 7:
			{
				wantsExit = true;
			}
			break;

			case 8:
			{
				cout << "Press \"1\" to add a new test score.\n"
					 << "Press \"2\" to delete a test score by student name.\n"
					 << "Press \"3\" to sort the test scores from highest to lowest.\n"
					 << "Press \"4\" to sort the test scores from lowest to highest.\n"
					 << "Press \"5\" to sort the test scores alphabetically by name.\n"
					 << "Press \"6\" to display the test scores.\n"
					 << "Press \"7\" to exit. " << endl;
			}
			break;

			default: cin.ignore(100, '\n');
					 cin.clear();
					 cout << "Invalid input, please enter a number between \"1\" and \"8\": " << flush;
					 break;
		}
	} while (!wantsExit);
}
