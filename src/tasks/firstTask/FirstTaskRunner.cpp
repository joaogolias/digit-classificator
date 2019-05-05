#include "./FirstTask.h"
#include <iostream>

using namespace std;

FirstTask *firstTask = new FirstTask();

void runExerciseA(bool printResult);
void runExerciseB(bool printResult);

int main() {
    runExerciseA(false);
    runExerciseB(true);
}

void runExerciseA(bool printResult) {
    int w_size = 64;
    Matrix *W = new Matrix(w_size,w_size);
    Matrix *b = new Matrix(w_size,1);

    Matrix* x = firstTask->resultOfExerciseA(W,b);

    cout << endl << "Exercise approximate A answer is: ";
    if(printResult) x->print();

    Matrix* b_from_x = W->multiply(x);

    if(b_from_x->isEqualsTo(b)) {
        cout << "Correct, because W*X = b" << endl;
    } else {
        cout << "Wrong, because W*X != b" << endl;
    }

}

void runExerciseB(bool printResult) {
    Matrix *W = new Matrix(20,17);
    Matrix *b = new Matrix(20,1);

    Matrix* x = firstTask->resultOfExerciseB(W,b);

    cout << endl << "Exercise approximate B answer can be correct, ";

    Matrix* b_from_x = W->multiply(x);

    if(b_from_x->isEqualsTo(b)) {
        cout << "because W*X = b" << endl;
    } else {
        cout << "but W*X != b" << endl;
    }
    cout << "Norm: "<<  b->subtract(W->multiply(x))->calculateFrobeniusNorm() << endl;
}