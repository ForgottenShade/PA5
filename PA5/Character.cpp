#include<string>
#include<iostream>
#include<map>
#include<vector>
#include<cstring>
#include"Image.h"
#include"Weapon.h"
#include"Armor.h"
#include"Consumable.h"
#include"Clear.h"

using namespace std;

class Character {
private:
	bool Unique;	//Used for determining enemy actions (fleeing)
	bool Alive;		//Used for pc death
	string Race;
	string Name;
	string Art;

	int Str;	//Strength
	int Dex;	//Dexterity
	int Con;	//Constitution
	int Int;	//Intelligence
	int Wis;	//Wisdom
	int Cha;	//Charisma

	//Combat
	int MaxHp;		//Hit Points
	int CurrentHp;
	int AC;			//Armor Class
	int Level;

	Weapon CurrentWeapon;
	Armor CurrentArmor;

	int Adv;	//Advantage to hit
		//0: Disadvantage
		//1: No Advantage
		//2: Advantage

	//Inventory
	int Gold;
	vector<Weapon> Weapons;
	vector<Armor> Armors;
	vector<Consumable> Consumables;
public:
	Character(bool, string, string, string, int, int, int, int, int, int, int, int, int);
	Character(map<string, Image>);
	Character();

	bool IsUnique();
	bool IsAlive();
	string GetName();
	string GetArt();
	int GetStr();
	int GetDex();
	int GetCon();
	int GetInt();
	int GetWis();
	int GetCha();
	int GetCurrentHp();
	int GetMaxHp();
	int GetAC();

	Weapon GetCurrentWeapon();
	Armor GetCurrentArmor();

	int GetAdv();

	int GetCurrentGold();
	vector<Weapon> GetWeaponInv();
	vector<Armor> GetArmorInv();
	vector<Consumable> GetConsumableInv();

	void TakeDamage(int);
	void Heal(int);
	void GiveAdv();
	void GiveDisAdv();
	void ResetAdv();
};

Character::Character(){}

void ChangeStat(string incr_dcrs, int& current_val, int& points) {
	//Add
	if (atoi(incr_dcrs.c_str()) == 1) {
		if (current_val < 13) {
			if (points > 0) {
				current_val++;
				points--;
			}
			else {
				cout << "Not enough points." << endl;
			}
		}
		else if (current_val == 15) {
			cout << "Stat cannot go above 15." << endl;
		}
		else if (points > 1) {
			current_val++;
			points -= 2;
		}
		else {
			cout << "Not enough points." << endl;
		}
	}
	//Decrease
	else if (atoi(incr_dcrs.c_str()) == 2) {
		if (current_val > 13) {
			current_val--;
			points += 2;
		}
		else if (current_val > 8) {
			current_val--;
			points++;
		}
		else {
			cout << "Stat cannot go below 8." << endl;
		}
	}
}

Character::Character(bool unique, string race, string name, string art, int str, int dex, int con, int intelligence, int wis, int cha, int hp, int ac, int level){
	Unique = unique;
	Alive = true;
	Race = race;
	Name = name;
	Art = art;
	Str = str;
	Dex = dex;
	Con = con;
	Int = intelligence;
	Wis = wis;
	Cha = cha;
	MaxHp = hp;
	CurrentHp = hp;
	AC = ac;
	Level = level;
	Adv = 1;
}

//Create the player character
Character::Character(map<string, Image> UIS) {
	string userInput;

	clear();
	cout << "Who are you?" << endl;
	cin >> userInput;
	Name = userInput;

	clear();
	cout << "What is your race?" << endl;
	cin >> userInput;
	Race = userInput;

	int points = 27;
	Str = 8;
	Dex = 8;
	Con = 8;
	Int = 8;
	Wis = 8;
	Cha = 8;

	//Build stat block
	while (true) {
		clear();
		cout << UIS.find("Border.txt")->second.GetImage();
		cout << "You have " << points << "/27 points" << endl;
		cout << "1. Str: " << Str << endl;
		cout << "2. Dex: " << Dex << endl;
		cout << "3. Con: " << Con << endl;
		cout << "4. Int: " << Int << endl;
		cout << "5. Wis: " << Wis << endl;
		cout << "6. Cha: " << Cha << endl;
		cout << "7. Done" << endl;
		cout << UIS.find("Border.txt")->second.GetImage();
		cout << "Each point can be assigned to a stat. Increasing a stat to 14 and 15 costs two points." << endl;
		cout << UIS.find("Border.txt")->second.GetImage();
		cin >> userInput;

		//Strength
		if (strcmp(userInput.c_str(), "1") == 0) {
			clear();
			cout << UIS.find("Border.txt")->second.GetImage();
			cout << "You have " << points << "/27 points" << endl;
			cout << "Current Strength: " << Str << "/15" << endl;
			cout << UIS.find("Border.txt")->second.GetImage();
			cout << "1. Add Strength" << endl;
			cout << "2. Decrease Strength" << endl;
			cout << UIS.find("Border.txt")->second.GetImage();

			cin >> userInput;
			ChangeStat(userInput, Str, points);
		}
		else if (strcmp(userInput.c_str(), "2") == 0) {
			clear();
			cout << UIS.find("Border.txt")->second.GetImage();
			cout << "You have " << points << "/27 points" << endl;
			cout << "Current Dexterity: " << Dex << "/15" << endl;
			cout << UIS.find("Border.txt")->second.GetImage();
			cout << "1. Add Dexterity" << endl;
			cout << "2. Decrease Dexterity" << endl;
			cout << UIS.find("Border.txt")->second.GetImage();

			cin >> userInput;
			ChangeStat(userInput, Dex, points);

		}
		else if (strcmp(userInput.c_str(), "3") == 0) {
			clear();
			cout << UIS.find("Border.txt")->second.GetImage();
			cout << "1. Add Constitution" << endl;
			cout << "2. Decrease Constitution" << endl;
			cout << UIS.find("Border.txt")->second.GetImage();

			cin >> userInput;
			ChangeStat(userInput, Con, points);
		}
		else if (strcmp(userInput.c_str(), "4") == 0) {
			clear();
			cout << UIS.find("Border.txt")->second.GetImage();
			cout << "1. Add Intelligence" << endl;
			cout << "2. Decrease Intelligence" << endl;
			cout << UIS.find("Border.txt")->second.GetImage();

			cin >> userInput;
			ChangeStat(userInput, Int, points);
		}
		else if (strcmp(userInput.c_str(), "5") == 0) {
			clear();
			cout << UIS.find("Border.txt")->second.GetImage();
			cout << "1. Add Wisdom" << endl;
			cout << "2. Decrease Wisdom" << endl;
			cout << UIS.find("Border.txt")->second.GetImage();

			cin >> userInput;
			ChangeStat(userInput, Wis, points);
		}
		else if (strcmp(userInput.c_str(), "6") == 0) {
			clear();
			cout << UIS.find("Border.txt")->second.GetImage();
			cout << "1. Add Charisma" << endl;
			cout << "2. Decrease Charisma" << endl;
			cout << UIS.find("Border.txt")->second.GetImage();

			cin >> userInput;
			ChangeStat(userInput, Cha, points);
		}
		else if (strcmp(userInput.c_str(), "7") == 0) {
			break;
		}

		Unique = false;
		Alive = true;
		AC = 0;	//Set to distinguish the player from autogenerated characters so I don't have to give enemies items
		MaxHp = 10;
		CurrentHp = 10;
		Level = 1;
		Adv = 1;
	}
}

bool Character::IsUnique() {
	return Unique;
}

bool Character::IsAlive() {
	return Alive;
}

string Character::GetName() {
	return Name;
}

string Character::GetArt() {
	return Art;
}

int Character::GetStr() {
	return Str;
}

int Character::GetDex() {
	return Dex;
}

int Character::GetCon() {
	return Con;
}

int Character::GetInt() {
	return Int;
}

int Character::GetWis() {
	return Wis;
}

int Character::GetCha() {
	return Cha;
}

int Character::GetCurrentHp() {
	return CurrentHp;
}

int Character::GetMaxHp() {
	return MaxHp;
}

int Character::GetAC() {
	if (AC == 0) {
		int ac = 10 + Dex + CurrentArmor.GetACBonus();
		if (ac > CurrentArmor.GetBonusCeiling()) {
			return CurrentArmor.GetBonusCeiling();
		}
		else {
			return ac;
		}
	}
	else {
		return AC;
	}
}

Weapon Character::GetCurrentWeapon() {
	return CurrentWeapon;
}

Armor Character::GetCurrentArmor() {
	return CurrentArmor;
}

int Character::GetAdv() {
	return Adv;
}

int Character::GetCurrentGold() {
	return Gold;
}

vector<Weapon> Character::GetWeaponInv() {
	return Weapons;
}

vector<Armor> Character::GetArmorInv() {
	return Armors;
}

vector<Consumable> Character::GetConsumableInv() {
	return Consumables;
}

void Character::TakeDamage(int dmg) {
	if (dmg > CurrentHp) {
		Alive = false;
	}
	else {
		CurrentHp -= dmg;
	}
}

void Character::Heal(int healing) {
	if (healing + CurrentHp > MaxHp) {
		CurrentHp = MaxHp;
	}
	else {
		CurrentHp += healing;
	}
}

void Character::GiveAdv() {
	Adv = 2;
}

void Character::GiveDisAdv() {
	Adv = 0;
}

void Character::ResetAdv() {
	Adv = 1;
}