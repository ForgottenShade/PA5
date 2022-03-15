#ifndef _ASSET_
#define _ASSET_

#include <string>
#include<filesystem>

namespace fs = std::filesystem;
using namespace std;

class Asset {
private:
	string filename;
	string path;

public:
	Asset(fs::path);
	Asset();

	string GetFilename();
	string GetPath();
};

#endif