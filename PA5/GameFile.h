#ifndef _ASSET_
#define _ASSET_

#include <string>
#include<filesystem>

namespace fs = std::filesystem;
using namespace std;

class GameFile {
private:
	string Filename;
	string Path;

public:
	GameFile(fs::path);
	GameFile() = default;
	~GameFile() = default;

	string GetFilename();
	string GetPath();
};

#endif