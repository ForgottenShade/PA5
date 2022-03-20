#ifndef _CHARACTER_
#define _CHARACTER_

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

	int Str;	//Strength
	int Dex;	//Dexterity
	int Con;	//Constitution
	int Int;	//Intelligence
	int Wis;	//Wisdom
	int Cha;	//Charisma

	//Combat
	int CurrentHp;		//Hit Points
	int MaxHp;
	int AC;		//Armor Class
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

#endif