#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<tuple>
#include<cstring>
#include<filesystem>
#include<map>
#include<stdlib.h>

#include"Image.h"
#include"Weapon.h"
#include"Armor.h"
#include"Consumable.h"
#include"Character.h"
#include"Encounter.h"
#include "Dialog.h"
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
	Weapon* Club = new Weapon();
	Weapon* Axe = new Weapon();
	Weapon* Shortbow = new Weapon();
	Weapon* Shortsword = new Weapon("Shortsword", 10, 1, 6, 1, false);
	Weapon* Dagger = new Weapon();
	Weapon* Quarterstaff = new Weapon();

			//Uncommon: 2
	Weapon* Crossbow = new Weapon();
	Weapon* Longbow = new Weapon();
	Weapon* Longsword = new Weapon();
	Weapon* Mace = new Weapon();
	Weapon* Spear = new Weapon();

			//Rare: 3
	Weapon* Greatsword = new Weapon();
	Weapon* Greataxe = new Weapon();
	Weapon* Greathammer = new Weapon();
	Weapon* Rapier = new Weapon();

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
	Consumable* HealingSalve = new Consumable();
	
			//Uncommon
	Consumable* HealingPotion = new Consumable();

			//Rare
	Consumable* GreaterHealingPotion = new Consumable();

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

	//Confrontation
void Dungeon() {
	GameOver();
}

	//Self Discovery
void Town() {
	Dungeon();
}

	//Orient yourself
void Forest() {
	Town();
}

	//Escape
void Sewer() {
	Forest();
}

void NewGame() {
	//Character/story intro here

	PC = Character(UIS);
	
	
	
	//Tutorial/first combat
	PC.SetArmor(ARMOR_TABLE.find("Clothes")->second);
	PC.SetWeapon(WEAPON_TABLE.find("Shortsword")->second);
	
	//dialog(PC, DIALOGS.find("SewerToForest.txt")->second.GetImage(), UIS, 10, "Str");

	
	Encounter tutorialEncounter = Encounter(PC, ENEMIES.find("Goblin")->second, UIS);
	//Sewer();
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

int main() {
	LoadAssets();
	LoadItems();
	LoadCharacters();
	StartMenu();
	return 1;
}