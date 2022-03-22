#include<string>
#include"Item.h"
#include"Consumable.h"

using namespace std;

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