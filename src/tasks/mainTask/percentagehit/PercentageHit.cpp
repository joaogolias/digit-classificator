#include "PercentageHit.h"
#include "../../../helpers/filehelper/FileHelper.h"
#include "../../../helpers/timehelper/TimeHelper.h"
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

void PercentageHit::execute(Matrix **W, Matrix *A, Matrix *answer, int ndig_treino, int p)
{
  QrFactorization *qr = new QrFactorization();
  TriangularSystemsSolver *solver = new TriangularSystemsSolver();
  FileHelper *fileHelper = new FileHelper();
  Learning *learning = new Learning();
  TimeHelper *timeHelper = new TimeHelper();
  TimeHelper *timeHelper2 = new TimeHelper();

  // define o vetor com os valores da classificação dos digitos
  Matrix *digit = new Matrix(N_TEST, 1);

  // define o vetor com os erros relativos de cada classificação
  Matrix *lowestError = new Matrix(N_TEST, 1);
  string s;

  string *times = new string[10];

  timeHelper2->start();

  Matrix  *Hd, *c;
  Matrix* A_copy = new Matrix(A->rows, A->columns);
  Matrix* differences = new Matrix(A->rows, A->columns);
  Matrix* WdH = new Matrix(W[0]->rows, A->columns);
  

  for (int d = 0; d < 10; d++){
    timeHelper->start();

    A->copyTo(A_copy);

    // resolve o sistema Wd*H = A
    qr->execute(W[d], A_copy);
    Hd = solver->solveSystems(W[d], A_copy);

    // realiza a determinação do erro de das classifições e monta 
    // o vetor c 
    W[d]->multiply(Hd, WdH);
    A_copy->subtract(WdH, differences);
    c = differences->calculateCErroVector();

    // verifica o menor erro e assume como o dígito correto
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

    timeHelper->end();
    times[d] = timeHelper->generateStringTime();
  }

  timeHelper2->end();

  string totalSpentTime = timeHelper2->generateStringTime();

  // escrevendo o arquivo com os resultados dos testes
  for (int i = 0; i < N_TEST; i++)
  {
    s += to_string(i) + string(": ") + to_string(digit->at(i, 0)) + string("\n");
  }

  string fileName = "./results-for-ndig="+to_string(ndig_treino)+"p="+to_string(p)+ ".txt";
  fileHelper->writeFile(
      fileName,
      s);

  string percentageResults = "";
  string *percentageResultsRef = &percentageResults;

  // escrevendo o arquivo com as porcentagens de acertos
  calculatePercentageHits(digit, answer, percentageResultsRef, ndig_treino, p);
  generateTotalTimeStringToSave(times, totalSpentTime, percentageResultsRef);
  fileName = "./result-percentage-hit-for-ndig="+to_string(ndig_treino)+"p="+to_string(p)+ ".txt";

  fileHelper->writeFile(
    fileName,
    percentageResults);

  delete qr;
  delete solver;
  delete fileHelper;
  delete digit;
  delete lowestError;
  delete A_copy;
  delete Hd;
  delete c;
}


void PercentageHit::calculatePercentageHits(Matrix* digit, Matrix* answer, string* s, int ndig_treino, int p) {
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


  *s += "*******************************************************************\n";
  *s += string("Número de digitos para treino: ") + to_string(ndig_treino) + string("\n");
  *s += string("Número de colunas da decomposição de A [p]: ") + to_string(p) + string("\n\n\n");

  *s += "Porcentagem de acerto para o digito 0: " + to_string(digit0PercentageHit) + "% (" + to_string(digit0rightAnswer) + "/" + to_string(digit0totalAnswer) + ")\n";
  *s += "Porcentagem de acerto para o digito 1: " + to_string(digit1PercentageHit) + "% (" + to_string(digit1rightAnswer) + "/" + to_string(digit1totalAnswer) + ")\n";
  *s += "Porcentagem de acerto para o digito 2: " + to_string(digit2PercentageHit) + "% (" + to_string(digit2rightAnswer) + "/" + to_string(digit2totalAnswer) + ")\n";
  *s += "Porcentagem de acerto para o digito 3: " + to_string(digit3PercentageHit) + "% (" + to_string(digit3rightAnswer) + "/" + to_string(digit3totalAnswer) + ")\n";
  *s += "Porcentagem de acerto para o digito 4: " + to_string(digit4PercentageHit) + "% (" + to_string(digit4rightAnswer) + "/" + to_string(digit4totalAnswer) + ")\n";
  *s += "Porcentagem de acerto para o digito 5: " + to_string(digit5PercentageHit) + "% (" + to_string(digit5rightAnswer) + "/" + to_string(digit5totalAnswer) + ")\n";
  *s += "Porcentagem de acerto para o digito 6: " + to_string(digit6PercentageHit) + "% (" + to_string(digit6rightAnswer) + "/" + to_string(digit6totalAnswer) + ")\n";
  *s += "Porcentagem de acerto para o digito 7: " + to_string(digit7PercentageHit) + "% (" + to_string(digit7rightAnswer) + "/" + to_string(digit7totalAnswer) + ")\n";
  *s += "Porcentagem de acerto para o digito 8: " + to_string(digit8PercentageHit) + "% (" + to_string(digit8rightAnswer) + "/" + to_string(digit8totalAnswer) + ")\n";
  *s += "Porcentagem de acerto para o digito 9: " + to_string(digit9PercentageHit) + "% (" + to_string(digit9rightAnswer) + "/" + to_string(digit9totalAnswer) + ")\n";

  *s += "\nPorcentagem de acerto: " + to_string(rightAnswer * 100.0 / (totalAnswer)) + "% (" + to_string(rightAnswer) + "/" + to_string(totalAnswer) + ")";
}

void PercentageHit::generateTotalTimeStringToSave(string* times, string totalTime, string *s){
  *s += "\n\n";
  *s += "Tempo para testar os números com o dígito 0: " + times[0] + "\n";
  *s += "Tempo para testar os números com o dígito 1: " + times[1] + "\n";
  *s += "Tempo para testar os números com o dígito 2: " + times[2] + "\n";
  *s += "Tempo para testar os números com o dígito 3: " + times[3] + "\n";
  *s += "Tempo para testar os números com o dígito 4: " + times[4] + "\n";
  *s += "Tempo para testar os números com o dígito 5: " + times[5] + "\n";
  *s += "Tempo para testar os números com o dígito 6: " + times[6] + "\n";
  *s += "Tempo para testar os números com o dígito 7: " + times[7] + "\n";
  *s += "Tempo para testar os números com o dígito 8: " + times[8] + "\n";
  *s += "Tempo para testar os números com o dígito 9: " + times[9] + "\n";

  *s += "\nTempo total para usado no teste: "  + totalTime;
}