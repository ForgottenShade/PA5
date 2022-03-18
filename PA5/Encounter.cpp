#include<string>
#include<map>
#include<iostream>
#include<random>
#include<time.h>
#include"Image.h"
#include"Character.h"

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

int GetBonus(int stat) {
	return (stat - 10) / 2;
}

int Roll(int count, int d) {
	srand(time(NULL));
	int roll = 0;
	for (int i = 0; i < count; i++) {
		roll += rand() % d;
	}
	return roll;
}