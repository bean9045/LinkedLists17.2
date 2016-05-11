#ifndef LISTMETHODS_H_
#define LISTMETHODS_H_

#include <iostream>

using std::string;

class ListMethods
{
  friend class SortMethods;

  private:
	struct ListNode
	{
		string name;
		double testScore;

		ListNode* next;
	};

  private:
	ListNode* head;
	ListNode* nodePtr;

  public:
	ListMethods();
	~ListMethods();

	void appendNode(string name, double testScore);
	void insertNode(string name, double testScore);
	void deleteScoreNode(double testScore);
	void deleteNameNode(string name);
	void displayList() const;
};

#endif
