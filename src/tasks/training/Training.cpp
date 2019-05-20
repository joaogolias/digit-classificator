#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <fstream>
#include <math.h>
#include "../../helpers/filehelper/FileHelper.h"
#include "../../helpers/timehelper/TimeHelper.h"
#include "../../modules/learning/Learning.h"
#include "../../modules/imageprocessor/ImageProcessor.h"
#include "../../modules/factorization/alternatingLeastSquares/NonNegativeFactorization.h"
#include "../../modules/classificator/Classificator.h"

#define VECTOR_ROWS 784

using namespace std;

int main()
{
    TimeHelper *timehelper = new TimeHelper();
    try
    {
        FileHelper *fileHelper = new FileHelper();
        Learning *learning = new Learning();
        ImageProcessor *imageProcessor = new ImageProcessor();
        NonNegativeFactorization *factorization = new NonNegativeFactorization();
        Classificator *classificator = new Classificator();

        timehelper->start();

        char *fileName = "/Users/joaogolias/Documents/Personal Projects/C++/digit-classificator/train_dig2.txt";

        int n_dig_treino = 100;

        Matrix *A = fileHelper->readSampleMatrix(fileName, n_dig_treino);

        Matrix **images = learning->getImages(A, 28, 28, n_dig_treino);

        //images[0]->print();
        //
        // for(int k =0 ; k < n_dig_treino; k++) {
        //     string s = string("pic") + to_string(2*k+2) + string(".ppm");
        //     ofstream img (s);
        //     img << "P3" << endl;
        //     img << 28 << " " << 28 << endl;
        //     img << "2295" << endl;
        //     for(int i = 0; i < images[k]->rows; i++){
        //         for (int j = 0; j < images[k]->columns; j++){
        //             cout << "i: " << i << " j: " << j << "value: " << images[k]->at(i,j) << endl;
        //             cout << (int)((images[k]->at(i,j))*255) << " " << (int)((images[k]->at(i,j))*255) << " " << (int)((images[k]->at(i,j))*255) << endl;
        //
        //             img << 0 << (int)(images[k]->at(i,j))*100 << 0 << " " << (int)(images[k]->at(i,j))*255 << endl;
        //         }
        //     }
        //     string openCommand = string("open ") + s;
        //     system(openCommand.c_str());
        // }

        Matrix *W = learning->execute(A, n_dig_treino, 10);
        images = learning->getImages(W, 28, 28, 10);
        // images[0]->print();

        // for (int k = 0; k < 10; k++)
        // {
        //     string s = string("pic") + to_string(k) + string(".ppm");
        //     ofstream img(s);
        //     img << "P3" << endl;
        //     img << 28 << " " << 28 << endl;
        //     img << "255" << endl;
        //     for (int i = 0; i < images[k]->rows; i++)
        //     {
        //         for (int j = 0; j < images[k]->columns; j++)
        //         {
        //             img << (int)(abs(255 - (images[k]->at(i, j)) * 255)) << " " << (int)(abs(255 - (images[k]->at(i, j)) * 255)) << " " << (int)(abs(255 - (images[k]->at(i, j)) * 255)) << endl;
        //         }
        //     }
        //     string openCommand = string("open ") + s;
        //     system(openCommand.c_str());
        // }
        return 0;
    }
    catch (std::invalid_argument *e)
    {
        timehelper->end();
        cout << timehelper->generateStringTime() << endl;
        return 0;
    }

    return 0;
}
