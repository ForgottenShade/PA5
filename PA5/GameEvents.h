#ifndef __GAMEEVENTS__
#define __GAMEEVENTS__

#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <random>
#include <time.h>
#include <map>
#include<algorithm>

#include "Image.h"
#include "Character.h"
#include "Clear.h"
#include "Weapon.h"
#include "Armor.h"
#include "Consumable.h"

bool is_number(const string& );

Consumable GetConsumableByQuality(int, map<string, Consumable>);
Armor GetArmorByQuality(int, map<string, Armor>);
Weapon GetWeaponByQuality(int, map<string, Weapon>);

void RollForWeapon(Character&, map<string, Weapon>, int, bool);
void RollForArmor(Character&, map<string, Armor>, int, bool);
void RollForConsumable(Character&, map<string, Consumable>, int, bool);
int RollSkill(Character&, string, string, int);

void GetHealing(Character&, map<string, Consumable>);
void GetCustomItem(Character&, int);
void GetMiscItem();
void ChangeStat();

int Dialog(Character&, string, map<string, Image>, map<string, Weapon>, map<string, Armor>, map<string, Consumable>, int = 0, bool = false); // Weapons table

#endif 