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

//Character a attacks character b, returns damage to b
int Encounter::Attack(Character a, Character b) {
	Weapon attackerWeapon = a.GetCurrentWeapon();
	int defenderAC = b.GetAC();
	int adv = a.GetAdv();
	int dmg = 0;
	int bonus = 0;
	int roll;

	//if no damage stat (NPC)
	if (attackerWeapon.GetDamageStat() == NULL) {
		roll = a.Roll(1, 20);

		//handle advantage/disadvantage
		if (adv == 0) {
			int roll2 = a.Roll(1, 20);
			roll = min(roll, roll2);
		}
		else if (adv == 2) {
			int roll2 = a.Roll(1, 20);
			roll = max(roll, roll2);
		}

		//check if hit
		if (roll > defenderAC) {
			dmg = a.Roll(attackerWeapon.GetNumberOfDice(), attackerWeapon.GetDamageDice());
		}
	}
	//true: Str
	else if (attackerWeapon.GetDamageStat()) {
		bonus = a.GetBonus(a.GetStr());
		roll = a.Roll(1, 20) + bonus;

		//handle advantage/disadvantage
		if (adv == 0) {
			int roll2 = a.Roll(1, 20) + bonus;
			roll = min(roll, roll2);
		}
		else if (adv == 2) {
			int roll2 = a.Roll(1, 20) + bonus;
			roll = max(roll, roll2);
		}
		
		//check if hit
		if (roll > defenderAC) {
			dmg = a.Roll(attackerWeapon.GetNumberOfDice(), attackerWeapon.GetDamageDice()) + bonus;
		}
	}
	//false: Dex
	else 
	{
		bonus = a.GetBonus(a.GetDex());
		roll = a.Roll(1, 20) + bonus;

		//handle advantage/disadvantage
		if (adv == 0) {
			int roll2 = a.Roll(1, 20) + bonus;
			roll = min(roll, roll2);
		}
		else if (adv == 2) {
			int roll2 = a.Roll(1, 20) + bonus;
			roll = max(roll, roll2);
		}

		//check if hit
		if (roll > defenderAC) {
			dmg = a.Roll(attackerWeapon.GetNumberOfDice(), attackerWeapon.GetDamageDice()) + bonus;
		}
	}

	//reset advantage
	a.ResetAdv();

	//print rolls
	cout << a.GetName() << " rolled: " + to_string(roll) + " against " + b.GetName() + "'s AC of " + to_string(defenderAC) << endl;
	return dmg;
}

//Character a uses item c (healing applied to self, damage to character b, handle uses)
void Encounter::UseItem(Character a, Character b, Consumable c) {
	a.Heal(c.GetHealing());
	b.TakeDamage(c.GetDamage());
	c.SetUses(c.GetUses() - 1);
}

//Returns whether an item was used 
bool Encounter::CombatItemMenu(Character a, Character b, map<string, Image> UIS) {
	vector<Consumable> items = a.GetConsumableInv();
	string userInput;

	while (true) {
		clear();
		cout << UIS.find("Border.txt")->second.GetImage();
		cout << "Select an item to use." << endl;
		cout << UIS.find("Border.txt")->second.GetImage();

		//list all items
		for (int i = 0; i < items.size(); i++) {
			cout << i + 1 << ". " << items[i].CombatInfo() << endl;
		}
		cout << items.size() + 1 << ". Cancel" << endl;
		cout << UIS.find("Border.txt")->second.GetImage();

		cin >> userInput;

		if (is_number(userInput)) {
			int index = atoi(userInput.c_str()) - 1;

			if (index == items.size() + 1) {
				return false;
			}
			Consumable item = items[index];
			UseItem(a, b, item);

			//Remove from inventory if uses == 0
			if (item.GetUses() == 0) {
				items.erase(items.begin() + index);
			}
			return true;
		}
	}
}

//Returns true if character a succeeds in fleeing from character b, otherwise false
//This is a Dex roll vs the Dex saving throw of the opponent
bool Encounter::Flee(Character a, Character b) {
	int rollA = a.Roll(1, 20) + a.GetBonus(a.GetDex());
	int rollB = b.SavingThrow(b.GetDex());

	if (rollA > rollB) {
		return true;
	}
	return false;
}

//1v1
Encounter::Encounter(Character pc, Character enemy, map<string, Image> UIS) {
	PC = pc;
	Enemy = enemy;
	string userInput;
	bool player_turn = true;

	while (true) {
		//Player Turn
		clear();
		cout << enemy.GetArt();
		cout << UIS.find("Border.txt")->second.GetImage();
		cout << enemy.GetName() << "\tHealth: " << enemy.GetCurrentHp() << "/" << enemy.GetMaxHp() << "\tArmor Class: " << enemy.GetAC() << endl;
		cout << UIS.find("Border.txt")->second.GetImage();
		cout << "1. Attack [" + pc.GetCurrentWeapon().Info() + "]\t2. Defend\t3. Use Item" << endl;
		cout << "4. Flee\t\t5. Inventory" << endl;
		cout << UIS.find("Border.txt")->second.GetImage();
		cout << pc.GetName() << "\tHealth: " << pc.GetCurrentHp() << "/" << pc.GetMaxHp() << "\tArmor Class: " << pc.GetAC() << endl;
		cout << UIS.find("Border.txt")->second.GetImage();
		cin >> userInput;
		clear();

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
			player_turn = false;
		}
			//Defend
		else if (strcmp(userInput.c_str(), "2") == 0) {
			cout << "You stand ready for the next attack." << endl;
			enemy.GiveDisAdv();
			player_turn = false;
		}
			//Use Item
		else if (strcmp(userInput.c_str(), "3") == 0) {
			player_turn = CombatItemMenu(pc, enemy, UIS);
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
			player_turn = false;
		}
			//Inventory
		else if (strcmp(userInput.c_str(), "5") == 0) {
			pc.ManageInventory(UIS);
		}

		cin.ignore();
		cout << "Hit Enter to continue.";
		cin.ignore();


		//Check if player turn over
		if (!player_turn) {
			clear();
			//Check if the enemy is dead to end the encounter
			if (!enemy.IsAlive()) {
				cout << enemy.GetName() << " has been defeated!" << endl;
				cout << "Hit Enter to continue.";
				cin.ignore();
				break;
			}

			//Enemy Turn
				//Enemy tries to flee if not unique and at critical health
			if (!enemy.IsUnique() && enemy.IsCriticalHealth()) {
				if (Flee(enemy, pc)) {
					cout << enemy.GetName() << " fled!" << endl;
					cout << "Hit Enter to continue.";
					cin.ignore();
					break;
				}
				else {
					cout << enemy.GetName() << " tries to escape and fails!" << endl;
					cout << "Hit Enter to continue.";
					cin.ignore();
					player_turn = true;
				}
			}
			//Randomly attack or defend for now
			else {
				srand(time(NULL));
				int randAction = rand() % 2 + 1;

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
					player_turn = true;
				}
				//Defend
				else if (randAction == 2) {
					cout << enemy.GetName() << " stands ready for your next attack." << endl;
					pc.GiveDisAdv();
					player_turn = true;
				}
				cout << "Hit Enter to continue.";
				cin.ignore();
			}
		}
	}
}