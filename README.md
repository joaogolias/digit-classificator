# digit-classificator

## RUN MAIN
There is a Bash script that runs the main file: run-main.sh

When first run, you need to prepare the script. To do so, run:

```
chmod u+x <path to run-main.sh>
```

After that, the program can be run, by using:
```
./run-main.sh
```

## TESTING
We don't use any framework or library for this, because we want this program to be very simple. 

There is a Bash script that runs test files: run-main.sh

When first run, you need to prepare the script. To do so, run:

```
chmod u+x <path to run-main.sh>
```

After that, the program can be run, by using:
```
./run-main.sh  <what you want to test>
```

The pattern is: each test file has the same name of its directory with the first letter capitalized and followed by "Test.cpp". 
So, in order to run matrix directory tests, you must run

```
./run-main.sh  Matrix
```