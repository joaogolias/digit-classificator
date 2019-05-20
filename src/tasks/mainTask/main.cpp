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



	PercentageHit *percentageHit = new PercentageHit();

	Matrix *A = fileHelper->readSampleMatrix(
			"./test_images.txt",
			10000,
			true);

	ImageProcessor *imageProcessor = new ImageProcessor();
	imageProcessor->createImageFromColumn(A, 0, p, "minhaImagem.ppm");
      // Matrix **images = learning->getImages(A, 28, 28, 10);








      // for (int g = 0; g < 10; g++)
      // {
      //   string s = string("pic") + to_string(g) + string(".ppm");
      //   ofstream img(s);
      //   img << "P3" << endl;
      //   img << 28 << " " << 28 << endl;
      //   img << "255" << endl;
      //   for (int i = 0; i < images[g]->rows; i++)
      //   {
      //     for (int j = 0; j < images[g]->columns; j++)
      //     {
      //       if (images[g]->at(i, j) != 0)
      //       {
      //         img << 255 << " " << 255 << " " << 255 << endl;
      //       }
      //       else
      //       {
      //         img << 0 << " " << 0 << " " << 0 << endl;
      //       }
      //       // img << (int)(images[g]->at(i, j) * 255) << " " << (int)(images[g]->at(i, j) * 255) << " " << (int)((images[g]->at(i, j) * 255)) << endl;
      //     }
      //   }
      //   string openCommand = string("open ") + s;
      //   system(openCommand.c_str());
      // }

	Matrix *answer = fileHelper->readSampleMatrix(
			"./test_index.txt",
			1,
			false,
			10000);

	percentageHit->execute(Wmatrices, A, answer, ndigTrain, p);

	fileHelper->writeFile(
			fileName,
			text);

	// delete textRef;
	return 0;
}

string generateFileName(int argc, char *input, int p, int ndigTrain)
{
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
