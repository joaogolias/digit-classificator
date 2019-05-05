#ifndef FIRSTTASK_H
#define FIRSTTASK_H
#include "../../../src/modules/basic/matrix/Matrix.h"

class Matrix;

class FirstTask {
    public:
        Matrix* resultOfExerciseA(Matrix* w, Matrix *b);
        Matrix* resultOfExerciseB(Matrix* w, Matrix *b);
        Matrix* resultOfExerciseC(Matrix* w, Matrix *a);
        Matrix* resultOfExerciseD(Matrix* w, Matrix *a);
};
#endif