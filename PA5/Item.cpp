#include<string>

using namespace std;

class Item {
private:
	string Name;
	int Price;
	int Quality;		//For generating loot tables
		//1: Common
		//2: Uncommon
		//3: Rare
		//4: Legendary
public:
	Item(string, int, int);
	Item();

	string GetName();
	int GetPrice();
	int GetQuality();
};

Item::Item(string name, int price, int quality) {
	Name = name;
	Price = price;
	Quality = quality;
}

Item::Item(){}

string Item::GetName() {
	return Name;
}

int Item::GetPrice() {
	return Price;
}

int Item::GetQuality() {
	return Quality;
}