#include<string>
#include"Item.h"

using namespace std;

class Armor:public Item {
private:
	int ACBonus;
	int BonusCeiling;
	string ArmorType;
public:
	Armor(string, int, int, int, int, string);
	Armor();

	int GetACBonus();
	int GetBonusCeiling();
	string GetArmorType();

	string GetName();
	int GetPrice();
	int GetQuality();
};

Armor::Armor(string name, int price, int quality, int acBonus, int bonusCeiling, string armorType) :Item(name, price, quality) {
	ACBonus = acBonus;
	BonusCeiling = bonusCeiling;
	ArmorType = armorType;
}

Armor::Armor():Item(){}

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