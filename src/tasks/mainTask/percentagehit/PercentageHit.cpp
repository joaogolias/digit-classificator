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

  int digit1rightAnswer = 0;
  int digit1totalAnswer = 0;
  double digit1PercentageHit = 0;

  int digit2rightAnswer = 0;
  int digit2totalAnswer = 0;
  double digit2PercentageHit = 0;

  int digit3rightAnswer = 0;
  int digit3totalAnswer = 0;
  double digit3PercentageHit = 0;

  int digit4rightAnswer = 0;
  int digit4totalAnswer = 0;
  double digit4PercentageHit = 0;




  for (int i = 0; i < digit->rows; i++)
  {
    if(answer->at(i,0) == 1) {
      if(digit->at(i,0) == answer->at(i,0)){
        digit1rightAnswer++;
      }
      digit1totalAnswer++;
    } 

    if (digit->at(i, 0) == answer->at(i, 0))
    {
      rightAnswer++;
    }
    totalAnswer++;
  }

  cout << "Porcentagem de acerto para o digito 1: " << digit1rightAnswer * 100.0 / (digit1totalAnswer) << "% (" << digit1rightAnswer << "/" << digit1totalAnswer << ")" << endl;
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


void calculatePercentageHits(Matrix* digit, Matrix* answer, string* s) {
  int rightAnswer = 0;
  int totalAnswer = 0;

  int digit0rightAnswer = 0;
  int digit0totalAnswer = 0;

  int digit1rightAnswer = 0;
  int digit1totalAnswer = 0;

  int digit2rightAnswer = 0;
  int digit2totalAnswer = 0;

  int digit3rightAnswer = 0;
  int digit3totalAnswer = 0;

  int digit4rightAnswer = 0;
  int digit4totalAnswer = 0;

  int digit5rightAnswer = 0;
  int digit5totalAnswer = 0;

  int digit6rightAnswer = 0;
  int digit6totalAnswer = 0;

  int digit7rightAnswer = 0;
  int digit7totalAnswer = 0;

  int digit8rightAnswer = 0;
  int digit8totalAnswer = 0;

  int digit9rightAnswer = 0;
  int digit9totalAnswer = 0;

  for (int i = 0; i < digit->rows; i++)
  {

    if(answer->at(i,0) == 0) {
      if(digit->at(i,0) == answer->at(i,0)){
        digit0rightAnswer++;
      }
      digit0totalAnswer++;
    }

    if(answer->at(i,0) == 1) {
      if(digit->at(i,0) == answer->at(i,0)){
        digit1rightAnswer++;
      }
      digit1totalAnswer++;
    }

    if(answer->at(i,0) == 2) {
      if(digit->at(i,0) == answer->at(i,0)){
        digit2rightAnswer++;
      }
      digit2totalAnswer++;
    } 

    if(answer->at(i,0) == 3) {
      if(digit->at(i,0) == answer->at(i,0)){
        digit3rightAnswer++;
      }
      digit3totalAnswer++;
    }

    if(answer->at(i,0) == 4) {
      if(digit->at(i,0) == answer->at(i,0)){
        digit4rightAnswer++;
      }
      digit4totalAnswer++;
    }

    if(answer->at(i,0) == 5) {
      if(digit->at(i,0) == answer->at(i,0)){
        digit5rightAnswer++;
      }
      digit5totalAnswer++;
    }

    if(answer->at(i,0) == 6) {
      if(digit->at(i,0) == answer->at(i,0)){
        digit6rightAnswer++;
      }
      digit6totalAnswer++;
    }

    if(answer->at(i,0) == 7) {
      if(digit->at(i,0) == answer->at(i,0)){
        digit7rightAnswer++;
      }
      digit7totalAnswer++;
    }

    if(answer->at(i,0) == 8) {
      if(digit->at(i,0) == answer->at(i,0)){
        digit8rightAnswer++;
      }
      digit8totalAnswer++;
    }

    if(answer->at(i,0) == 9) {
      if(digit->at(i,0) == answer->at(i,0)){
        digit9rightAnswer++;
      }
      digit9totalAnswer++;
    }

    if (digit->at(i, 0) == answer->at(i, 0))
    {
      rightAnswer++;
    }
    totalAnswer++;
  }

  double digit0PercentageHit = digit0rightAnswer*100.0/digit0totalAnswer;
  double digit1PercentageHit = digit1rightAnswer*100.0/digit1totalAnswer;
  double digit2PercentageHit = digit2rightAnswer*100.0/digit2totalAnswer;
  double digit3PercentageHit = digit3rightAnswer*100.0/digit3totalAnswer;
  double digit4PercentageHit = digit4rightAnswer*100.0/digit4totalAnswer;
  double digit5PercentageHit = digit5rightAnswer*100.0/digit5totalAnswer;
  double digit6PercentageHit = digit6rightAnswer*100.0/digit6totalAnswer;
  double digit7PercentageHit = digit7rightAnswer*100.0/digit7totalAnswer;
  double digit8PercentageHit = digit8rightAnswer*100.0/digit8totalAnswer;
  double digit9PercentageHit = digit9rightAnswer*100.0/digit9totalAnswer;

  *s += "Porcentagem de acerto para o digito 0: " + to_string(digit0PercentageHit) + "% (" + to_string(digit1rightAnswer) + "/" + to_string(digit1totalAnswer) + ")";

  cout << "Porcentagem de acerto para o digito 0: " << digit0PercentageHit << "% (" << digit1rightAnswer << "/" << digit1totalAnswer << ")" << endl;
  cout << "Porcentagem de acerto para o digito 1: " << digit1PercentageHit << "% (" << digit1rightAnswer << "/" << digit1totalAnswer << ")" << endl;
  cout << "Porcentagem de acerto para o digito 2: " << digit2PercentageHit << "% (" << digit1rightAnswer << "/" << digit1totalAnswer << ")" << endl;
  cout << "Porcentagem de acerto para o digito 3: " << digit3PercentageHit << "% (" << digit1rightAnswer << "/" << digit1totalAnswer << ")" << endl;
  cout << "Porcentagem de acerto para o digito 4: " << digit4PercentageHit << "% (" << digit1rightAnswer << "/" << digit1totalAnswer << ")" << endl;
  cout << "Porcentagem de acerto para o digito 5: " << digit5PercentageHit << "% (" << digit1rightAnswer << "/" << digit1totalAnswer << ")" << endl;
  cout << "Porcentagem de acerto para o digito 6: " << digit6PercentageHit << "% (" << digit1rightAnswer << "/" << digit1totalAnswer << ")" << endl;
  cout << "Porcentagem de acerto para o digito 7: " << digit7PercentageHit << "% (" << digit1rightAnswer << "/" << digit1totalAnswer << ")" << endl;
  cout << "Porcentagem de acerto para o digito 8: " << digit8PercentageHit << "% (" << digit1rightAnswer << "/" << digit1totalAnswer << ")" << endl;
  cout << "Porcentagem de acerto para o digito 9: " << digit9PercentageHit << "% (" << digit1rightAnswer << "/" << digit1totalAnswer << ")" << endl;
  
  
  cout << "Porcentagem de acerto: " << rightAnswer * 100.0 / (totalAnswer) << "% (" << rightAnswer << "/" << totalAnswer << ")" << endl;
}