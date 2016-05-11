#include <iostream>

using std::cout;
using std::endl;

#include "ListMethods.h"

ListMethods::ListMethods() : head(nullptr), nodePtr(nullptr)
{}

ListMethods::~ListMethods()
{
	nodePtr = head;
	ListNode* nextNode = nullptr;

	while (nodePtr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}

void ListMethods::appendNode(string name, double testScore)
{
	ListNode* newNode = new ListNode;
	newNode->name = name;
	newNode->testScore = testScore;
	newNode->next = nullptr;

	nodePtr = head;

	if (!head)
	{
		head = newNode;

	} else
	{
		while (nodePtr->next)
		{
			nodePtr = nodePtr->next;
		}
		nodePtr->next = newNode;
	}
}

void ListMethods::insertNode(string name, double testScore)
{
	ListNode* newNode = new ListNode;
	newNode->testScore = testScore;
	newNode->name = name;

	nodePtr = head;
	ListNode* previousNode = nullptr;

	if (!head)
	{
		head = newNode;
		newNode->next = nullptr;

	} else
	{
		while (nodePtr && nodePtr->testScore < testScore)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (previousNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;

		} else
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

void ListMethods::deleteScoreNode(double testScore)
{
	nodePtr = nullptr;
	ListNode* previousNode = nullptr;

	if (!head)
	{
		return;

	} else if (head->testScore == testScore)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;

	} else
	{
		nodePtr = head;

		while (nodePtr && nodePtr->testScore != testScore)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

void ListMethods::deleteNameNode(string name)
{
	nodePtr = nullptr;
	ListNode* previousNode = nullptr;

	if (!head)
	{
		return;

	} else if (head->name == name)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;

	} else
	{
		nodePtr = head;

		while (nodePtr && nodePtr->name != name)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

void ListMethods::displayList() const
{
	ListNode* nodePtr = head;
	int count = 0;

	cout << endl;

	while (nodePtr)
	{
		cout << "Test Score #" << ++count << "\nName: " << nodePtr->name << "\nScore: " << nodePtr->testScore << "\n" << endl;

		nodePtr = nodePtr->next;
	}
}
