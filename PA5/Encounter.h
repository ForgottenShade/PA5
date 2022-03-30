#ifndef _ENCOUNTER_
#define _ENCOUNTER_

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


using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::system_clock;
using namespace std;

class Encounter {
private:
	Character PC;
	Character Enemy;
	bool Fled;
public:
	Encounter() = default;
	~Encounter() = default;
	Encounter(Character&, Character, map<string, Image>);

	bool is_number(const string&);
	int Attack(Character, Character);
	void UseItem(Character, Character, Consumable);
	bool CombatItemMenu(Character, Character, map<string, Image>);
	bool Flee(Character, Character);
	bool GetFled();
};


#endif