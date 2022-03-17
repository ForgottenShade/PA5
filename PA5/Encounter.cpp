#include<string>
#include<map>
#include<iostream>
#include"Image.h"
#include"Character.h"

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