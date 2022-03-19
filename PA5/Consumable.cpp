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

	string CombatInfo();
	void SetUses(int);
};

Consumable::Consumable(string name, int price, int quality, int uses, int damage, int healing) :Item(name, price, quality) {
	Uses = uses;
	Damage = damage;
	Healing = healing;
}

Consumable::Consumable():Item(){}

int Consumable::GetUses() {
	return Uses;
}

int Consumable::GetDamage() {
	return Damage;
}

int Consumable::GetHealing() {
	return Healing;
}

string Consumable::GetName() {
	return Item::GetName();
}

int Consumable::GetPrice() {
	return Item::GetPrice();
}

int Consumable::GetQuality() {
	return Item::GetQuality();
}

string Consumable::CombatInfo() {
	return Item::GetName() + "\t(Uses: " + to_string(Uses) + " Healing: " + to_string(Healing) + " Damage: " + to_string(Damage) + ")";
}

void Consumable::SetUses(int uses) {
	Uses = uses;
}