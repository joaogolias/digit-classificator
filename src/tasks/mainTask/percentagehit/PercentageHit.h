#ifndef PERCENTAGEHIT_H
#define PERCENTAGEHIT_H
#include "../../../modules/basic/matrix/Matrix.h"
#include <string>

using namespace std;

class Matrix;

class PercentageHit{
  public:
    PercentageHit();
    ~PercentageHit();
    void execute(Matrix** W, Matrix* A, Matrix* answer, int ndig_treino, int p);
    void calculatePercentageHits(Matrix* digit, Matrix* answer, string* s, int ndig_treino, int p);
    void generateTotalTimeStringToSave(string* times, string totalTime, string *s);
};

#endif
