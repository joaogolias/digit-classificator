#include "PercentageHit.h"
#include "../../../helpers/filehelper/FileHelper.h"
#include "../../../modules/learning/Learning.h"
#include "../../../modules/factorization/qr/QrFactorization.h"
#include "../../../modules/systems/triangularsystemssolver/TriangularSystemsSolver.h"
#include <fstream>
#include <iostream>

using namespace std;

#define N_TEST 10000
PercentageHit::PercentageHit()
{
}

PercentageHit::~PercentageHit() {}

void PercentageHit::execute(Matrix **W, Matrix *A, Matrix *answer)
{
  QrFactorization *qr = new QrFactorization();
  TriangularSystemsSolver *solver = new TriangularSystemsSolver();
  FileHelper *fileHelper = new FileHelper();
  Learning *learning = new Learning();

  Matrix *digit = new Matrix(N_TEST, 1);
  Matrix *lowestError = new Matrix(N_TEST, 1);

  string s;

  Matrix *Wd_copy, *A_copy, *Hd, *c;
  for (int d = 0; d < 10; d++){

    Wd_copy = W[d]->copy();
    A_copy = A->copy();

    qr->execute(Wd_copy, A_copy);

    Hd = solver->solveSystems(Wd_copy, A_copy);

    c = A_copy->subtract(Wd_copy->multiply(Hd))->calculateCErroVector();

    if (d == 0)
    {
      lowestError = c->copy();
    }
    else
    {
      for (int i = 0; i < N_TEST; i++)
      {
        if (c->at(i, 0) < lowestError->at(i, 0))
        {
          lowestError->set(i, 0, c->at(i, 0));
          digit->set(i, 0, d);
        }
      }
    }
  }

  for (int i = 0; i < N_TEST; i++)
  {
    s += to_string(i) + string(": ") + to_string(digit->at(i, 0)) + string("\n");
  }

  int rightAnswer = 0;
  int totalAnswer = 0;

  for (int i = 0; i < digit->rows; i++)
  {
    if (digit->at(i, 0) == answer->at(i, 0))
    {
      rightAnswer++;
    }
    totalAnswer++;
  }

  cout << "Porcentagem de acerto: " << rightAnswer * 100.0 / (totalAnswer) << "% (" << rightAnswer << "/" << totalAnswer << ")" << endl;

  fileHelper->writeFile(
      "/Users/joaogolias/Documents/Personal Projects/C++/digit-classificator/results.txt",
      s);

  // delete qr;
  // delete solver;
  // delete fileHelper;
  // delete digit;
  // delete lowestError;
  // delete Wd_copy;
  // delete A_copy;
  // delete Hd;
  // delete c;
}