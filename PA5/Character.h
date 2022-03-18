#ifndef _CHARACTER_
#define _CHARACTER_

#include<string>
#include<iostream>
#include<map>
#include<vector>
#include"Image.h"
#include"Weapon.h"
#include"Armor.h"
#include"Consumable.h"

using namespace std;

class Character {
private:
	string Race;
	string Name;

	int Str;	//Strength
	int Dex;	//Dexterity
	int Con;	//Constitution
	int Int;	//Intelligence
	int Wis;	//Wisdom
	int Cha;	//Charisma

	int Hp;		//Hit Points
	int AC;		//Armor Class
	int Level;

	Weapon CurrentWeapon;
	Armor CurrentArmor;

	//Inventory
	int Gold;
	vector<Weapon> Weapons;
	vector<Armor> Armors;
	vector<Consumable> Consumables;
public:
	Character(map<string, Image>);
	Character(string, string, string, int, int, int, int, int, int, int, int, int);
	Character();

	string GetName();
	string GetArt();
};

#endif