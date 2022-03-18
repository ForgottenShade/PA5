#ifndef _ITEM_
#define _ITEM_

#include<string>

using namespace std;

class Item {
private:
	string Name;
	int Price;
public:
	Item(string, int);
	Item();

	string GetName();
	int GetPrice();
};

#endif