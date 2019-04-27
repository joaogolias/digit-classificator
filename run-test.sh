echo Running $1Test.cpp

if [ $1 = "Matrix" ] 
then
    g++ -std=c++11 src/modules/basic/matrix/Matrix.cpp tests/testmanager/TestManager.cpp tests/testable/Testable.cpp tests/modules/basic/matrix/MatrixTest.cpp -o MatrixTest.out
    ./MatrixTest.out
fi

if [ $1 = "MatrixGenerator" ] 
then
    g++ -std=c++11 basic/matrix/Matrix.cpp  basic/matrixgenerator/$1Test.cpp basic/matrixgenerator/MatrixGenerator.cpp -o $1Test.out
    ./$1Test.out
fi

if [ $1 = "QR" ] 
then
    g++ -std=c++11 factorization/qr/QRFactorization.cpp  factorization/qr/QRFactorizationTest.cpp basic/matrix/Matrix.cpp  -o QRFactorizationTest.out
    ./QRFactorizationTest.out
fi

