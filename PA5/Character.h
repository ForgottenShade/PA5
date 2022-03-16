#ifndef _CHARACTER_
#define _CHARACTER_

#include<string>
#include<iostream>
#include<map>
#include"Image.h"

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
public:
	Character(map<string, Image>);
	Character(int);
	Character();
};

#endif