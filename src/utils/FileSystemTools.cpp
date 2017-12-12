#include "dirent.h"
#include "FileSystemTools.h"

using namespace std;

vector<string> FileSystemTools::listElementsInDir(string target) {
    vector<string> elements;
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(target.c_str())) != nullptr) {
	while ((ent = readdir(dir)) != nullptr) {
	    elements.push_back(ent->d_name);
	}
	closedir(dir);
    }
    return elements;
}
