#ifndef _ITEM_
#define _ITEM_

#include<string>

using namespace std;

class Item {
private:
	string Name;
	int Price;
	int Quality;		//For generating loot tables
		//1: Common
		//2: Uncommon
		//3: Rare
		//4: Legendary

public:
	Item(string, int, int);
	Item() = default;
	~Item() = default;

	string GetName();
	int GetPrice();
	int GetQuality();
};

#endif