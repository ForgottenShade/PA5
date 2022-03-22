#include<string>
#include<map>
#include<iostream>
#include<random>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
#include<cstring>
#include<chrono>
#include<vector>

#include"Image.h"
#include"Weapon.h"
#include"Armor.h"
#include"Character.h"
#include"Clear.h"
#include"Encounter.h"
//Time used for random seed generation to ensure non-deterministic behavior
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::system_clock;
using namespace std;



//Check if string is number
bool Encounter::is_number(const string& s)
{
	string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

//Returns the stat bonus or malice for a stat
int Encounter::GetBonus(int stat) {
	return (stat - 10) / 2;
}

//Returns true if the enemy is considered at critical health, threshold is 10%
bool Encounter::IsCriticalHealth(Character x) {
	if (x.GetCurrentHp() < 0.1 * x.GetMaxHp()) {
		return true;
	}
	return false;
}

//Roll an x sided dice, count times, returns sum of roll(s)
int Encounter::Roll(int count, int x) {
	srand(time(NULL));
	int roll = 0;
	for (int i = 0; i < count; i++) {
		roll += rand() % x;
	}
	return roll;
}

//Return saving throw for specific stat
int Encounter::SavingThrow(int stat) {
	int roll = Roll(1, 20);
	int bonus = GetBonus(stat) * 2;
	return roll + bonus;
}

//Character a attacks character b, returns damage to b
int Encounter::Attack(Character a, Character b) {
	Weapon attackerWeapon = a.GetCurrentWeapon();
	int defenderAC = b.GetAC();
	int adv = a.GetAdv();
	int dmg = 0;

	//true: Str
	if (attackerWeapon.GetDamageStat()) {
		int roll = Roll(1, 20) + GetBonus(a.GetStr());

		//handle advantage/disadvantage
		if (adv == 0) {
			int roll2 = Roll(1, 20) + GetBonus(a.GetStr());
			roll = min(roll, roll2);
		}
		else if (adv == 2) {
			int roll2 = Roll(1, 20) + GetBonus(a.GetStr());
			roll = max(roll, roll2);
		}
		
		//check if hit
		if (roll > defenderAC) {
			dmg = Roll(attackerWeapon.GetNumberOfDice(), attackerWeapon.GetDamageDice());
		}
	}
	//false: Dex
	else 
	{
		int roll = Roll(1, 20) + GetBonus(a.GetDex());

		//handle advantage/disadvantage
		if (adv == 0) {
			int roll2 = Roll(1, 20) + GetBonus(a.GetStr());
			roll = min(roll, roll2);
		}
		else if (adv == 2) {
			int roll2 = Roll(1, 20) + GetBonus(a.GetStr());
			roll = max(roll, roll2);
		}

		//check if hit
		if (roll > defenderAC) {
			dmg = Roll(attackerWeapon.GetNumberOfDice(), attackerWeapon.GetDamageDice());
		}
	}

	//reset advantage
	a.ResetAdv();

	return dmg;
}

//Character a uses item c (healing applied to self, damage to character b, handle uses)
void Encounter::UseItem(Character a, Character b, Consumable c) {
	a.Heal(c.GetHealing());
	b.TakeDamage(c.GetDamage());
	c.SetUses(c.GetUses() - 1);
}

void Encounter::CombatItemMenu(Character a, Character b, map<string, Image> UIS) {
	vector<Consumable> items = a.GetConsumableInv();
	string userInput;

	while (true) {
		clear();
		cout << UIS.find("Border.txt")->second.GetImage();
		cout << "ITEMS" << endl;
		cout << UIS.find("Border.txt")->second.GetImage();

		//list all items
		for (int i = 0; i < items.size(); i++) {
			cout << i + 1 << ". " << items[i].CombatInfo() << endl;
		}
		cout << UIS.find("Border.txt")->second.GetImage();

		cin >> userInput;

		if (is_number(userInput)) {
			int index = atoi(userInput.c_str());
			Consumable item = items[index];
			UseItem(a, b, item);

			//Remove from inventory if uses == 0
			if (item.GetUses() == 0) {
				items.erase(items.begin() + index);
			}
			break;
		}
	}
}

//Returns true if character a succeeds in fleeing from character b, otherwise false
//This is a Dex roll vs the Dex saving throw of the opponent
bool Encounter::Flee(Character a, Character b) {
	int rollA = Roll(1, 20) + GetBonus(a.GetDex());
	int rollB = SavingThrow(b.GetDex());

	if (rollA > rollB) {
		return true;
	}
	return false;
}

Encounter::~Encounter(){}

//1v1
Encounter::Encounter(Character& pc, Character& enemy, map<string, Image> IMAGES, map<string, Image> UIS) {
	PC = pc;
	Enemy = enemy;
	string userInput;

	while (true) {
		//Player Turn
		clear();
		enemy.GetArt();
		cout << UIS.find("Border.txt")->second.GetImage();
		cout << enemy.GetName() << "\tHealth: " << enemy.GetCurrentHp() << "/" << enemy.GetMaxHp() << "\tArmor Class: " << enemy.GetAC() << endl;
		cout << UIS.find("Border.txt")->second.GetImage();
		cout << UIS.find("CombatMenu.txt")->second.GetImage();
		cout << UIS.find("Border.txt")->second.GetImage();
		cout << pc.GetName() << "\tHealth: " << pc.GetCurrentHp() << "/" << pc.GetMaxHp() << "\tArmor Class: " << pc.GetAC() << endl;
		cout << UIS.find("Border.txt")->second.GetImage();
		cin >> userInput;

			//Attack
		if (strcmp(userInput.c_str(), "1") == 0) {
			int dmg = Attack(pc, enemy);

				//Handle miss
			if (dmg == 0) {
				cout << "You missed!" << endl;
			}
			else {
				cout << "You deal " << dmg << " damage!" << endl;
				enemy.TakeDamage(dmg);
			}
		}
			//Defend
		else if (strcmp(userInput.c_str(), "2") == 0) {
			cout << "You stand ready for the next attack." << endl;
			enemy.GiveDisAdv();
		}
			//Use Item
		else if (strcmp(userInput.c_str(), "3") == 0) {
			CombatItemMenu(pc, enemy, UIS);
		}
			//Flee
		else if (strcmp(userInput.c_str(), "4") == 0) {

				//Success
			if (Flee(pc, enemy)) {
				cout << "You evade " << enemy.GetName() << "!" << endl;
				break;
			}
				//Fail
			else {
				cout << "You fail to escape." << endl;
			}
		}
			//Surrender
		else if (strcmp(userInput.c_str(), "5") == 0) {
			cout << "Not Implemented" << endl;
		}
			//View Character
		else if (strcmp(userInput.c_str(), "6") == 0) {

		}

		//Check if the enemy is dead to end the encounter
		if (!enemy.IsAlive()) {
			break;
		}

		//Enemy Turn
			//Enemy tries to flee if not unique and at critical health
		if(!enemy.IsUnique() && IsCriticalHealth(enemy)){
			if (Flee(enemy, pc)) {
				cout << enemy.GetName() << " fled!" << endl;
				break;
			}
			else {
				cout << enemy.GetName() << " tries to escape and fails!" << endl;
			}
		}
			//Randomly attack or defend for now
		else {
			srand(time(NULL));
			int randAction = rand() % 2;

				//Attack
			if (randAction == 1) {
				int dmg = Attack(enemy, pc);

				if (dmg == 0) {
					cout << enemy.GetName() << " attacked but missed!" << endl;
				}
				else {
					pc.TakeDamage(dmg);
					cout << enemy.GetName() << " attacks for " << dmg << " damage!" << endl;
				}
			}
				//Defend
			else if (randAction == 2) {
				cout << enemy.GetName() << " stands ready for your next attack." << endl;
				pc.GiveDisAdv();
			}
		}
	}
}