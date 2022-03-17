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
#include"Character.h"

namespace fs = std::filesystem;
using namespace std;

string ASSET_DIR = fs::current_path().string() + "\\Assets";
string IMAGE_DIR = ASSET_DIR + "\\Images";
string UI_DIR = ASSET_DIR + "\\UI";
string DIALOG_DIR = ASSET_DIR + "\\Dialogs";

map<string, Image> IMAGES;
map<string, Image> UIS;
map<string, Image> DIALOGS;
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

void LoadCharacters() {
	//Enemies
	Character* rat = new Character("Beast", "Rat", IMAGES.find("Rat01.txt")->second.GetImage(), 2, 11, 9, 2, 10, 4, 1, 10, 0);
	Character* goblin = new Character("Goblin", "Goblin", IMAGES.find("Goblin01.txt")->second.GetImage(), 8, 14, 10, 10, 8, 8, 7, 15, 1);
	Character* stankrat = new Character("Goblin", "Stankrat", IMAGES.find("Stankrat01.txt")->second.GetImage(), 10, 14, 10, 10, 8, 10, 21, 17, 2);

	Character* wolf = new Character("Beast", "Wolf", IMAGES.find("Wolf01.txt")->second.GetImage(), 12, 15, 12, 3, 12, 6, 11, 13, 1);
	Character* crab = new Character("Beast", "Crabbo", IMAGES.find("Wolf01.txt")->second.GetImage(), 14, 16, 18, 1, 10, 2, 25, 12, 2);
	Character* awakened_tree = new Character("Plant", "Awakened Tree", IMAGES.find("Tree01.txt")->second.GetImage(), 19, 6, 15, 10, 10, 7, 30, 13, 3);

	ENEMIES.insert(pair<string, Character>(rat[0].GetName(), rat[0]));
	ENEMIES.insert(pair<string, Character>(goblin[0].GetName(), goblin[0]));
	ENEMIES.insert(pair<string, Character>(stankrat[0].GetName(), stankrat[0]));

	ENEMIES.insert(pair<string, Character>(wolf[0].GetName(), wolf[0]));
	ENEMIES.insert(pair<string, Character>(crab[0].GetName(), crab[0]));
	ENEMIES.insert(pair<string, Character>(awakened_tree[0].GetName(), awakened_tree[0]));

	//NPCs
}

void Sewer() {

}

void Forest() {

}

void NewGame() {
	//Character/story intro here

	PC = Character(UIS);
	//Tutorial/first combat

}

void LoadGame() {

}

void StartMenu() {
	string userInput;

	while (true) {
		system("CLS");
		cout << IMAGES.find("Crab01.txt")->second.GetImage() << endl;
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
	//LoadCharacters();
	StartMenu();
	return 1;
}