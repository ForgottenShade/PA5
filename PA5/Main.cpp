#include<iostream>
#include <fstream>
#include<string>
#include<vector>
#include<tuple>
#include<cstring>
#include<filesystem>
#include<map>
#include"Image.h"

namespace fs = std::filesystem;
using namespace std;

string ASSET_DIR = fs::current_path().string() + "\\Assets";
string IMAGE_DIR = ASSET_DIR + "\\Images";
map<string, Image> IMAGES;

void LoadAssets() {
	//Load Images
	for (const auto& entry : fs::directory_iterator(IMAGE_DIR)) {
		Image newImage = Image(entry.path());
		IMAGES.insert(pair<string, Image>(newImage.GetFilename(), newImage));
	}

}

void StartMenu() {
	cout << IMAGES.find("Mountains01.txt")->second.GetImage() << endl;
	cout << IMAGES.find("Welcome.txt")->second.GetImage() << endl;
}

int main() {

	LoadAssets();
	StartMenu();


	return 1;
}