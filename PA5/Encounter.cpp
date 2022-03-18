#include<string>
#include<map>
#include<iostream>
#include<random>
#include<time.h>
#include"Image.h"
#include"Weapon.h"
#include"Armor.h"
#include"Character.h"

//Time used for random seed generation to ensure non-deterministic behavior
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::system_clock;
using namespace std;

class Encounter {
private:
	Character PC;
	Character Enemy;
public:
	Encounter();
	Encounter(Character&, Character&, map<string, Image>, map<string, Image>);
};

//Returns the stat bonus or malice for a stat
int GetBonus(int stat) {
	return (stat - 10) / 2;
}

//Roll an x sided dice, count times, returns sum of roll(s)
int Roll(int count, int x) {
	srand(time(NULL));
	int roll = 0;
	for (int i = 0; i < count; i++) {
		roll += rand() % x;
	}
	return roll;
}

//Character a attacks character b, returns damage to b
int Attack(Character a, Character b) {
	Weapon attackerWeapon = a.GetCurrentWeapon();
	int defenderAC = b.GetAC();
	int dmg = 0;

	//true: Str
	if (attackerWeapon.GetDamageStat()) {
		int attkBonus = GetBonus(a.GetStr());
		int roll = Roll(1, 20);
		//check if hit
		if (roll + attkBonus > defenderAC) {
			dmg = Roll(attackerWeapon.GetNumberOfDice(), attackerWeapon.GetDamageDice());
		}
	}
	//false: Dex
	else 
	{
		int attkBonus = GetBonus(a.GetDex());
		int roll = Roll(1, 20);
		//check if hit
		if (roll + attkBonus > defenderAC) {
			dmg = Roll(attackerWeapon.GetNumberOfDice(), attackerWeapon.GetDamageDice());
		}
	}

	return dmg;
}

Encounter::Encounter(){}

Encounter::Encounter(Character& pc, Character& enemy, map<string, Image> IMAGES, map<string, Image> UIS) {
	PC = pc;
	Enemy = enemy;

	while (true) {
		enemy.GetArt();
		cout << UIS.find("Border.txt")->second.GetImage();
		cout << UIS.find("Border.txt")->second.GetImage();
		cout << UIS.find("CombatMenu.txt")->second.GetImage();

	}
}