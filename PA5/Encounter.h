#ifndef _ENCOUNTER_
#define _ENCOUNTER_

#include<string>
#include<map>
#include<iostream>
#include<random>
#include<time.h>
#include<stdlib.h>
#include<cstring>
#include<chrono>

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
public:
	Encounter();
	Encounter(Character&, Character&, map<string, Image>, map<string, Image>);
};


#endif