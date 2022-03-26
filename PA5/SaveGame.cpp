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
#include"SaveGame.h"

namespace fs = std::filesystem;
using namespace std;

//Read save from file
SaveGame::SaveGame(fs::path path, map<string, Image> IMAGES, map<string, Weapon> WEAPON_TABLE, map<string, Armor> ARMOR_TABLE, map<string, Consumable> CONSUMABLE_TABLE):GameFile(path) {
	ifstream reader(GameFile::GetPath());
	int lineCount = 0;
	bool readingWep = false;
	bool readingArm = false;
	bool readingCon = false;

	//have to build it to the constructor
	string race = "";
	string name = "";
	string art_file = "";
	int str = 0;
	int dex = 0;
	int con = 0;
	int intelligence = 0;
	int wis = 0;
	int cha = 0;
	int currenthp = 0;
	int maxhp = 0;
	int level = 0;
	int gold = 0;

	Weapon currentweapon = Weapon();
	Armor currentarmor = Armor();

	vector<Weapon> weapons;
	vector<Armor> armors;
	vector<Consumable> consumables;

	if (reader) {
		while (reader.good()) {
			string currentLine;
			getline(reader, currentLine);

			//hardcoding reading from the file
			if (lineCount == 0) {
				Stage = stoi(currentLine);
			}
			else if (lineCount == 1) {
				art_file = currentLine;
			}
			else if (lineCount == 2) {
				race = currentLine;
			}
			else if (lineCount == 3) {
				name = currentLine;
			}
			else if (lineCount == 4) {
				str = atoi(currentLine.c_str());
			}
			else if (lineCount == 5) {
				dex = atoi(currentLine.c_str());
			}
			else if (lineCount == 6) {
				con = atoi(currentLine.c_str());
			}
			else if (lineCount == 7) {
				intelligence = atoi(currentLine.c_str());
			}
			else if (lineCount == 8) {
				wis = atoi(currentLine.c_str());
			}
			else if (lineCount == 9) {
				cha = atoi(currentLine.c_str());
			}
			else if (lineCount == 10) {
				currenthp = atoi(currentLine.c_str());
			}
			else if (lineCount == 11) {
				maxhp = atoi(currentLine.c_str());
			}
			else if (lineCount == 12) {
				level = atoi(currentLine.c_str());
			}
			else if (lineCount == 13) {
				currentweapon = WEAPON_TABLE.find(currentLine)->second;
			}
			else if (lineCount == 14) {
				currentarmor = ARMOR_TABLE.find(currentLine)->second;
			}
			else if (lineCount == 15) {
				gold = atoi(currentLine.c_str());
			}
			//load inventory
			else if (strcmp(currentLine.c_str(), "WeaponInv:") == 0) {
				readingWep = true;
			}
			else if (strcmp(currentLine.c_str(), "ArmorInv:") == 0) {
				readingWep = false;
				readingArm = true;
			}
			else if (strcmp(currentLine.c_str(), "ConsInv:") == 0) {
				readingArm = false;
				readingCon = true;
			}
			else if (readingWep) {
				weapons.push_back(WEAPON_TABLE.find(currentLine)->second);
			}
			else if (readingArm) {
				armors.push_back(ARMOR_TABLE.find(currentLine)->second);
			}
			else if (readingCon) {
				consumables.push_back(CONSUMABLE_TABLE.find(currentLine)->second);
			}

			lineCount++;
		}
	}

	PC = Character(race, name, art_file, str, dex, con, intelligence, wis, cha, currenthp, maxhp, level, gold, currentweapon, currentarmor, weapons, armors, consumables, IMAGES);
}

//Saves the game to file
SaveGame::SaveGame(Character pc, int stage, string SAVE_DIR) {
	PC = pc;
	Stage = stage;
	string userInput;

	clear();
	cout << "Enter a name for the save: " << endl;
	cin >> userInput;

	//build the file
	ofstream save(SAVE_DIR + "\\" + userInput + ".txt");
	save << stage << endl;
	if (strcmp(pc.GetArtFilename().c_str(), "") == 0) {
		save << "DefaultCharacter01.txt" << endl;
	}
	else {
		save << pc.GetArtFilename() << endl;
	}
	save << pc.GetRace() << endl;
	save << pc.GetName() << endl;
	save << pc.GetStr() << endl;
	save << pc.GetDex() << endl;
	save << pc.GetCon() << endl;
	save << pc.GetInt() << endl;
	save << pc.GetWis() << endl;
	save << pc.GetCha() << endl;
	save << pc.GetCurrentHp() << endl;
	save << pc.GetMaxHp() << endl;
	save << pc.GetLevel() << endl;
	save << pc.GetCurrentWeapon().GetName() << endl;
	save << pc.GetCurrentArmor().GetName() << endl;
	save << pc.GetGold() << endl;
	save << "WeaponInv:" << endl;
	for (int i = 0; i < pc.GetWeaponInv().size(); i++) {
		save << pc.GetWeaponInv()[i].GetName() << endl;
	}
	save << "ArmorInv:" << endl;
	for (int i = 0; i < pc.GetArmorInv().size(); i++) {
		save << pc.GetArmorInv()[i].GetName() << endl;
	}
	save << "ConsInv:" << endl;
	for (int i = 0; i < pc.GetConsumableInv().size(); i++) {
		save << pc.GetConsumableInv()[i].GetName() << endl;
	}
	save.close();
}


Character SaveGame::GetPC() {
	return PC;
}

int SaveGame::GetStage() {
	return Stage;
}