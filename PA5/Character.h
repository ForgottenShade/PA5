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
	Image Art;
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
	Character(string, string, string, int, int, int, int, int, int, int, int, int, int, Weapon, Armor, vector<Weapon>, vector<Armor>, vector<Consumable>, map<string, Image>);
	Character(bool, string, string, Image, int, int, int, int, int, int, int, int, int);
	Character(map<string, Image>);
	Character() = default;
	~Character() = default;

	bool IsUnique();
	bool IsAlive();
	string GetName();
	string GetRace();
	string GetArt();
	string GetArtFilename();
	int GetStr();
	int GetDex();
	int GetCon();
	int GetInt();
	int GetWis();
	int GetCha();
	int GetCurrentHp();
	int GetMaxHp();
	int GetAC();
	int GetLevel();

	Weapon GetCurrentWeapon();
	Armor GetCurrentArmor();

	int GetAdv();

	int GetGold();
	vector<Weapon> GetWeaponInv();
	vector<Armor> GetArmorInv();
	vector<Consumable> GetConsumableInv();

	bool is_number(const string&);
	int GetBonus(int);
	bool IsCriticalHealth();
	int Roll(int, int);
	int SavingThrow(int);

	void ChangeStat(string, int&, int&);
	void TakeDamage(int);
	void Heal(int);
	void GiveAdv();
	void GiveDisAdv();
	void ResetAdv();
	void PrintCharacterStats(map<string, Image>);
	void ManageInventory(map<string, Image>);
	void SetWeapon(Weapon);
	void SetArmor(Armor);
};

#endif