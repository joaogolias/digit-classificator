#ifndef PERCENTAGEHIT_H
#define PERCENTAGEHIT_H
#include "../../../modules/basic/matrix/Matrix.h"

class Matrix;

class PercentageHit{
  public:
    PercentageHit();
    ~PercentageHit();
    void execute(Matrix** W, Matrix* A, Matrix* answer);
    // void calculatePercentageHits();
};

#endif
