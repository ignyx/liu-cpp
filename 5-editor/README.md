# CLI Text editor

Reads a file and processes flags on it. Uses the standard library as much as
possible.

## Compiling and running

We can compile and run the main program with :

```
g++ -o run_main.out -std=c++17 -Wall -Wextra -Wpedantic -Weffc++ -Wold-style-cast main.cc
./run_main.out
```

```
usage: ./run_main.out <file> [arguments]
// TODO
```

Check for mem-leaks :

```
valgrind --tool=memcheck --leak-check=yes ./run_main.out 200000 10 0.01 24
```

## Testing and compiling

Download catch library then compile it.

```
wget https://www.ida.liu.se/~TDDE18/current/lab/given_files/lab2/catch.hpp
wget https://www.ida.liu.se/~TDDE18/current/lab/given_files/lab2/test_main.cc
g++ -std=c++17 -c test_main.cc
```

This should result in an `test_main.o` object file we can use during our tests.

We can then compile and run the tests :

```
g++ -o run_tests.out -std=c++17 -Wall -Wextra -Wpedantic -Weffc++ -Wold-style-cast test_main.o Network.cc test_Network.cc
./run_tests.out
```

Check for mem-leaks :

```
valgrind --tool=memcheck --leak-check=yes ./run_tests.out
```
