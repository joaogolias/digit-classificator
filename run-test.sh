echo Running $1Test.cpp
g++ -std=c++14 basic/matrix/$1Test.cpp basic/matrix/$1.cpp -o $1Test.out
./$1Test.out