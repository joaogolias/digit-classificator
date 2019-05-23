if [ $1 = "FirstTask" ] 
then
    g++ -std=c++11 src/modules/basic/matrix/Matrix.cpp src/modules/factorization/qr/QrFactorization.cpp tests/testmanager/TestManager.cpp src/modules/systems/triangularsystemssolver/TriangularSystemsSolver.cpp src/tasks/firstTask/FirstTask.cpp src/tasks/firstTask/FirstTaskRunner.cpp -o FirstTask.out
    ./FirstTask.out
fi

if [ $1 = "SecondTask" ] 
then
    g++ -std=c++11 src/modules/basic/matrix/Matrix.cpp src/modules/factorization/qr/QrFactorization.cpp src/modules/factorization/alternatingLeastSquares/NonNegativeFactorization.cpp tests/testmanager/TestManager.cpp src/modules/systems/triangularsystemssolver/TriangularSystemsSolver.cpp src/tasks/secondTask/SecondTask.cpp src/tasks/secondTask/SecondTaskRunner.cpp -o SecondTask.out
    ./SecondTask.out
fi 

if [ $1 = "MainTask" ] 
then
    echo ndig=$2 p=$3
    g++ -std=c++11 -Wno-writable-strings src/helpers/timehelper/TimeHelper.cpp src/modules/factorization/qr/QrFactorization.cpp tests/testmanager/TestManager.cpp src/modules/systems/triangularsystemssolver/TriangularSystemsSolver.cpp src/modules/learning/Learning.cpp  src/modules/imageprocessor/ImageProcessor.cpp src/modules/basic/matrix/Matrix.cpp src/helpers/filehelper/FileHelper.cpp src/modules/factorization/alternatingLeastSquares/NonNegativeFactorization.cpp  src/tasks/mainTask/train/Train.cpp src/tasks/mainTask/main.cpp src/tasks/mainTask/percentagehit/PercentageHit.cpp -o MainTask.out
    ./MainTask.out $2 $3
fi

if [ $1 = "AllMainTask" ] 
then
    ./run-test.sh MainTask 100 5 &&
    ./run-test.sh MainTask 100 10 &&
    ./run-test.sh MainTask 1000 5 &&
    ./run-test.sh MainTask 100 15 &&
    ./run-test.sh MainTask 1000 10 &&
    ./run-test.sh MainTask 1000 15 &&
    ./run-test.sh MainTask 4000 5 &&
    ./run-test.sh MainTask 4000 10 &&
    ./run-test.sh MainTask 4000 15
fi

