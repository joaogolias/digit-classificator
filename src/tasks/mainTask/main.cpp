/****
 *  Nomes:
 *      	Guilherme C. Santos (9349590)
 *          João V. Golias (8992902)
 */

#include <iostream>
#include <string>
#include "./train/Train.h"
#include "./percentagehit/PercentageHit.h"
#include "../../helpers/filehelper/FileHelper.h"
#include "../../modules/imageprocessor/ImageProcessor.h"
#include "../../modules/learning/Learning.h"

using namespace std;

Train *train = new Train();

string generateFileName(int argc, char *fileName, int p, int ndigTraina);

int main(int argc, char *argv[])
{
	// lê os 3 parâmetros de entrada do programa:
	// (1) ndig train; (2) valor do p; (3) nome dos arquivos para 
	// salvar as informações desse programa

	if (argc < 3)
	{
		cout << "You must provide ndigTrain and p!" << endl;
		return 0;
	}

	int ndigTrain = atoi(argv[1]);
	int p = atoi(argv[2]);

	string fileName = generateFileName(argc, argv[3], p, ndigTrain);

	FileHelper *fileHelper = new FileHelper();

	string text;
	string *textRef = &text;

	// realiza o treino de todos os dígitos e devolve um array com os Wd
	Matrix **Wmatrices = train->execute(ndigTrain, p, textRef);
	Learning *learning = new Learning();

	PercentageHit *percentageHit = new PercentageHit();

	// lê o arquivo de teste
	Matrix *A = fileHelper->readSampleMatrix(
			"./test_images.txt",
			10000,
			true);

	ImageProcessor *imageProcessor = new ImageProcessor();

	// lê o arquvio de respostas
	Matrix *answer = fileHelper->readSampleMatrix(
			"./test_index.txt",
			1,
			false,
			10000);

	// realiza os testes e determina a porcentagem de acertos
	percentageHit->execute(Wmatrices, A, answer, ndigTrain, p);

	fileHelper->writeFile(
			fileName,
			text);

	// delete textRef;
	return 0;
}

string generateFileName(int argc, char *input, int p, int ndigTrain)
{
	// gera o nome do arquivo para salvar as informações desse programa
	string fileName = "./";
	if (argc == 4)
	{
		fileName += string(input);
	}
	else
	{
		fileName += string("training-information-") + string("ndig=") + to_string(ndigTrain);
		fileName += string("p=") + to_string(p) + string(".txt");
	}
	return fileName;
}
