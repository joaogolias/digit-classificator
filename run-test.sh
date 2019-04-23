echo Running $1Test.cpp
if [ $1 = "Matrix" ] 
then
    g++ -std=c++11 basic/matrix/$1Test.cpp basic/matrix/Matrix.cpp -o $1Test.out
    ./$1Test.out
fi

if [ $1 = "MatrixGenerator" ] 
then
    g++ -std=c++11 basic/matrix/Matrix.cpp  basic/matrixgenerator/$1Test.cpp basic/matrixgenerator/MatrixGenerator.cpp -o $1Test.out
    ./$1Test.out
fi