#include "Weapon.h"
#include"Item.h"


Weapon::Weapon(string name, int price, int quality, int damageDice, int numberOfDice, bool damageStat):Item(name, price, quality) {
	DamageDice = damageDice;
	NumberOfDice = numberOfDice;
	DamageStat = damageStat;
}

int Weapon::GetDamageDice() {
	return DamageDice;
}

int Weapon::GetNumberOfDice() {
	return NumberOfDice;
}

bool Weapon::GetDamageStat() {
	return DamageStat;
}

string Weapon::Info() {
	string stat = "None";
	if (DamageStat) {
		stat = "Str";
	}
	else {
		stat = "Dex";
	}

	return Item::GetName() + " (" + to_string(NumberOfDice) + "d" + to_string(DamageDice) + " " + stat + ")";
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
