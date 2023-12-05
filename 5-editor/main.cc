#include <algorithm>
#include <forward_list>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>

using namespace std;

forward_list<string> read_words_from_file(ifstream &file);
void print(forward_list<string> &words);
void print_help(char *arg0);
void execute_argument(const string &argument, forward_list<string> &text);

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

  for_each(arguments.begin(), arguments.end(), [&text](const string &argument) {
    execute_argument(argument, text);
  });
  // print(text);
  // print(arguments);
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

unordered_map<string, int> count_words(const forward_list<string> &text) {
  // unsorted key-value pairs (O(1) average; O(n) worst-case)
  unordered_map<string, int> word_count;
  for_each(text.begin(), text.end(),
           [&word_count](const string &word) { word_count[word]++; });
  return word_count;
}

// Computes and prints and frequency table sorted alphabetically for
// the given text
void print_frequency_table_alpha(const forward_list<string> &text) {
  unordered_map<string, int> word_count{count_words(text)};

  map<string, int> word_count_sorted;

  copy(word_count.begin(), word_count.end(),
       inserter(word_count_sorted, word_count_sorted.end()));

  // TODO refactore
  // TODO format
  for_each(word_count_sorted.begin(), word_count_sorted.end(),
           [](const std::pair<string, int> word) {
             cout << word.first << word.second << endl;
           });
}

// Computes and prints and frequency table sorted by decreasing frequency for
// the given text
void print_frequency_table_numer(const forward_list<string> &text) {
  unordered_map<string, int> word_count{count_words(text)};

  multimap<int, string> word_count_sorted;

  transform(word_count.begin(), word_count.end(),
            inserter(word_count_sorted, word_count_sorted.end()),
            [](const std::pair<string, int> word) {
              const std::pair<int, string> reversed{word.second, word.first};
              return reversed;
            });

  // TODO refactore
  // TODO format
  for_each(word_count_sorted.rbegin(), word_count_sorted.rend(),
           [](const std::pair<int, string> word) {
             cout << word.first << " " << word.second << endl;
           });
}

void execute_argument(const string &argument, forward_list<string> &text) {
  const size_t separator{argument.find('=')};
  const size_t split{separator == string::npos ? argument.size() : separator};
  const string flag = argument.substr(0, split);
  const string parameter = argument.substr(split);

  if (flag == "--print") {
    if (parameter.size() > 0)
      cerr << "warning: --print takes no parameter" << endl;
    print(text);
  } else if (flag == "--frequency") {
    if (parameter.size() > 0)
      cerr << "warning: --frequency takes no parameter" << endl;
    print_frequency_table_numer(text);

  } else if (flag == "--table") {
    if (parameter.size() > 0)
      cerr << "warning: --table takes no parameter" << endl;
    print_frequency_table_alpha(text);

  } else if (flag == "--substitute") {

  } else if (flag == "--remove") {

  } else {
    cerr << "warning: unknown flag " << flag << endl;
  }
}
