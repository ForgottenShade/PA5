#ifndef _IMAGE_
#define _IMAGE_

#include<iostream>
#include<fstream>
#include<filesystem>
#include<string>
#include"GameFile.h"

namespace fs = std::filesystem;
using namespace std;

class Image:public GameFile {
private:
	string Img;
public:
	Image(fs::path);
	Image() = default;
	~Image() = default;

	string GetFileContents(ifstream&);
	string GetImage();
	string GetFilename();
	string GetPath();
};

#endif
