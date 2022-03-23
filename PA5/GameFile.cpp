#include <string>
#include <filesystem>
#include "GameFile.h"
namespace fs = std::filesystem;
using namespace std;

GameFile::GameFile(fs::path path) {
	Path = path.string();
	Filename = path.string().substr(path.string().find_last_of("/\\") + 1);
}

string GameFile::GetFilename() {
	return Filename;
}

string GameFile::GetPath() {
	return Path;
}