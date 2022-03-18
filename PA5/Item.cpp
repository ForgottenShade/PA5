#include<string>

using namespace std;

class Item {
private:
	string Name;
	int Price;
public:
	Item(string, int);
	Item();

	string GetName();
	int GetPrice();
};

Item::Item(string name, int price) {
	Name = name;
	Price = price;
}

Item::Item(){}

string Item::GetName() {
	return Name;
}

int Item::GetPrice() {
	return Price;
}