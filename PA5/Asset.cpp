#include <string>
#include <filesystem>
#include "Asset.h"
namespace fs = std::filesystem;
using namespace std;


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