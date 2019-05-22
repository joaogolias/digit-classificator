#include <iostream>
#include <fstream>
#include "ImageProcessor.h"
#include "../learning/Learning.h"


using namespace std;

ImageProcessor::ImageProcessor(){}
ImageProcessor::~ImageProcessor(){}

Matrix* ImageProcessor::generateVector(Matrix* image){
    // gera o  vetor com as colunas empilhadas da matriz <Image>
    int rows = image->rows*image->columns;
    Matrix* vector = new Matrix(rows, 1);

    for(int j = 0; j < image->columns; j++) {
        for(int i = 0; i < image -> rows; i++) {
            vector->set(j*image->rows + i, 0, image->at(i,j));
        }
    }
    return vector;
}

Matrix* ImageProcessor::regenerateMatrix(Matrix* vector, int rows, int columns){
    //  <vector> é o vetor coluna que contém as colunas empilhadas de 
    // uma matriz que representa uma imagem
    Matrix* M = new Matrix(rows, columns);
    for(int i = 0; i < rows; i ++) {
        for (int j = 0; j < columns; j++){
            M->set(i,j, vector->at(i + rows*j,0));
        }
    }

    return M->transpose();
}

Matrix* ImageProcessor::joinVectors(Matrix** vectors, int vectorsQuantity, bool normalize){
    // recebe um array de vetores que contenham as colunas empilhadas de uma imagem e
    // junta todos eles em uma matriz só
    Matrix *result = new Matrix(vectors[0]->rows, vectorsQuantity);
    for(int i = 0; i < vectorsQuantity; i++) {
        for(int j = 0 ; j < result->rows; j++) {
            if(normalize) result->set(j,i, (vectors[i]->at(j,0))/255.0);
            else result->set(j,i, vectors[i]->at(j,0));
        }
    }
    return result;
}

Matrix** ImageProcessor::splitVectors(Matrix* matrixOfVectors){
    // ele recebe uma matriz que contenham os vetores coluna e devolve
    // um array de matrizes representando cada vetor individualmente
    Matrix** vectors = new Matrix*[matrixOfVectors->columns];
    Matrix* vector;

    for(int j = 0 ; j < matrixOfVectors -> columns; j++) {
        vector = new Matrix(matrixOfVectors->rows, 1);
        for (int i = 0; i < matrixOfVectors->rows; i ++) {
            vector->set(i,0,matrixOfVectors->at(i,j));
        }
        vectors[j] = vector;
    }
    return vectors;
}


void ImageProcessor::normalize(Matrix* image){
    // normaliza a imagem, divididno por 255
    image->mutiplyByConstant(1/(255.0));
}

void ImageProcessor::unnormalize(Matrix* image){
    // desnormaliza a imagem, multiplicando por 255
    image->mutiplyByConstant(255.0);
}

Matrix* ImageProcessor::execute(Matrix** images, int imageQuantity, bool reverse, int rows, int columns) {
    // executa o processamento das imagens. 
    Matrix** vectors = new Matrix*[imageQuantity];
    for(int k = 0; k < imageQuantity; k++) {
        Matrix* image = images[k];
        
        // começa por gerar um vetor para cada imagem
        Matrix* vector = generateVector(image);
        vectors[k] = vector;
    }
    
    // depois, une todos esses vetores em uma matriz só
    Matrix* A = joinVectors(vectors, imageQuantity);

    // normaliza os valores da matriz A
    normalize(A);

    return A;
}

Matrix** ImageProcessor::reverse(Matrix* A, int rows, int columns, int p){
    // realiza o processo inverso do execute da ImageProcessor
    // recebe uma matriz com todas as colunas representando imagens
    // e devolve um array de imagens

    // desnormaliza os valores da matriz A
    unnormalize(A);

    Matrix** matrixes = new Matrix*[A->columns];

    // separa os vetores
    Matrix** vectors = splitVectors(A);
    for(int l = 0 ; l < p; l++) {

        // transforma o vetor em uma matriz 28x28
        Matrix* reversedMatrix = regenerateMatrix(vectors[l], rows, columns);

        matrixes[l] = reversedMatrix;
    }

    return matrixes;
}

void ImageProcessor::createImageFromColumn(Matrix* imageMatrix, int column, int p, char* fileName){
    // gera um arquivo do tipo ppm, que facilita ver as imagens pintadas

    Learning* learning = new Learning();
    
    // a partir de uma matriz com todas as imagens, ela  gera um array com 
    // as colunas em vetores separados
    Matrix **images = learning->getImages(imageMatrix, 28, 28, p);
    ofstream img(fileName);
    img << "P3" << endl;
    img << 28 << " " << 28 << endl;
	img << "255" << endl;

    // dada uma coluna, percorremos as matrizes, "desnormalizando" seus valores
    // e, então, coloca a escala RGB com os mesmos valores pare gerar uma escala preto e branca
    for (int i = 0; i < images[column]->rows; i++){
        for(int j = 0; j < images[column]->columns; j++){
			img << (int)(images[column]->at(i, j) * 255) << " " << (int)(images[column]->at(i, j) * 255) << " " << (int)((images[column]->at(i, j) * 255)) << endl;
        }
    }
    string openCommand = string("open ") + string(fileName);

    // comando para o sistema abrir a imagem
	system(openCommand.c_str());
}
