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

namespace fs = std::filesystem;
using namespace std;

string ASSET_DIR = fs::current_path().string() + "/Assets";
string IMAGE_DIR = ASSET_DIR + "/Images";
string UI_DIR = ASSET_DIR + "/UI";
string DIALOG_DIR = ASSET_DIR + "/Dialogs";

map<string, Image> IMAGES;
map<string, Image> UIS;
map<string, Image> DIALOGS;

map<string, Weapon> WEAPON_TABLE;
map<string, Armor> ARMOR_TABLE;
map<string, Consumable> CONSUMABLE_TABLE;

map<string, Character> ENEMIES;
map<string, Character> NPCS;

Character PC;

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
	Character* rat = new Character(false, "Beast", "Rat", IMAGES.find("Rat01.txt")->second.GetImage(), 2, 11, 9, 2, 10, 4, 1, 10, 0);
	Character* goblin = new Character(false, "Goblin", "Goblin", IMAGES.find("Goblin01.txt")->second.GetImage(), 8, 14, 10, 10, 8, 8, 7, 12, 1);
	Character* stankrat = new Character(true, "Goblin", "Stankrat", IMAGES.find("Stankrat01.txt")->second.GetImage(), 10, 14, 10, 10, 8, 10, 21, 14, 2);

	rat->SetWeapon(WEAPON_TABLE.find("Rat_Attack")->second);
	goblin->SetWeapon(WEAPON_TABLE.find("Goblin_Attack")->second);

		//Forest
	Character* wolf = new Character(false, "Beast", "Wolf", IMAGES.find("Wolf01.txt")->second.GetImage(), 12, 15, 12, 3, 12, 6, 11, 13, 1);
	Character* crab = new Character(false, "Beast", "Crabbo", IMAGES.find("Crab01.txt")->second.GetImage(), 14, 16, 18, 1, 10, 2, 25, 12, 2);
	Character* awakened_tree = new Character(true, "Plant", "Awakened Tree", IMAGES.find("Tree01.txt")->second.GetImage(), 19, 6, 15, 10, 10, 7, 30, 13, 3);

		//Town
	Character* theif = new Character();
	Character* gaurd = new Character();

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
void Sewer(int stage) {
	//**STAGE 1.1***
	//side chamber -> exit into tunnels
	Encounter ratEncounter = Encounter(PC, ENEMIES.find("Rat")->second, UIS);
	//theres another one!
	Encounter ratEncounter = Encounter(PC, ENEMIES.find("Rat")->second, UIS);
	//going up in the tunnels, to intersection, find goblin traces +weapon
	//just manage inventory, not rest screen 
	//intersection -> tunnel -> goblins
	Encounter goblinEncounter = Encounter(PC, ENEMIES.find("Goblin")->second, UIS);
	//look around +armor
	
	//**STAGE 1.2***
	//goblin food, rest, inventory for armor, save/load
	Encounter stankratEncounter = Encounter(PC, ENEMIES.find("Stankrat")->second, UIS);
	//healing potion loot, misc object
	//emerge from the sewer
	Town();
}

void NewGame() {
	//Character/story intro here
	
	PC = Character(UIS);
	PC.SetArmor(ARMOR_TABLE.find("Clothes")->second);
	PC.SetWeapon(WEAPON_TABLE.find("Fist")->second);
	LAST_SAVE = SaveGame(PC, 1, SAVE_DIR);
	Sewer(1);
}

void LoadGame(SaveGame save) {
	PC = save.GetPC();

	if (save.GetStage() == 1) {
		Sewer();
	}
	else if (save.GetStage() == 2) {
		Town();
	}
	else if (save.GetStage() == 3) {
		Dungeon();
	}
}

void LoadGame() {

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
			LoadGame();
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