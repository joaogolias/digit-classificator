#include <iostream>
#include "./train/Train.h"
#include "../../helpers/filehelper/FileHelper.h"

using namespace std;

Train* train = new Train();

int main(){
    FileHelper *fileHelper = new FileHelper();
    string text;
    string* textRef = &text;
    train->execute(100, 5, textRef);

    // train->execute(1000, 5);

    // train->execute(4000, 5);

    train->execute(100, 10, textRef);

    // train->execute(1000, 10);

    // train->execute(4000, 10);

    train->execute(100, 15, textRef);

    // train->execute(1000, 15);

    // train->execute(4000, 15, textRef);

    fileHelper->writeFile(
        "/Users/joaogolias/Documents/Personal Projects/C++/digit-classificator/training_information.txt", 
        text);
}