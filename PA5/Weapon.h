#ifndef _WEAPON_
#define _WEAPON_

#include"Item.h"

class Weapon :public Item {
private:
	int DamageDice;
	int NumberOfDice;
	bool DamageStat;
		//true: Str
		//false: Dex
public:
	Weapon(string, int, int, int, int, bool);
	Weapon() = default;
	~Weapon() = default;

	int GetDamageDice();
	int GetNumberOfDice();
	bool GetDamageStat();

	string Info();
	string GetName();
	int GetPrice();
	int GetQuality();
};

#endif