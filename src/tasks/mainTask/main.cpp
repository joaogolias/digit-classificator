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

	Matrix **Wmatrices = train->execute(ndigTrain, p, textRef);
	Learning *learning = new Learning();

	// for (int k = 0; k < 10; k++)
	// {
	// 	Matrix **images = learning->getImages(Wmatrices[k], 28, 28, p);
	// 	for (int g = 0; g < p; g++)
	// 	{
	// 		string s = string("pic") + to_string(k) + to_string(g) + string(".ppm");
	// 		ofstream img(s);
	// 		img << "P3" << endl;
	// 		img << 28 << " " << 28 << endl;
	// 		img << "255" << endl;
	// 		for (int i = 0; i < images[g]->rows; i++)
	// 		{
	// 			for (int j = 0; j < images[g]->columns; j++)
	// 			{
	// 				img << (int)(images[g]->at(i, j) * 255) << " " << (int)(images[g]->at(i, j) * 255) << " " << (int)((images[g]->at(i, j) * 255)) << endl;
	// 			}
	// 		}
	// 		string openCommand = string("open ") + s;
	// 		system(openCommand.c_str());
	// 	}
	// }

	PercentageHit *percentageHit = new PercentageHit();

	Matrix *A = fileHelper->readSampleMatrix(
			"/Users/joaogolias/Documents/Personal Projects/C++/digit-classificator/test_images.txt",
			10000,
			true);

	Matrix *answer = fileHelper->readSampleMatrix(
			"/Users/joaogolias/Documents/Personal Projects/C++/digit-classificator/test_index.txt",
			1,
			false,
			10000);

	// answer->print();

	percentageHit->execute(Wmatrices, A, answer);
	fileHelper->writeFile(
			fileName,
			text);

	// delete textRef;
	return 0;
}

string generateFileName(int argc, char *input, int p, int ndigTrain)
{
	string fileName = "/Users/joaogolias/Documents/Personal Projects/C++/digit-classificator/";
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
