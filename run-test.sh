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
    g++ -std=c++11 src/modules/basic/matrix/Matrix.cpp tests/modules/factorization/qr/QrFactorizationTest.cpp src/modules/factorization/qr/QrFactorization.cpp tests/testmanager/TestManager.cpp tests/testable/Testable.cpp -o QRFactorizationTest.out
    ./QRFactorizationTest.out
fi

if [ $1 = "TriangularSystemsSolver" ] 
then
    g++ -std=c++11 src/modules/basic/matrix/Matrix.cpp src/modules/factorization/qr/QrFactorization.cpp tests/testmanager/TestManager.cpp src/modules/systems/triangularsystemssolver/TriangularSystemsSolver.cpp tests/modules/systems/triangularsystemsolver/TriangularSystemsSolverTest.cpp -o TriangularSystemsSolverTest.out
    ./TriangularSystemsSolverTest.out
fi

if [ $1 = "FirstTask" ] 
then
    g++ -std=c++11 src/modules/basic/matrix/Matrix.cpp src/modules/factorization/qr/QrFactorization.cpp tests/testmanager/TestManager.cpp src/modules/systems/triangularsystemssolver/TriangularSystemsSolver.cpp src/tasks/firstTask/FirstTask.cpp src/tasks/firstTask/FirstTaskRunner.cpp -o FirstTask.out
    ./FirstTask.out
fi
