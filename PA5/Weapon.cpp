
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

Weapon::Weapon(string name, int price, int quality, int damageDice, int numberOfDice):Item(name, price, quality) {
	DamageDice = damageDice;
	NumberOfDice = numberOfDice;
}

Weapon::Weapon():Item(){}

int Weapon::GetDamageDice() {
	return DamageDice;
}

int Weapon::GetNumberOfDice() {
	return NumberOfDice;
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