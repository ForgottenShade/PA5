#include<iostream>
#include<fstream>
#include<filesystem>
#include<string>

#include"Consumable.h"
#include"Armor.h"
#include"Weapon.h"
#include"Character.h"
#include"GameFile.h"
#include"Clear.h"

namespace fs = std::filesystem;
using namespace std;

class SaveGame :public GameFile {
private:
	Character PC;
	int Stage;
public:
	SaveGame(fs::path, map<string, Image>, map<string, Weapon>, map<string, Armor>, map<string, Consumable>);
	SaveGame(Character, double, string);
	SaveGame() = default;
	~SaveGame() = default;

	Character GetPC();
	int GetStage();
};