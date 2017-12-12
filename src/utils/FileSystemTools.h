#ifndef SRC_FILESYSTEMTOOLS_H_
#define SRC_FILESYSTEMTOOLS_H_

#include <vector>
#include <string>

using namespace std;

class FileSystemTools {
public:
    FileSystemTools(){};
    virtual ~FileSystemTools(){};
    
    vector<string> listElementsInDir(string);
};

#endif /* SRC_FILESYSTEMTOOLS_H_ */
