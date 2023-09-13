# Time library

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
g++ -o run_tests.out -std=c++17 -Wall -Wextra -Wpedantic -Weffc++ -Wold-style-cast test_main.o Time.cc test_time.cc
./run_tests.out
```
