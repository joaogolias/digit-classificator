#include "./FirstTask.h"
#include <iostream>

using namespace std;

FirstTask *firstTask = new FirstTask();

void runExerciseA(bool printResult);
void runExerciseB(bool printResult);
void runExerciseC(bool printResult);
void runExerciseD(bool printResult);

int main() {
    runExerciseA(false);
    runExerciseB(true);
    runExerciseC(false);
    runExerciseD(true);
}

void runExerciseA(bool printResult) {
    int w_size = 64;
    Matrix *W = new Matrix(w_size,w_size);
    Matrix *b = new Matrix(w_size,1);

    Matrix* x = firstTask->resultOfExerciseA(W,b);

    cout << endl << "Exercise approximate A answer is: ";
    if(printResult) x->print();

    Matrix* b_from_x = W->multiply(x);


    b_from_x->copy();
    
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

void runExerciseC(bool printResult) {
    Matrix *W = new Matrix(64,64);
    Matrix *A = new Matrix(64,3);

    Matrix*H  = firstTask->resultOfExerciseC(W,A);

    cout << endl << "Exercise approximate C answer is correct, ";

    Matrix* HfromX = W->multiply(H);

    if(HfromX->isEqualsTo(A)) {
        cout << "because W*X = A" << endl;
    } else {
        cout << "but W*H != b" << endl;
    }
    cout << "Norm: "<<  A->subtract(W->multiply(H))->calculateFrobeniusNorm() << endl;
}

void runExerciseD(bool printResult) {
    Matrix *W = new Matrix(20,17);
    Matrix *A = new Matrix(20,3);

    Matrix* H = firstTask->resultOfExerciseD(W,A);

    cout << endl << "Exercise approximate D answer is correct, ";

    Matrix* HfromX = W->multiply(H);

    if(HfromX->isEqualsTo(A)) {
        cout << "because W*X = b" << endl;
    } else {
        cout << "but W*X != b" << endl;
    }
    cout << "Norm: "<<  A->subtract(W->multiply(H))->calculateFrobeniusNorm() << endl;
}