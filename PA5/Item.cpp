#include<string>
#include"Item.h"

using namespace std;

Item::Item(string name, int price, int quality) {
	Name = name;
	Price = price;
	Quality = quality;
}

Item::Item(){}
Item::~Item(){}

string Item::GetName() {
	return Name;
}

int Item::GetPrice() {
	return Price;
}

int Item::GetQuality() {
	return Quality;
}