#ifndef USELIST_H_
#define USELIST_H_

#include "SortMethods.h"

class UseList
{
  private:
	SortMethods* sortMethodsPtr;

  public:
	UseList();
	~UseList();

	void showOptions();
};

#endif
