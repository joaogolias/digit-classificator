#include <iostream>
#include "./train/Train.h"


using namespace std;

Train* train = new Train();

int main(){
    train->execute(5, 5);
}