#include <iostream>
#include "../../testmanager/TestManager.h"
#include "../../../src/modules/basic/matrix/Matrix.h"
#include "../../../src/modules/factorization/qr/QrFactorization.h"
#include "../../../src/modules/imageProcessor/ImageProcessor.h"

void firstTest();
void secondTest();
void thirdTest();

void firstTestOfJoinVectors();
void secondTestOfJoinVectors();
void thirdTestOfJoinVectors();

void firstTextOfNormalize();

void firstTextOfUnnormalize();

void firstTextExecute();
void secondTextExecute();

using namespace std;

ImageProcessor* imgprocessor = new ImageProcessor();
int main() {
    firstTest();
    secondTest();
    thirdTest();

    firstTestOfJoinVectors();
    secondTestOfJoinVectors();
    thirdTestOfJoinVectors();

    firstTextOfNormalize();

    firstTextOfUnnormalize();

    firstTextExecute();
    secondTextExecute();
}

void firstTest() {
    cout << endl << endl << endl << "FirstTest" << endl;
    Matrix* M = new Matrix(3,3);
    double Mvalues[3][3] = {{1,4,7},{2,5,8},{3,6,9}};
    for(int i = 0; i < 3; i++) {
        M->setRow(i, Mvalues[i], 3);
    }
    cout << "v: " << endl;
    Matrix* v = imgprocessor->generateVector(M);
    v->print();

    cout << "M: " << endl;
    M = imgprocessor->regenerateMatrix(v, 3, 3);
    M->print();
}

void secondTest() {
    cout << endl << endl << endl << "SecondTest" << endl;
    Matrix* M = new Matrix(2,3);
    double Mvalues[2][3] = {{1,3,5},{2,4,6}};
    for(int i = 0; i < 2; i++) {
        M->setRow(i, Mvalues[i], 3);
    }
    cout << "v: " << endl;
    Matrix* v = imgprocessor->generateVector(M);
    v->print();

    cout << "M: " << endl;
    M = imgprocessor->regenerateMatrix(v, 2, 3);
    M->print();
}

void thirdTest() {
    cout << endl << endl << endl << "ThirdTest" << endl;
    Matrix* M = new Matrix(3,2);
    double Mvalues[3][2] = {{1,4},{2,5}, {3,6}};
    for(int i = 0; i < 3; i++) {
        M->setRow(i, Mvalues[i], 2);
    }

    cout << "v: " << endl;
    Matrix* v = imgprocessor->generateVector(M);
    v->print();

    cout << "M: " << endl;
    M = imgprocessor->regenerateMatrix(v, 3, 2);
    M->print();
}

void firstTestOfJoinVectors(){
    cout << endl << endl << "FistTest of JoinVectors" << endl;
    
    Matrix* v1 = new Matrix(3,1);
    double v1Values[3][1] = {{1},{4},{7}};
    for(int i = 0; i < 3; i++) {
        v1->setRow(i, v1Values[i], 1);
    }

    Matrix* v2 = new Matrix(3,1);
    double v2Values[3][1] = {{2},{5},{8}};
    for(int i = 0; i < 3; i++) {
        v2->setRow(i, v2Values[i], 1);
    }

    Matrix* v3 = new Matrix(3,1);
    double v3Values[3][1] = {{3},{6},{9}};
    for(int i = 0; i < 3; i++) {
        v3->setRow(i, v3Values[i], 1);
    }

    Matrix** vectors = new Matrix*[3];
    vectors[0] = v1;
    vectors[1] = v2;
    vectors[2] = v3;

    Matrix* M = imgprocessor->joinVectors(vectors,3);
    M->print();

    vectors = imgprocessor->splitVectors(M);
    for(int i = 0; i < 3; i++){
        cout << endl << "v" << i+1 << ": " << endl;
        vectors[i]->print();
    }
}

void secondTestOfJoinVectors(){
    cout << endl << endl << "SecondTest of JoinVectors" << endl;
    
    Matrix* v1 = new Matrix(3,1);
    double v1Values[3][1] = {{1},{3},{5}};
    for(int i = 0; i < 3; i++) {
        v1->setRow(i, v1Values[i], 1);
    }


    Matrix* v2 = new Matrix(3,1);
    double v2Values[3][1] = {{2},{4},{6}};
    for(int i = 0; i < 3; i++) {
        v2->setRow(i, v2Values[i], 1);
    }

    Matrix** vectors = new Matrix*[2];
    vectors[0] = v1;
    vectors[1] = v2;

    Matrix* M = imgprocessor->joinVectors(vectors,2);
    M->print();

    vectors = imgprocessor->splitVectors(M);
    for(int i = 0; i < 2; i++){
        cout << endl << "v" << i+1 << ": " << endl;
        vectors[i]->print();
    }
}


void thirdTestOfJoinVectors(){
    cout << endl << endl << "ThirdTest of JoinVectors" << endl;
    
    Matrix* v1 = new Matrix(2,1);
    double v1Values[2][1] = {{1},{4}};
    for(int i = 0; i < 2; i++) {
        v1->setRow(i, v1Values[i], 1);
    }


    Matrix* v2 = new Matrix(2,1);
    double v2Values[2][1] = {{2},{5}};
    for(int i = 0; i < 2; i++) {
        v2->setRow(i, v2Values[i], 1);
    }

    Matrix* v3 = new Matrix(2,1);
    double v3Values[2][1] = {{3},{6}};
    for(int i = 0; i < 2; i++) {
        v3->setRow(i, v3Values[i], 1);
    }

    Matrix** vectors = new Matrix*[3];
    vectors[0] = v1;
    vectors[1] = v2;
    vectors[2] = v3;

    Matrix* M = imgprocessor->joinVectors(vectors,3);
    M->print();

    vectors = imgprocessor->splitVectors(M);
    for(int i = 0; i < 3; i++){
        cout << endl << "v" << i+1 << ": " << endl;
        vectors[i]->print();
    }
}


void firstTextOfNormalize(){
    cout << endl << endl << "FirstTest of Normalize" << endl;
    
    Matrix* M = new Matrix(3,3);
    double Mvalues[3][3] = {{255, 127.5, 0}, {255, 127.5, 0}, {255, 127.5, 0}};
    for(int i = 0; i < 3; i++) {
        M->setRow(i, Mvalues[i], 3);
    }

    imgprocessor->normalize(M);
    M->print();
}

void firstTextOfUnnormalize(){
    cout << endl << endl << "FirstTest of Unnormalize" << endl;
    
    Matrix* M = new Matrix(3,3);
    double Mvalues[3][3] = {{1, 0.5, 0}, {1, 0.5, 0}, {1, 0.5, 0}};
    for(int i = 0; i < 3; i++) {
        M->setRow(i, Mvalues[i], 3);
    }

    imgprocessor->unnormalize(M);
    M->print();
}

void firstTextExecute() {
    cout << endl << endl << "FirstTest of execute" << endl;
    int imageQuantity = 2;
    Matrix** images = new Matrix*[imageQuantity];

    Matrix* img0 = new Matrix(3,3);
    double img0Values[3][3] = {{255, 127.5, 0}, {255, 127.5, 0}, {255, 127.5, 0}};
    for(int i = 0; i < 3; i++) {
        img0->setRow(i, img0Values[i], 3);
    }

    images[0] = img0;

    Matrix* img1 = new Matrix(3,3);
    double img1Values[3][3] = {{0, 127.5, 255}, {0, 127.5, 255}, {0, 127.5, 255}};
    for(int i = 0; i < 3; i++) {
        img1->setRow(i, img1Values[i], 3);
    }

    images[1] = img1;

    imgprocessor -> execute(images, imageQuantity, true, 3, 3);
}

void secondTextExecute() {
    cout << endl << endl << "SecondTest of execute" << endl;
    int imageQuantity = 3;
    Matrix** images = new Matrix*[imageQuantity];

    Matrix* img0 = new Matrix(2,3);
    double img0Values[2][3] = {{255, 127.5, 0}, {255, 127.5, 0}};
    for(int i = 0; i < 2; i++) {
        img0->setRow(i, img0Values[i], 3);
    }

    images[0] = img0;

    Matrix* img1 = new Matrix(2,3);
    double img1Values[2][3] = {{0, 127.5, 255}, {0, 127.5, 255}};
    for(int i = 0; i < 2; i++) {
        img1->setRow(i, img1Values[i], 3);
    }

    images[1] = img1;


    Matrix* img2 = new Matrix(2,3);
    double img2Values[2][3] = {{63.75, 127.5, 0}, {63.75, 127.5, 0}};
    for(int i = 0; i < 2; i++) {
        img2->setRow(i, img2Values[i], 3);
    }

    images[2] = img2;

    imgprocessor -> execute(images, imageQuantity, true, 2, 3);
}