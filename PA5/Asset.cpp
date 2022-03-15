#include <string>
#include<filesystem>

namespace fs = std::filesystem;
using namespace std;

class Asset {
private:
	string Filename;
	string Path;
public:
	Asset(fs::path);
	Asset(){};
	
	string GetFilename();
	string GetPath();
};

Asset::Asset(fs::path path) {
	Path = path.string();
	Filename = path.string().substr(path.string().find_last_of("/\\") + 1);
}

string Asset::GetFilename() {
	return Filename;
}

string Asset::GetPath() {
	return Path;
}