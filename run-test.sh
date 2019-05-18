echo Running $1Test.cpp

if [ $1 = "Matrix" ] 
then
    g++ -std=c++11 src/modules/basic/matrix/Matrix.cpp tests/testmanager/TestManager.cpp tests/comparable/Comparable.cpp tests/modules/basic/matrix/MatrixTest.cpp -o MatrixTest.out
    ./MatrixTest.out
fi

if [ $1 = "MatrixGenerator" ] 
then
    g++ -std=c++11 basic/matrix/Matrix.cpp  basic/matrixgenerator/$1Test.cpp basic/matrixgenerator/MatrixGenerator.cpp -o $1Test.out
    ./$1Test.out
fi

if [ $1 = "QR" ] 
then
    g++ -std=c++11 src/modules/basic/matrix/Matrix.cpp tests/modules/factorization/qr/QrFactorizationTest.cpp src/modules/factorization/qr/QrFactorization.cpp tests/testmanager/TestManager.cpp tests/comparable/Comparable.cpp -o QRFactorizationTest.out
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

if [ $1 = "ImageProcessor" ] 
then
    g++ -std=c++11 src/modules/basic/matrix/Matrix.cpp  src/modules/imageprocessor/ImageProcessor.cpp tests/testmanager/TestManager.cpp tests/modules/imageprocessor/ImageProcessorTest.cpp -o ImageProcessor.out
    ./ImageProcessor.out
fi

if [ $1 = "Learning" ] 
then
    g++ -std=c++11 src/modules/basic/matrix/Matrix.cpp  src/modules/imageprocessor/ImageProcessor.cpp tests/testmanager/TestManager.cpp src/modules/learning/Learning.cpp tests/modules/learning/LearningTest.cpp -o Learning.out
    ./Learning.out
fi

if [ $1 = "SecondTask" ] 
then
    g++ -std=c++11 src/modules/basic/matrix/Matrix.cpp src/modules/factorization/qr/QrFactorization.cpp src/modules/factorization/alternatingLeastSquares/NonNegativeFactorization.cpp tests/testmanager/TestManager.cpp src/modules/systems/triangularsystemssolver/TriangularSystemsSolver.cpp src/tasks/secondTask/SecondTask.cpp src/tasks/secondTask/SecondTaskRunner.cpp -o SecondTask.out
    ./SecondTask.out
fi 
    
if [ $1 = "TimeHelper" ] 
then
    g++ -std=c++11 src/helpers/timehelper/TimeHelper.cpp tests/testmanager/TestManager.cpp tests/helpers/timehelper/TimeHelperTest.cpp -o TimeHelperTest.out
    ./TimeHelperTest.out
fi

if [ $1 = "FileHelper" ] 
then
    g++ -std=c++11 -Wno-writable-strings tests/testmanager/TestManager.cpp src/modules/basic/matrix/Matrix.cpp src/modules/imageprocessor/ImageProcessor.cpp  tests/helpers/filehelper/FileHelperTest.cpp src/helpers/filehelper/FileHelper.cpp -o FileHelper.out
    ./FileHelper.out
fi

if [ $1 = "Training" ] 
then
    g++ -std=c++11 -Wno-writable-strings src/modules/classificator/Classificator.cpp src/helpers/timehelper/TimeHelper.cpp src/modules/factorization/qr/QrFactorization.cpp tests/testmanager/TestManager.cpp src/modules/systems/triangularsystemssolver/TriangularSystemsSolver.cpp src/modules/learning/Learning.cpp  src/modules/imageprocessor/ImageProcessor.cpp src/modules/basic/matrix/Matrix.cpp src/helpers/filehelper/FileHelper.cpp src/modules/factorization/alternatingLeastSquares/NonNegativeFactorization.cpp src/tasks/training/Training.cpp -o Training.out
    ./Training.out
fi

if [ $1 = "MainTask" ] 
then
    g++ -std=c++11 -Wno-writable-strings src/modules/classificator/Classificator.cpp src/helpers/timehelper/TimeHelper.cpp src/modules/factorization/qr/QrFactorization.cpp tests/testmanager/TestManager.cpp src/modules/systems/triangularsystemssolver/TriangularSystemsSolver.cpp src/modules/learning/Learning.cpp  src/modules/imageprocessor/ImageProcessor.cpp src/modules/basic/matrix/Matrix.cpp src/helpers/filehelper/FileHelper.cpp src/modules/factorization/alternatingLeastSquares/NonNegativeFactorization.cpp  src/tasks/mainTask/train/Train.cpp src/tasks/mainTask/main.cpp -o MainTask.out
    ./MainTask.out
fi
