#include "Weapon.h"
#include"Item.h"


Weapon::Weapon(string name, int price, int quality, int damageDice, int numberOfDice, bool damageStat):Item(name, price, quality) {
	DamageDice = damageDice;
	NumberOfDice = numberOfDice;
	DamageStat = damageStat;
}

Weapon::Weapon():Item(){}
Weapon::~Weapon(){}

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
