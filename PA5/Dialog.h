#ifndef __DIALOGS__
#define __DIALOGS__
// Reanme to  Game events 
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <map>

#include "Image.h"
#include "Character.h"
#include "Clear.h"

void dialog(Character&, string, map<string, Image>); // Weapons table
void rollForWeapon(Character&); // Weapons table
void rollForHealing();
void getHealing();
void getCustomItem(int);
void getMiscItem();
void changeStat();

#endif 