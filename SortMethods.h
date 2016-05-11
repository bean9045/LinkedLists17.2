#ifndef SORTMETHODS_H_
#define SORTMETHODS_H_

#include "ListMethods.h"

class ListMethods;

class SortMethods
{
  private:
	ListMethods* listMethodsPtr;

  public:
	SortMethods();
	~SortMethods();

	void sortListDec();
	void sortListAcc();
	void sortListAlpha();

	ListMethods* getListMethodsPtr();
};

#endif
