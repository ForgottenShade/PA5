#include<iostream>
#include<fstream>
#include<string>
#include"Asset.h"

namespace fs = std::filesystem;
using namespace std;

class Image:public Asset {
private:
	string Img;
public:
	Image(fs::path);
	Image():Asset(){};

	string GetImage();
	string GetFilename();
	string GetPath();
};

string GetFileContents(ifstream& file)
{
	string lines = "";								//All lines

	if (file)										//Check if everything is good
	{
		while (file.good())
		{
			string tempLine;						//Temp line
			getline(file, tempLine);				//Get temp line
			tempLine += "\n";						//Add newline character

			lines += tempLine;						//Add newline
		}
		return lines;
	}
	else											//Return error
	{
		return "ERROR File does not exist.";
	}
}

Image::Image(fs::path path):Asset(path) {
	ifstream reader(Asset::GetPath());
	Img = GetFileContents(reader);
	reader.close();
}

string Image::GetImage() {
	return Img;
}

string Image::GetFilename() {
	return Asset::GetFilename();
}

string Image::GetPath() {
	return Asset::GetPath();
}