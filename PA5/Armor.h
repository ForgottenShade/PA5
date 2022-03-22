#ifndef _ARMOR_
#define _ARMOR_

#include<string>
#include"Item.h"

using namespace std;

class Armor :public Item {
private:
	int ACBonus;
	int BonusCeiling;
	string ArmorType;
public:
	Armor(string, int, int, int, int, string);
	Armor() = default;
	~Armor() = default;

	int GetACBonus();
	int GetBonusCeiling();
	string GetArmorType();

	string Info();
	string GetName();
	int GetPrice();
	int GetQuality();
};

#endif