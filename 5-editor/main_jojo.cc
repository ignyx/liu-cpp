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


class Text : private forward_list<string>{
  public :
    Text(){};
    Text(istream_iterator<string> begin, istream_iterator<string> end)
      : forward_list(begin, end){};
    using forward_list<string>::begin;
    using forward_list<string>::end;
    //using forward_list<string>::operator=;
    void print();
    void substitute(string replaced, string replacing);
    void erase(string replaced);
    void compute_arguments(string argument);
};

Text read_words_from_file(ifstream &file);
void print(forward_list<string> &words);
void print_help(char *arg0);

int main(int argc, char **argv) {

  if (argc == 1) {
    print_help(argv[0]);
    exit(1);
  }

  char *file_name = argv[1];

  ifstream file{file_name};
  Text text;
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
    text.compute_arguments(argument);
  };
  for_each(arguments.begin(),arguments.end(), f);
}
  

void Text::compute_arguments(string argument){

  string parameter = argument.substr(argument.find('='));
  string flag = argument.substr(0, argument.find('='));


  if (flag == "--print"){
    this->print();
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


Text read_words_from_file(ifstream &file) {

  Text words{istream_iterator<string>{file},
                             istream_iterator<string>{}};
  return words;
}

void Text::print() {
  copy(this->begin(), this->end(), ostream_iterator<string>{cout, " "});
  cout << endl;
}

void Text::substitute(string replaced, string replacing){
  replace(this->begin(), this->end(), replaced, replacing);
}

void Text::erase(string replaced){
  std::remove(this->begin(), this->end(),replaced);
}



void print_help(char *arg0) {
  cout << "usage: " << arg0 << " <file> [arguments]" << endl;
  // TODO
}

