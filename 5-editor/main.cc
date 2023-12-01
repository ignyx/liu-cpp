#include <algorithm>
#include <forward_list>
#include <fstream>
#include <iostream>
#include <iterator>
#include <unordered_map>

using namespace std;

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

  print(text);
  print(arguments);
  return 0;
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

unordered_map<string, int> count_words(forward_list<string> &text) {
  // unsorted key-value pairs (O(1) average; O(n) worst-case)
  unordered_map<string, int> word_count;
  for_each(text.begin(), text.end(),
           [&word_count](string word) { word_count[word]++; });
  return word_count;
}
