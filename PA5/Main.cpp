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

void NewGame() {
	PC = Character(UIS);
}

void LoadGame() {

}

void StartMenu() {
	string userInput;

	while (true) {
		system("CLS");
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
	StartMenu();
	return 1;
}