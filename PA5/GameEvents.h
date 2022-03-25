#ifndef __GAMEEVENTS__
#define __GAMEEVENTS__

#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <map>

#include "Image.h"
#include "Character.h"
#include "Clear.h"
#include "Weapon.h"
#include "Armor.h"
#include "Consumable.h"

void rollForWeapon(Character&, map<string, Weapon>);
void rollForArmor(Character&, map<string, Armor>);
void rollForConsumable(Character&, map<string, Consumable>);
void getHealing(Character&, map<string, Consumable>);
void getCustomItem(Character&, int);
void getMiscItem();
void changeStat();
void dialog(Character&, string, map<string, Image>, map<string, Weapon>, map<string, Armor>, map<string, Consumable>); // Weapons table

#endif 