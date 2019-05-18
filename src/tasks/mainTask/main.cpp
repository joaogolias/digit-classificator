#include <iostream>
#include <string>
#include "./train/Train.h"
#include "../../helpers/filehelper/FileHelper.h"

using namespace std;

Train* train = new Train();

string generateFileName(int argc, char* fileName, int p, int ndigTraina);

int main(int argc, char *argv[]){
       if(argc < 3){
            cout << "You must provide ndigTrain and p!" << endl;
            return 0;
       }

       int ndigTrain = atoi(argv[1]);
       int p = atoi(argv[2]);
       
       string fileName = generateFileName(argc, argv[3], p, ndigTrain);

       FileHelper *fileHelper = new FileHelper();
       
       string text;
       string* textRef = &text;
       
       train->execute(ndigTrain, p, textRef);

       fileHelper->writeFile(
                fileName, 
                text);
       
       return 0;
}

string generateFileName(int argc, char* input, int p, int ndigTrain){
        string fileName = "/Users/joaogolias/Documents/Personal Projects/C++/digit-classificator/";
        if(argc == 4) {
                fileName += string(input);
        } else {
               fileName += string("training-information-") + string("ndig=") + to_string(ndigTrain);
               fileName += string("p=") + to_string (p) + string(".txt");
        }
        return fileName;
}
