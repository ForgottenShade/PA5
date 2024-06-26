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
#include"Character.h"

using namespace std;

//Returns the stat bonus or malice for a stat
int Character::GetBonus(int stat) {
	return (stat - 10) / 2;
}

void Character::ChangeStat(string incr_dcrs, int& current_val, int& points) {
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

//Load player from save data
Character::Character(string race, string name, string art_file, int str, int dex, int con, int intelligence, int wis, int cha, int currenthp, int maxhp, int level, int gold, Weapon weapon, Armor armor, vector<Weapon> weapons, vector<Armor> armors, vector<Consumable> consumables, map<string, Image> IMAGES) {
	Unique = false;
	Alive = true;
	Race = race;
	Name = name;
	Art = IMAGES.find(art_file)->second;
	Str = str;
	Dex = dex;
	Con = con;
	Int = intelligence;
	Wis = wis;
	Cha = cha;
	MaxHp = maxhp;
	CurrentHp = currenthp;
	Level = level;
	CurrentWeapon = weapon;
	CurrentArmor = armor;
	Weapons = weapons;
	Armors = armors;
	Consumables = consumables;
	AC = 0;
	Adv = 1;
}

//Create enemy
Character::Character(bool unique, string race, string name, Image art, int str, int dex, int con, int intelligence, int wis, int cha, int hp, int ac, int level){
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
			Character::ChangeStat(userInput, Str, points);
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
			Character::ChangeStat(userInput, Dex, points);

		}
		else if (strcmp(userInput.c_str(), "3") == 0) {
			clear();
			cout << UIS.find("Border.txt")->second.GetImage();
			cout << "You have " << points << "/27 points" << endl;
			cout << "Current Dexterity: " << Con << "/15" << endl;
			cout << UIS.find("Border.txt")->second.GetImage();
			cout << "1. Add Constitution" << endl;
			cout << "2. Decrease Constitution" << endl;
			cout << UIS.find("Border.txt")->second.GetImage();

			cin >> userInput;
			Character::ChangeStat(userInput, Con, points);
		}
		else if (strcmp(userInput.c_str(), "4") == 0) {
			clear();
			cout << UIS.find("Border.txt")->second.GetImage();
			cout << "You have " << points << "/27 points" << endl;
			cout << "Current Dexterity: " << Int << "/15" << endl;
			cout << UIS.find("Border.txt")->second.GetImage();
			cout << "1. Add Intelligence" << endl;
			cout << "2. Decrease Intelligence" << endl;
			cout << UIS.find("Border.txt")->second.GetImage();

			cin >> userInput;
			Character::ChangeStat(userInput, Int, points);
		}
		else if (strcmp(userInput.c_str(), "5") == 0) {
			clear();
			cout << UIS.find("Border.txt")->second.GetImage();
			cout << "You have " << points << "/27 points" << endl;
			cout << "Current Dexterity: " << Wis << "/15" << endl;
			cout << UIS.find("Border.txt")->second.GetImage();
			cout << "1. Add Wisdom" << endl;
			cout << "2. Decrease Wisdom" << endl;
			cout << UIS.find("Border.txt")->second.GetImage();

			cin >> userInput;
			Character::ChangeStat(userInput, Wis, points);
		}
		else if (strcmp(userInput.c_str(), "6") == 0) {
			clear();
			cout << UIS.find("Border.txt")->second.GetImage();
			cout << "You have " << points << "/27 points" << endl;
			cout << "Current Dexterity: " << Cha << "/15" << endl;
			cout << UIS.find("Border.txt")->second.GetImage();
			cout << "1. Add Charisma" << endl;
			cout << "2. Decrease Charisma" << endl;
			cout << UIS.find("Border.txt")->second.GetImage();

			cin >> userInput;
			Character::ChangeStat(userInput, Cha, points);
		}
		else if (strcmp(userInput.c_str(), "7") == 0) {
			break;
		}
	}

	Unique = false;
	Alive = true;
	AC = 0;	//Set to distinguish the player from autogenerated characters so I don't have to give enemies items
	MaxHp = 10 + GetBonus(Con);
	CurrentHp = 10 + GetBonus(Con);
	Level = 1;
	Adv = 1;
	Gold = 0;
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

string Character::GetRace() {
	return Race;
}

string Character::GetArt() {
	return Art.GetImage();
}

string Character::GetArtFilename() {
	return Art.GetFilename();
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
		int ac = 10 + GetBonus(Dex) + CurrentArmor.GetACBonus();
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

int Character::GetLevel() {
	return Level;
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

int Character::GetGold() {
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

//Check if string is number
bool Character::is_number(const string& s)
{
	string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

//Returns true if the enemy is considered at critical health, threshold is 10%
bool Character::IsCriticalHealth() {
	if (CurrentHp < 0.1 * MaxHp) {
		return true;
	}
	return false;
}

//Roll an x sided dice, count times, returns sum of roll(s)
int Character::Roll(int count, int x) {
	srand(time(NULL));
	int roll = 0;
	for (int i = 0; i < count; i++) {
		roll += rand() % x + 1;
	}
	return roll;
}

//Return saving throw for specific stat
int Character::SavingThrow(int stat) {
	int roll = Roll(1, 20);
	int bonus = GetBonus(stat) * 2;
	return roll + bonus;
}

void Character::TakeDamage(int dmg) {
	if (dmg >= CurrentHp) {
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

void Character::PrintCharacterStats(map<string, Image> UIS) {
	clear();
	cout << UIS.find("Border.txt")->second.GetImage();
	cout << "Name: " << Name << "\tHP: " << CurrentHp << "/" << MaxHp << "\tArmor Class: " << GetAC() << "\tLevel: " << Level << "\t" << endl;
	cout << UIS.find("Border.txt")->second.GetImage();
	cout << "Strength: " << Str << endl;
	cout << "Dexterity: " << Dex << endl;
	cout << "Constitution: " << Con << endl;
	cout << "Intelligence: " << Int << endl;
	cout << "Wisdom: " << Wis << endl;
	cout << "Charisma: " << Cha << endl;
	cout << UIS.find("Border.txt")->second.GetImage();
}

void Character::ManageInventory(map<string, Image> UIS) {
	string userInput;

	while (true) {
		PrintCharacterStats(UIS);
		cout << UIS.find("Border.txt")->second.GetImage();
		cout << "1. Manage Weapons \t2. Manage Armors" << endl;
		cout << "3. Show Consumables \t4. Exit" << endl;
		cout << UIS.find("Border.txt")->second.GetImage();
		cin >> userInput;
		clear();

		//Weapons
		if (strcmp(userInput.c_str(), "1") == 0) {
			while (true) {
				cout << UIS.find("Border.txt")->second.GetImage();
				cout << "Select a weapon to equip." << endl;
				cout << "Current Weapon: " << CurrentWeapon.Info() << endl;
				cout << UIS.find("Border.txt")->second.GetImage();
				for (int i = 0; i < Weapons.size(); i++) {
					cout << i + 1 << ". " << Weapons[i].Info() << endl;
				}
				cout << Weapons.size() + 1 << ". Cancel" << endl;
				cout << UIS.find("Border.txt")->second.GetImage();
				cin >> userInput;

				if (is_number(userInput)) {
					int index = atoi(userInput.c_str()) - 1;

					if (index == Weapons.size()) {
						break;
					}

					//Weapon Equipping
					Weapon newCurrent = Weapons[index];
					Weapons.erase(Weapons.begin() + index);
					Weapons.push_back(CurrentWeapon);
					CurrentWeapon = newCurrent;
					break;
				}
			}
		}
		//Armors
		else if (strcmp(userInput.c_str(), "2") == 0) {
			while (true) {
				cout << UIS.find("Border.txt")->second.GetImage();
				cout << "Select an armor to equip." << endl;
				cout << "Current Armor: " << CurrentArmor.Info() << endl;
				cout << UIS.find("Border.txt")->second.GetImage();
				for (int i = 0; i < Armors.size(); i++) {
					cout << i + 1 << ". " << Armors[i].Info() << endl;
				}
				cout << Armors.size() + 1 << ". Cancel" << endl;
				cout << UIS.find("Border.txt")->second.GetImage();
				cin >> userInput;

				if (is_number(userInput)) {
					int index = atoi(userInput.c_str()) - 1;

					if (index == Armors.size()) {
						break;
					}

					//Armor Equipping
					Armor newCurrent = Armors[index];
					Armors.erase(Armors.begin() + index);
					Armors.push_back(CurrentArmor);
					CurrentArmor = newCurrent;
					break;
				}
			}
		}
		//Consumables
		else if (strcmp(userInput.c_str(), "3") == 0) {
			cout << UIS.find("Border.txt")->second.GetImage();
			cout << "ITEMS" << endl;
			cout << UIS.find("Border.txt")->second.GetImage();

			//list all items
			for (int i = 0; i < Consumables.size(); i++) {
				cout << i + 1 << ". " << Consumables[i].CombatInfo() << endl;
			}
			cout << Consumables.size() + 1 << ". Cancel" << endl;
			cout << UIS.find("Border.txt")->second.GetImage();
			cin >> userInput;
		}
		else if (strcmp(userInput.c_str(), "4") == 0) {
			break;
		}
	}
}

void Character::SetWeapon(Weapon weapon) {
	CurrentWeapon = weapon;
}

void Character::SetArmor(Armor armor) {
	CurrentArmor = armor;
}

void Character::StatChange(char effect, string stat) {
	if (effect == '+'){
		if (stat == "Str"){
			Str++;
		} else if (stat == "Dex") {
			Dex++;
		} else if (stat == "Con") {
			Con++;
		} else if (stat == "Int") {
			Int++;
		} else if (stat == "Wis") {
			Wis++;
		} else if (stat == "Cha") {
			Cha++;
		}

	} else if (effect == '-') {
		if (stat == "Str"){
			Str--;
		} else if (stat == "Dex") {
			Dex--;
		} else if (stat == "Con") {
			Con--;
		} else if (stat == "Int") {
			Int--;
		} else if (stat == "Wis") {
			Wis--;
		} else if (stat == "Cha") {
			Cha--;
		}
	}
}

void Character::AddWeaponToInv(Weapon weapon){
	Weapons.push_back(weapon);
}

void Character::AddArmorToInv(Armor armor) {
	Armors.push_back(armor);
}

void Character::AddConsumableToInv(Consumable consumable) {
	Consumables.push_back(consumable);
}

void Character::LevelUp(map<string, Image> UIS) {
	string userInput;
	int currentPoints = 2;

	int initStr = Str;
	int initDex = Dex;
	int initCon = Con;
	int initInt = Int;
	int initWis = Wis;
	int initCha = Cha;

	while (true) {
		clear();
		cout << UIS.find("Border.txt")->second.GetImage();
		cout << "You have leveled up!" << endl;
		cout << "You have " << currentPoints << "/2 to allocate." << endl;
		cout << UIS.find("Border.txt")->second.GetImage();
		cout << "1. Str: " << Str << endl;
		cout << "2. Dex: " << Dex << endl;
		cout << "3. Con: " << Con << endl;
		cout << "4. Int: " << Int << endl;
		cout << "5. Wis: " << Wis << endl;
		cout << "6. Cha: " << Cha << endl;
		cout << "7. Done" << endl;
		cout << UIS.find("Border.txt")->second.GetImage();
		cout << "You may only add to your base stats." << endl;
		cout << UIS.find("Border.txt")->second.GetImage();
		cin >> userInput;

		//Strength
		if (strcmp(userInput.c_str(), "1") == 0) {
			clear();
			cout << UIS.find("Border.txt")->second.GetImage();
			cout << "You have " << currentPoints << "/2 points" << endl;
			cout << "Current Strength: " << Str << endl;
			cout << UIS.find("Border.txt")->second.GetImage();
			cout << "1. Add Strength" << endl;
			cout << "2. Decrease Strength" << endl;
			cout << UIS.find("Border.txt")->second.GetImage();

			cin >> userInput;
			if (strcmp(userInput.c_str(), "1") == 0 && currentPoints > 0) {
				currentPoints -= 1;
				Character::StatChange('+', "Str");
			}
			else if (strcmp(userInput.c_str(), "2") == 0 && currentPoints < 2 && Str > initStr) {
				currentPoints += 1;
				Character::StatChange('-', "Str");
			}
		}
		else if (strcmp(userInput.c_str(), "2") == 0) {
			clear();
			cout << UIS.find("Border.txt")->second.GetImage();
			cout << "You have " << currentPoints << "/2 points" << endl;
			cout << "Current Dexterity: " << Dex << endl;
			cout << UIS.find("Border.txt")->second.GetImage();
			cout << "1. Add Dexterity" << endl;
			cout << "2. Decrease Dexterity" << endl;
			cout << UIS.find("Border.txt")->second.GetImage();

			cin >> userInput;
			if (strcmp(userInput.c_str(), "1") == 0 && currentPoints > 0) {
				currentPoints -= 1;
				Character::StatChange('+', "Dex");
			}
			else if (strcmp(userInput.c_str(), "2") == 0 && currentPoints < 2 && Dex > initDex) {
				currentPoints += 1;
				Character::StatChange('-', "Dex");
			}

		}
		else if (strcmp(userInput.c_str(), "3") == 0) {
			clear();
			cout << UIS.find("Border.txt")->second.GetImage();
			cout << "You have " << currentPoints << "/2 points" << endl;
			cout << "Current Constitution: " << Con << endl;
			cout << UIS.find("Border.txt")->second.GetImage();
			cout << "1. Add Constitution" << endl;
			cout << "2. Decrease Constitution" << endl;
			cout << UIS.find("Border.txt")->second.GetImage();

			cin >> userInput;
			if (strcmp(userInput.c_str(), "1") == 0 && currentPoints > 0) {
				currentPoints -= 1;
				Character::StatChange('+', "Con");
			}
			else if (strcmp(userInput.c_str(), "2") == 0 && currentPoints < 2 && Con > initCon) {
				currentPoints += 1;
				Character::StatChange('-', "Con");
			}
		}
		else if (strcmp(userInput.c_str(), "4") == 0) {
			clear();
			cout << UIS.find("Border.txt")->second.GetImage();
			cout << "You have " << currentPoints << "/2 points" << endl;
			cout << "Current Intelligence: " << Int << endl;
			cout << UIS.find("Border.txt")->second.GetImage();
			cout << "1. Add Intelligence" << endl;
			cout << "2. Decrease Intelligene" << endl;
			cout << UIS.find("Border.txt")->second.GetImage();

			cin >> userInput;
			if (strcmp(userInput.c_str(), "1") == 0 && currentPoints > 0) {
				currentPoints -= 1;
				Character::StatChange('+', "Int");
			}
			else if (strcmp(userInput.c_str(), "2") == 0 && currentPoints < 2 && Int > initInt) {
				currentPoints += 1;
				Character::StatChange('-', "Int");
			}
		}
		else if (strcmp(userInput.c_str(), "5") == 0) {
			clear();
			cout << UIS.find("Border.txt")->second.GetImage();
			cout << "You have " << currentPoints << "/2 points" << endl;
			cout << "Current Wisdom: " << Wis << endl;
			cout << UIS.find("Border.txt")->second.GetImage();
			cout << "1. Add Wisdom" << endl;
			cout << "2. Decrease Wisdom" << endl;
			cout << UIS.find("Border.txt")->second.GetImage();

			cin >> userInput;
			if (strcmp(userInput.c_str(), "1") == 0 && currentPoints > 0) {
				currentPoints -= 1;
				Character::StatChange('+', "Wis");
			}
			else if (strcmp(userInput.c_str(), "2") == 0 && currentPoints < 2 && Wis > initWis) {
				currentPoints += 1;
				Character::StatChange('-', "Wis");
			}
		}
		else if (strcmp(userInput.c_str(), "6") == 0) {
		clear();
		cout << UIS.find("Border.txt")->second.GetImage();
		cout << "You have " << currentPoints << "/2 points" << endl;
		cout << "Current Charisma: " << Cha << endl;
		cout << UIS.find("Border.txt")->second.GetImage();
		cout << "1. Add Charisma" << endl;
		cout << "2. Decrease Charisma" << endl;
		cout << UIS.find("Border.txt")->second.GetImage();

		cin >> userInput;
		if (strcmp(userInput.c_str(), "1") == 0 && currentPoints > 0) {
			currentPoints -= 1;
			Character::StatChange('+', "Cha");
		}
		else if (strcmp(userInput.c_str(), "2") == 0 && currentPoints < 2 && Cha > initCha) {
			currentPoints += 1;
			Character::StatChange('-', "Cha");
		}
		}
		else if (strcmp(userInput.c_str(), "7") == 0) {
			break;
		}
	}

	CurrentHp += 10 + GetBonus(Con);
	MaxHp += 10 + GetBonus(Con);

}