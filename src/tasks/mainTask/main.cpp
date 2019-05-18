#include <iostream>
#include "./train/Train.h"


using namespace std;

Train* train = new Train();

int main(){
    train->execute(100, 5);

    train->execute(1000, 5);

    train->execute(4000, 5);

    train->execute(100, 10);

    train->execute(1000, 10);

    train->execute(4000, 10);

    train->execute(100, 15);

    train->execute(1000, 15);

    train->execute(4000, 15);
}