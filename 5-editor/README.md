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
argmuments :
--print                Prints current buffer
--frequency            Prints a frequency table, sorted by number of occurences
--table                Prints a frequency table, sorted alphabetically
--substitute=old+new   Replaces all occurences of old by new in buffer
--remove=word          Removes all occurences of word from buffer
```

Check for mem-leaks :

```
valgrind --tool=memcheck --leak-check=yes ./run_main.out lorem.txt --print --frequency --table --substitute=Lorem+bar --remove=bar --print
```
