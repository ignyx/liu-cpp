#include <iomanip>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <forward_list>
#include <algorithm>
#include <iterator>

using namespace std;

void compute_arguments(string argument, forward_list<string>& text);
forward_list<string> read_words_from_file(ifstream &file);
void print(forward_list<string> &words);
void print_help(char *arg0);

int main(int argc, char **argv) {

  if (argc == 1) {
    print_help(argv[0]);
    exit(1);
  }

  char *file_name = argv[1];
  ifstream file{file_name};
  forward_list<string> text;
  forward_list<string> arguments{argv + 2, argv + argc};

  if (!file.is_open()) {
    cout << "failed to open " << file_name << endl;
    exit(1);
  }

  try {
    text = read_words_from_file(file);
  } catch (const ifstream::failure &error) {
    cout << "failed to read from " << file_name << ": " << error.what() << endl;
  }

  auto f = [&](string argument) { 
    compute_arguments(argument, text);
  };
  for_each(arguments.begin(),arguments.end(), f);
}
  

void compute_arguments(string argument, forward_list<string>& text){

  string parameter = argument.substr(argument.find('='));
  string flag = argument.substr(0, argument.find('='));


  if (flag == "--print"){
    print(text);
  }
  else if(flag == "--frequency"){

  }
  else if(flag == "--table"){

  }
  else if(flag == "--substitute"){

  }
  else if(flag == "--remove"){

  }
  else {
    cout << "unknown command" << endl;
    exit(1);
  }
}

forward_list<string> read_words_from_file(ifstream &file) {
  forward_list<string> words{istream_iterator<string>{file},
                             istream_iterator<string>{}};
  return words;
}

void print(forward_list<string> &words) {
  copy(words.begin(), words.end(), ostream_iterator<string>{cout, " "});
  cout << endl;
}

void print_help(char *arg0) {
  cout << "usage: " << arg0 << " <file> [arguments]" << endl;
  // TODO
}
