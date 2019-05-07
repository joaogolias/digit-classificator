#ifndef FILEHELPER_H
#define FILEHELPER_H

class FileHelper {
    public:
        FileHelper();
        ~FileHelper();
        // char* readFile(char* name);
        // void writeFile(char* name, char* content, bool overrideFile);
        bool checkFileExists(char* name);
};
#endif