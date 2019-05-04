#include "./FirstTask.h"
#include <iostream>

using namespace std;

FirstTask *firstTask = new FirstTask();

void runExerciseA(bool printResult);

int main() {
    runExerciseA(false);
}

void runExerciseA(bool printResult) {
    int w_size = 64;
    Matrix *W = new Matrix(64,64);
    Matrix *b = new Matrix(64,1);

    Matrix* x = firstTask->exerciseResultA(W,b,false);

    cout << endl << "Exercise approximate A answer is: ";
    if(printResult) x->print();

    Matrix* b_from_x = W->multiply(x);

    if(b_from_x->isEqualsTo(b)) {
        cout << "Correct, because W*X = b" << endl;
    } else {
        cout << "Wrong, because W*X != b" << endl;
    }

}