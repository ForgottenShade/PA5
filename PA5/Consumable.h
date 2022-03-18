#ifndef _CONSUMABLE_
#define _CONSUMABLE_

#include<string>
#include"Item.h"

using namespace std;

class Consumable :public Item {
private:
	int Uses;
	int Damage;
	int Healing;
public:
	Consumable(string, int, int, int, int, int);
	Consumable();

	int GetUses();
	int GetDamage();
	int GetHealing();

	string GetName();
	int GetPrice();
	int GetQuality();
};

#endif