#ifndef _IMAGE_
#define _IMAGE_

#include<iostream>
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
	Image();

	string GetFileContents(ifstream&);
	string GetImage();
	string GetFilename();
	string GetPath();
};

#endif
