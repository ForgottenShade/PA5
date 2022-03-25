#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<tuple>
#include<cstring>
#include<filesystem>
#include<map>
#include<stdlib.h>
#include <stdio.h>
#include <windows.h>

#include"Image.h"
#include"Weapon.h"
#include"Armor.h"
#include"Consumable.h"
#include"Character.h"
#include"Encounter.h"
#include "GameEvents.h"
#include "Clear.h"
#include "SaveGame.h"

namespace fs = std::filesystem;
using namespace std;

string ROOT_DIR = fs::current_path().string();
string ASSET_DIR = ROOT_DIR + "/Assets";
string IMAGE_DIR = ASSET_DIR + "/Images";
string UI_DIR = ASSET_DIR + "/UI";
string DIALOG_DIR = ASSET_DIR + "/Dialogs";
string SAVE_DIR = ROOT_DIR + "/Saves";

map<string, Image> IMAGES;
map<string, Image> UIS;
map<string, Image> DIALOGS;

map<string, Weapon> WEAPON_TABLE;
map<string, Armor> ARMOR_TABLE;
map<string, Consumable> CONSUMABLE_TABLE;

map<string, Character> ENEMIES;
map<string, Character> NPCS;

Character PC;
SaveGame LAST_SAVE;

void LoadAssets() {
	//Load Images
	for (const auto& entry : fs::directory_iterator(IMAGE_DIR)) {
		Image newImage = Image(entry.path());
		IMAGES.insert(pair<string, Image>(newImage.GetFilename(), newImage));
	}

	//Load UI
	for (const auto& entry : fs::directory_iterator(UI_DIR)) {
		Image newImage = Image(entry.path());
		UIS.insert(pair<string, Image>(newImage.GetFilename(), newImage));
	}

	//Load Dialogs
	for (const auto& entry : fs::directory_iterator(DIALOG_DIR)) {
		Image newImage = Image(entry.path());
		DIALOGS.insert(pair<string, Image>(newImage.GetFilename(), newImage));
	}
}

void LoadItems(){
	//Weapons
		//Generics
	Weapon* Fists = new Weapon();
			//Common: 1
	Weapon* Club = new Weapon("Club", 10, 1, 4, 1, true);
	Weapon* Axe = new Weapon("Axe", 10, 1, 6, 1, false);
	Weapon* Shortbow = new Weapon("Shortbow", 10, 1, 6, 1, false);
	Weapon* Shortsword = new Weapon("Shortsword", 10, 1, 6, 1, false);
	Weapon* Dagger = new Weapon("Dagger", 10, 1, 4, 1, false);
	Weapon* Quarterstaff = new Weapon("Quarterstaff", 10, 1, 6, 1, true); //STR

			//Uncommon: 2
	Weapon* Crossbow = new Weapon("Crossbow", 10, 2, 6, 1, false);
	Weapon* Longbow = new Weapon("Longbow", 10, 2, 8, 1, false);
	Weapon* Longsword = new Weapon("Longsword", 10, 2, 8, 1, true);
	Weapon* Mace = new Weapon("Mace", 10, 2, 6, 1, true);
	Weapon* Spear = new Weapon("Spear", 10, 2, 6, 1, false);

			//Rare: 3
	Weapon* Greatsword = new Weapon("Greatsword", 10, 3, 6, 2, true);
	Weapon* Greataxe = new Weapon("Greataxe", 10, 3, 12, 1, true);
	Weapon* Warhammer = new Weapon("Warhammer", 10, 3, 12, 1, true);
	Weapon* Rapier = new Weapon("Rapier", 10, 3, 8, 1, false);

		//Uniques: 4

		//NPC Attacks
	Weapon* Rat_Attack = new Weapon("Rat_Attack", 0, 0, 1, 1, NULL);
	Weapon* Goblin_Attack = new Weapon("Goblin_Attack", 0, 0, 6, 1, false);

	//Armors
		//Generics
	Armor* Clothes = new Armor("Clothes", 1, 1, 0, 999, "Not Armor");
			//Common
	Armor* Leather = new Armor();
	Armor* Hide = new Armor();
	Armor* RingMail = new Armor();
			
			//Uncommon
	Armor* StuddedLeather = new Armor();
	Armor* ScaleMail = new Armor();
	Armor* ChainMail = new Armor();

			//Rare
	Armor* HalfPlate = new Armor();
	Armor* Plate = new Armor();

		//Uniques

	//Consumables
		//Generics
			//Common
	Consumable* HealingSalve = new Consumable("HealingSalve", 10, 1, 1, 0, 5);
	
			//Uncommon
	Consumable* HealingPotion = new Consumable("HealingPotion", 10, 2, 1, 0, 10); 

			//Rare
	Consumable* GreaterHealingPotion = new Consumable("GreaterHealingPotion", 10, 3, 1, 0, 20); 

		//Uniques

	WEAPON_TABLE.insert(pair<string, Weapon>(Shortsword->GetName(), Shortsword[0]));
	WEAPON_TABLE.insert(pair<string, Weapon>(Rat_Attack->GetName(), Rat_Attack[0]));
	WEAPON_TABLE.insert(pair<string, Weapon>(Goblin_Attack->GetName(), Goblin_Attack[0]));

	ARMOR_TABLE.insert(pair<string, Armor>(Clothes->GetName(), Clothes[0]));
}

void LoadCharacters() {
	//Enemies
		//Sewer
	Character* rat = new Character(false, "Beast", "Rat", IMAGES.find("Rat01.txt")->second, 2, 11, 9, 2, 10, 4, 1, 10, 0);
	Character* goblin = new Character(false, "Goblin", "Goblin", IMAGES.find("Goblin01.txt")->second, 8, 14, 10, 10, 8, 8, 7, 12, 1);
	Character* stankrat = new Character(true, "Goblin", "Stankrat", IMAGES.find("Stankrat01.txt")->second, 10, 14, 10, 10, 8, 10, 21, 14, 2);

	rat->SetWeapon(WEAPON_TABLE.find("Rat_Attack")->second);
	goblin->SetWeapon(WEAPON_TABLE.find("Goblin_Attack")->second);

		//Forest
	Character* wolf = new Character(false, "Beast", "Wolf", IMAGES.find("Wolf01.txt")->second, 12, 15, 12, 3, 12, 6, 11, 13, 1);
	Character* crab = new Character(false, "Beast", "Crabbo", IMAGES.find("Crab01.txt")->second, 14, 16, 18, 1, 10, 2, 25, 12, 2);
	Character* awakened_tree = new Character(true, "Plant", "Awakened Tree", IMAGES.find("Tree01.txt")->second, 19, 6, 15, 10, 10, 7, 30, 13, 3);
	
		//Town
	Character* theif = new Character();
	Character* guard = new Character();

	ENEMIES.insert(pair<string, Character>(rat->GetName(), rat[0]));
	ENEMIES.insert(pair<string, Character>(goblin->GetName(), goblin[0]));
	ENEMIES.insert(pair<string, Character>(stankrat->GetName(), stankrat[0]));

	ENEMIES.insert(pair<string, Character>(wolf->GetName(), wolf[0]));
	ENEMIES.insert(pair<string, Character>(crab->GetName(), crab[0]));
	ENEMIES.insert(pair<string, Character>(awakened_tree->GetName(), awakened_tree[0]));

	//NPCs
}

//Game Structure
void GameOver() {

}

//Confrontation: stage 3
void Dungeon() {
	GameOver();
}

//Self Discovery: stage 2
void Town() {
	Dungeon();
}

//Escape: stage 1
void Sewer(double stage) {
	//**STAGE 1.1***
	if (stage == 1.1) {
		Dialog(PC, DIALOGS.find("IntroToRats.txt")->second.GetImage(), UIS, WEAPON_TABLE, ARMOR_TABLE, CONSUMABLE_TABLE, false);
		Encounter ratEncounter = Encounter(PC, ENEMIES.find("Rat")->second, UIS);
		Dialog(PC, DIALOGS.find("Rat2.txt")->second.GetImage(), UIS, WEAPON_TABLE, ARMOR_TABLE, CONSUMABLE_TABLE, false);
		Encounter ratEncounter = Encounter(PC, ENEMIES.find("Rat")->second, UIS);
		Dialog(PC, DIALOGS.find("RatsToIntersection.txt")->second.GetImage(), UIS, WEAPON_TABLE, ARMOR_TABLE, CONSUMABLE_TABLE, true);
		PC.ManageInventory(UIS);
		Dialog(PC, DIALOGS.find("IntersectionToGoblins.txt")->second.GetImage(), UIS, WEAPON_TABLE, ARMOR_TABLE, CONSUMABLE_TABLE, false);
		Encounter goblinEncounter = Encounter(PC, ENEMIES.find("Goblin")->second, UIS);
		Dialog(PC, DIALOGS.find("GoblinsToRest.txt")->second.GetImage(), UIS, WEAPON_TABLE, ARMOR_TABLE, CONSUMABLE_TABLE, false);

		//**STAGE 1.2***
		Rest(PC, stage, UIS, IMAGES);
		Dialog(PC, DIALOGS.find("RestToStankrat.txt")->second.GetImage(), UIS, WEAPON_TABLE, ARMOR_TABLE, CONSUMABLE_TABLE, false);
		Encounter stankratEncounter = Encounter(PC, ENEMIES.find("Stankrat")->second, UIS);
		Dialog(PC, DIALOGS.find("SewerToTown.txt")->second.GetImage(), UIS, WEAPON_TABLE, ARMOR_TABLE, CONSUMABLE_TABLE, false);
		Town();
	}
	else if (stage == 1.2) {
		Rest(PC, stage, UIS, IMAGES);
		Dialog(PC, DIALOGS.find("RestToStankrat.txt")->second.GetImage(), UIS, WEAPON_TABLE, ARMOR_TABLE, CONSUMABLE_TABLE, false);
		Encounter stankratEncounter = Encounter(PC, ENEMIES.find("Stankrat")->second, UIS);
		Dialog(PC, DIALOGS.find("SewerToTown.txt")->second.GetImage(), UIS, WEAPON_TABLE, ARMOR_TABLE, CONSUMABLE_TABLE, false);
		Town();
	}
}

void LoadGame(SaveGame save) {
	PC = save.GetPC();

	if (save.GetStage() == 1.1 || save.GetStage() == 1.2) {
		Sewer(save.GetStage());
	}
	else if (save.GetStage() == 2) {
		Town();
	}
	else if (save.GetStage() == 3) {
		Dungeon();
	}
}

void LoadGameMenu() {
	string userInput;
	while (true) {
		int fileCount = 0;
		vector<fs::path> filePaths;

		clear();
		cout << UIS.find("Border.txt")->second.GetImage();
		cout << "Select a save to load." << endl;
		cout << UIS.find("Border.txt")->second.GetImage();
		for (const auto& entry : fs::directory_iterator(SAVE_DIR)) {
			fileCount++;
			cout << fileCount << ". " << entry.path().string().substr(entry.path().string().find_last_of("/\\") + 1) << endl;
			filePaths.push_back(entry.path());
		}
		cout << fileCount + 1 << ". Cancel" << endl;
		cout << UIS.find("Border.txt")->second.GetImage();
		cin >> userInput;
		if (is_number(userInput)) {
			int index = atoi(userInput.c_str()) - 1;
			if (-1 < index < fileCount) {
				if (index == fileCount) {
					break;
				}
				else {
					LAST_SAVE = SaveGame(filePaths[index], IMAGES, WEAPON_TABLE, ARMOR_TABLE, CONSUMABLE_TABLE);
					LoadGame(LAST_SAVE);
					break;
				}
			}
		}
	}
}

void Rest(Character& PC, int stage, map<string, Image> UIS, map<string, Image> IMAGES) {
	string userInput;

	while (true) {
		clear();
		cout << IMAGES.find("Campfire.txt")->second.GetImage();
		cout << UIS.find("Border.txt")->second.GetImage();
		cout << UIS.find("RestMenu.txt")->second.GetImage();
		cout << UIS.find("Border.txt")->second.GetImage();
		cin >> userInput;

		//Rest
		if (strcmp(userInput.c_str(), "1") == 0) {
			int halfHp = (PC.GetMaxHp() / 2);
			cout << "You heal " << halfHp << " points!" << endl;
			PC.Heal(halfHp);
			break;
		}
		//Inventory
		else if (strcmp(userInput.c_str(), "2") == 0) {
			PC.ManageInventory(UIS);
		}
		//Save Game
		else if (strcmp(userInput.c_str(), "3") == 0) {
			LAST_SAVE = SaveGame(PC, stage, SAVE_DIR);
		}
		//Load Game
		else if (strcmp(userInput.c_str(), "3") == 0) {
			LoadGameMenu();
		}
	}
}

void NewGame() {
	Dialog(PC, DIALOGS.find("Intro.txt")->second.GetImage(), UIS, WEAPON_TABLE, ARMOR_TABLE, CONSUMABLE_TABLE, false);
	PC = Character(UIS);
	PC.SetArmor(ARMOR_TABLE.find("Clothes")->second);
	PC.SetWeapon(WEAPON_TABLE.find("Fist")->second);
	LAST_SAVE = SaveGame(PC, 1.1, SAVE_DIR);
	Sewer(1.1);
}

void StartMenu() {
	string userInput;

	while (true) {
		clear();
		cout << IMAGES.find("Mountains01.txt")->second.GetImage() << endl;
		cout << UIS.find("Border.txt")->second.GetImage();
		cout << UIS.find("Border.txt")->second.GetImage();
		cout << UIS.find("Welcome.txt")->second.GetImage();
		cout << UIS.find("Border.txt")->second.GetImage();
		cout << UIS.find("Border.txt")->second.GetImage();
		cout << UIS.find("StartMenu.txt")->second.GetImage();
		cout << UIS.find("Border.txt")->second.GetImage();


		cin >> userInput;


		if (strcmp(userInput.c_str(), "1") == 0) {
			NewGame();
			break;
		}
		else if (strcmp(userInput.c_str(), "2") == 0) {
			LoadGameMenu();
			break;
		}
	}
}

void ResizeWindow(){
	HANDLE wHnd;    // Handle to write to the console.
	HANDLE rHnd;    // Handle to read from the console.

    // Set up the handles for reading/writing:
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    rHnd = GetStdHandle(STD_INPUT_HANDLE);
    // Change the window title:
    SetConsoleTitle(L"Chains of Content");
    // Set up the required window size:
    SMALL_RECT windowSize = {0, 0, 1000, 600};
    SetConsoleWindowInfo(wHnd, 1, &windowSize);
    // Change the console window size:
        // Create a COORD to hold the buffer size:
    COORD bufferSize = {10, 10};
    SetConsoleScreenBufferSize(wHnd, bufferSize);
}

int main() {
	//ResizeWindow();
	LoadAssets();
	LoadItems();
	LoadCharacters();
	StartMenu();
	return 1;
}