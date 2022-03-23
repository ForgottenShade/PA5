#include<iostream>
#include<fstream>
#include<filesystem>
#include<string>
#include"GameFile.h"
#include"Image.h"

namespace fs = std::filesystem;
using namespace std;

string Image::GetFileContents(ifstream& file)
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

Image::Image(fs::path path):GameFile(path) {
	ifstream reader(GameFile::GetPath());
	Img = GetFileContents(reader);
	reader.close();
}

string Image::GetImage() {
	return Img;
}

string Image::GetFilename() {
	return GameFile::GetFilename();
}

string Image::GetPath() {
	return GameFile::GetPath();
}