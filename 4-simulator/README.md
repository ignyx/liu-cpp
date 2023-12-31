# Electric network simulator

The simulator is implemented as a library and tested. It is then used to build
and simulate the networks.

## Compiling and running

We can compile and run the main program with :

```
g++ -o run_main.out -std=c++17 -Wall -Wextra -Wpedantic -Weffc++ -Wold-style-cast Network.cc main.cc
./run_main.out
```

```
usage: ./run_main.out iterations lines step battery_voltage
example: ./run_main.out 200000 10 0.01 24
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
