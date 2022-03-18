#ifndef _WEAPON_
#define _WEAPON_

#include"Item.h"

class Weapon :public Item {
private:
	int DamageDice;
	int NumberOfDice;
public:
	Weapon(string, int, int, int, int);
	Weapon();

	int GetDamageDice();
	int GetNumberOfDice();

	string GetName();
	int GetPrice();
	int GetQuality();
};

#endif