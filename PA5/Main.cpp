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
#include"GameEvents.h"
#include"Clear.h"
#include"SaveGame.h"

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
	Weapon* Fists = new Weapon("Fists", 0, 0, 4, 1, true);
			//Common: 1
	Weapon* Club = new Weapon("Club", 10, 1, 4, 1, true);
	Weapon* Axe = new Weapon("Axe", 20, 1, 6, 1, false);
	Weapon* Shortbow = new Weapon("Shortbow", 20, 1, 6, 1, false);
	Weapon* Shortsword = new Weapon("Shortsword", 20, 1, 6, 1, false);
	Weapon* Dagger = new Weapon("Dagger", 15, 1, 4, 1, false);
	Weapon* Quarterstaff = new Weapon("Quarterstaff", 15, 1, 6, 1, true); //STR

			//Uncommon: 2
	Weapon* Crossbow = new Weapon("Crossbow", 50, 2, 6, 1, false);
	Weapon* Longbow = new Weapon("Longbow", 70, 2, 8, 1, false);
	Weapon* Longsword = new Weapon("Longsword", 90, 2, 8, 1, true);
	Weapon* Mace = new Weapon("Mace", 70, 2, 6, 1, true);
	Weapon* Spear = new Weapon("Spear", 65, 2, 6, 1, false);

			//Rare: 3
	Weapon* Greatsword = new Weapon("Greatsword", 120, 3, 6, 2, true);
	Weapon* Greataxe = new Weapon("Greataxe", 115, 3, 12, 1, true);
	Weapon* Warhammer = new Weapon("Warhammer", 95, 3, 12, 1, true);
	Weapon* Rapier = new Weapon("Rapier", 105, 3, 8, 1, false);

		//Uniques: 4
	Weapon* ShortswordP1 = new Weapon("Shortsword +1", 200, 4, 9, 1, false);


		//NPC Attacks
	Weapon* Rat_Attack = new Weapon("Rat_Attack", 0, 0, 1, 1, NULL);
	Weapon* Goblin_Attack = new Weapon("Goblin_Attack", 0, 0, 6, 1, false);

	//Armors
		//Generics
	Armor* Clothes = new Armor("Clothes", 1, 0, 0, 999, "Not Armor");
			//Common
	Armor* Leather = new Armor("Leather", 20, 1, 1, 999, "Light");
	Armor* Hide = new Armor("Hide", 30, 1, 2, 14, "Medium");
	Armor* RingMail = new Armor("RingMail", 50, 1, 4, 14, "Heavy");
			
			//Uncommon
	Armor* StuddedLeather = new Armor("Studded Leather", 100, 2, 2, 999, "Light");
	Armor* ScaleMail = new Armor("Scale Mail", 150, 2, 4, 16, "Medium");
	Armor* ChainMail = new Armor("Chain Mail", 300, 2, 6, 16, "Heavy");

			//Rare
	Armor* HalfPlate = new Armor("Half Plate", 500, 3, 5, 17, "Medium");
	Armor* Plate = new Armor("Plate", 1000, 3, 8, 18, "Heavy");

		//Uniques
	Armor* StuddedLeatherP1 = new Armor("Studded Leather +1", 3000, 4, 3, 999, "Light");

	//Consumables
		//Generics
			//Common
	Consumable* HealingSalve = new Consumable("Healing Salve", 30, 1, 1, 0, 5);
	
			//Uncommon
	Consumable* HealingPotion = new Consumable("Healing Potion", 50, 2, 1, 0, 10); 

			//Rare
	Consumable* GreaterHealingPotion = new Consumable("Greater Healing Potion", 100, 3, 1, 0, 20); 

		//Uniques
	Consumable* MajorHealingPotion = new Consumable("Major Healing Potion", 200, 4, 1, 0, 50);


	WEAPON_TABLE.insert(pair<string, Weapon>(Fists->GetName(), Fists[0]));
	WEAPON_TABLE.insert(pair<string, Weapon>(Club->GetName(), Club[0]));
	WEAPON_TABLE.insert(pair<string, Weapon>(Axe->GetName(), Axe[0]));
	WEAPON_TABLE.insert(pair<string, Weapon>(Shortbow->GetName(), Shortbow[0]));
	WEAPON_TABLE.insert(pair<string, Weapon>(Shortsword->GetName(), Shortsword[0]));
	WEAPON_TABLE.insert(pair<string, Weapon>(Dagger->GetName(), Dagger[0]));
	WEAPON_TABLE.insert(pair<string, Weapon>(Quarterstaff->GetName(), Quarterstaff[0]));

	WEAPON_TABLE.insert(pair<string, Weapon>(Crossbow->GetName(), Crossbow[0]));
	WEAPON_TABLE.insert(pair<string, Weapon>(Longbow->GetName(), Longbow[0]));
	WEAPON_TABLE.insert(pair<string, Weapon>(Longsword->GetName(), Longsword[0]));
	WEAPON_TABLE.insert(pair<string, Weapon>(Mace->GetName(), Mace[0]));
	WEAPON_TABLE.insert(pair<string, Weapon>(Spear->GetName(), Spear[0]));

	WEAPON_TABLE.insert(pair<string, Weapon>(Greatsword->GetName(),Greatsword[0]));
	WEAPON_TABLE.insert(pair<string, Weapon>(Greataxe->GetName(),Greataxe[0]));
	WEAPON_TABLE.insert(pair<string, Weapon>(Warhammer->GetName(), Warhammer[0]));
	WEAPON_TABLE.insert(pair<string, Weapon>(Rapier->GetName(), Rapier[0]));

	WEAPON_TABLE.insert(pair<string, Weapon>(ShortswordP1->GetName(), ShortswordP1[0]));

	WEAPON_TABLE.insert(pair<string, Weapon>(Rat_Attack->GetName(), Rat_Attack[0]));
	WEAPON_TABLE.insert(pair<string, Weapon>(Goblin_Attack->GetName(), Goblin_Attack[0]));

	ARMOR_TABLE.insert(pair<string, Armor>(Clothes->GetName(), Clothes[0]));
	ARMOR_TABLE.insert(pair<string, Armor>(Leather->GetName(), Leather[0]));
	ARMOR_TABLE.insert(pair<string, Armor>(Hide->GetName(), Hide[0]));
	ARMOR_TABLE.insert(pair<string, Armor>(RingMail->GetName(), RingMail[0]));
	ARMOR_TABLE.insert(pair<string, Armor>(StuddedLeather->GetName(), StuddedLeather[0]));
	ARMOR_TABLE.insert(pair<string, Armor>(ChainMail->GetName(), ChainMail[0]));
	ARMOR_TABLE.insert(pair<string, Armor>(HalfPlate->GetName(), HalfPlate[0]));
	ARMOR_TABLE.insert(pair<string, Armor>(Plate->GetName(), Plate[0]));
	ARMOR_TABLE.insert(pair<string, Armor>(StuddedLeatherP1->GetName(), StuddedLeatherP1[0]));

	CONSUMABLE_TABLE.insert(pair<string, Consumable>(HealingSalve->GetName(), HealingSalve[0]));
	CONSUMABLE_TABLE.insert(pair<string, Consumable>(HealingPotion->GetName(), HealingPotion[0]));
	CONSUMABLE_TABLE.insert(pair<string, Consumable>(GreaterHealingPotion->GetName(), GreaterHealingPotion[0]));
	CONSUMABLE_TABLE.insert(pair<string, Consumable>(MajorHealingPotion->GetName(), MajorHealingPotion[0]));
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
	}
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
	//**STAGE 110***
	if (stage == 110) {
		Dialog(PC, DIALOGS.find("IntroToRats.txt")->second.GetImage(), UIS, WEAPON_TABLE, ARMOR_TABLE, CONSUMABLE_TABLE, false);
		Encounter ratEncounter = Encounter(PC, ENEMIES.find("Rat")->second, UIS);
		Dialog(PC, DIALOGS.find("Rat2.txt")->second.GetImage(), UIS, WEAPON_TABLE, ARMOR_TABLE, CONSUMABLE_TABLE, false);
		Encounter ratEncounter2 = Encounter(PC, ENEMIES.find("Rat")->second, UIS);
		Dialog(PC, DIALOGS.find("RatsToIntersection.txt")->second.GetImage(), UIS, WEAPON_TABLE, ARMOR_TABLE, CONSUMABLE_TABLE, true);
		PC.ManageInventory(UIS);
		Dialog(PC, DIALOGS.find("IntersectionToGoblins.txt")->second.GetImage(), UIS, WEAPON_TABLE, ARMOR_TABLE, CONSUMABLE_TABLE, false);
		Encounter goblinEncounter = Encounter(PC, ENEMIES.find("Goblin")->second, UIS);
		Dialog(PC, DIALOGS.find("GoblinToRest.txt")->second.GetImage(), UIS, WEAPON_TABLE, ARMOR_TABLE, CONSUMABLE_TABLE, false);

		//**STAGE 120***
		Rest(PC, 120, UIS, IMAGES);
		Dialog(PC, DIALOGS.find("RestToStankrat.txt")->second.GetImage(), UIS, WEAPON_TABLE, ARMOR_TABLE, CONSUMABLE_TABLE, false);
		Encounter stankratEncounter = Encounter(PC, ENEMIES.find("Stankrat")->second, UIS);
		Dialog(PC, DIALOGS.find("SewerToTown.txt")->second.GetImage(), UIS, WEAPON_TABLE, ARMOR_TABLE, CONSUMABLE_TABLE, false);
		Town();
	}
	else if (stage == 120) {
		Rest(PC, 120, UIS, IMAGES);
		Dialog(PC, DIALOGS.find("RestToStankrat.txt")->second.GetImage(), UIS, WEAPON_TABLE, ARMOR_TABLE, CONSUMABLE_TABLE, false);
		Encounter stankratEncounter = Encounter(PC, ENEMIES.find("Stankrat")->second, UIS);
		Dialog(PC, DIALOGS.find("SewerToTown.txt")->second.GetImage(), UIS, WEAPON_TABLE, ARMOR_TABLE, CONSUMABLE_TABLE, false);
		Town();
	}
}


void LoadGame(SaveGame save) {
	PC = save.GetPC();

	if (save.GetStage() == 110 || save.GetStage() == 120) {
		Sewer(save.GetStage());
	}
	else if (save.GetStage() == 200) {
		Town();
	}
	else if (save.GetStage() == 300) {
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

void NewGame() {
	Dialog(PC, DIALOGS.find("Intro.txt")->second.GetImage(), UIS, WEAPON_TABLE, ARMOR_TABLE, CONSUMABLE_TABLE, false);
	PC = Character(UIS);
	PC.SetArmor(ARMOR_TABLE.find("Clothes")->second);
	PC.SetWeapon(WEAPON_TABLE.find("Fists")->second);
	LAST_SAVE = SaveGame(PC, 110, SAVE_DIR);
	Sewer(110);
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
		}
		else if (strcmp(userInput.c_str(), "2") == 0) {
			LoadGameMenu();
		}
		else if (strcmp(userInput.c_str(), "3") == 0) {
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
    //SetConsoleTitle("Chains of Content");
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