#ifndef __GAMEEVENTS__
#define __GAMEEVENTS__

#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <random>
#include <time.h>
#include <map>

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

void RollForWeapon(Character&, map<string, Weapon>, bool);
void RollForArmor(Character&, map<string, Armor>, bool);
void RollForConsumable(Character&, map<string, Consumable>, bool);

void GetHealing(Character&, map<string, Consumable>);
void GetCustomItem(Character&, int);
void GetMiscItem();
void ChangeStat();

void Dialog(Character&, string, map<string, Image>, map<string, Weapon>, map<string, Armor>, map<string, Consumable>, bool); // Weapons table

#endif 