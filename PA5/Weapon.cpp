
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
	Weapon();

	int GetDamageDice();
	int GetNumberOfDice();
	bool GetDamageStat();

	string GetName();
	int GetPrice();
	int GetQuality();
};

Weapon::Weapon(string name, int price, int quality, int damageDice, int numberOfDice, bool damageStat):Item(name, price, quality) {
	DamageDice = damageDice;
	NumberOfDice = numberOfDice;
	DamageStat = damageStat;
}

Weapon::Weapon():Item(){}

int Weapon::GetDamageDice() {
	return DamageDice;
}

int Weapon::GetNumberOfDice() {
	return NumberOfDice;
}

bool Weapon::GetDamageStat() {
	return DamageStat;
}

string Weapon::GetName() {
	return Item::GetName();
}

int Weapon::GetPrice() {
	return Item::GetPrice();
}

int Weapon::GetQuality() {
	return Item::GetQuality();
}
