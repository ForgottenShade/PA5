#include<string>
#include"Item.h"
#include"Armor.h"

using namespace std;

Armor::Armor(string name, int price, int quality, int acBonus, int bonusCeiling, string armorType) :Item(name, price, quality) {
	ACBonus = acBonus;
	BonusCeiling = bonusCeiling;
	ArmorType = armorType;
}

Armor::Armor():Item(){}
Armor::~Armor(){}

int Armor::GetACBonus(){
	return ACBonus;
}

int Armor::GetBonusCeiling() {
	return BonusCeiling;
}

string Armor::GetArmorType() {
	return ArmorType;
}

string Armor::GetName() {
	return Item::GetName();
}

int Armor::GetPrice() {
	return Item::GetPrice();
}

int Armor::GetQuality() {
	return Item::GetQuality();
}