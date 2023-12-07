#include <algorithm>
#include <forward_list>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>

using namespace std;

class Text : private forward_list<string> {
public:
  Text(){};
  Text(istream_iterator<string> begin, istream_iterator<string> end)
      : forward_list(begin, end){};
  using forward_list<string>::begin;
  using forward_list<string>::end;
  void print() const;
  unordered_map<string, int> count_words() const;
  unsigned int get_max_word_length() const;
  void print_frequency_table_numer() const;
  void print_frequency_table_alpha() const;
  void substitute(const string &replaced, const string &replacing);
  void erase(const string &replaced);
  void compute_argument(const string &argument);
};

Text read_words_from_file(ifstream &file);
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

  for_each(arguments.begin(), arguments.end(), [&text](const string &argument) {
    text.compute_argument(argument);
  });
  return 0;
}

Text read_words_from_file(ifstream &file) {
  Text words{istream_iterator<string>{file}, istream_iterator<string>{}};
  return words;
}

void Text::print() const {
  copy(this->begin(), this->end(), ostream_iterator<string>{cout, " "});
  cout << endl;
}

void Text::substitute(const string &replaced, const string &replacing) {
  replace(this->begin(), this->end(), replaced, replacing);
}

void Text::erase(const string &replaced) {
  this->end() = std::remove(this->begin(), this->end(), replaced);
}

void print_help(char *arg0) {
  cout << "usage: " << arg0 << " <file> [arguments]" << endl;
  // TODO
}

unsigned int Text::get_max_word_length() const {
  return max_element(this->begin(), this->end(),
                     [](string a, string b) { return a.length() < b.length(); })
      ->length();
}

unordered_map<string, int> Text::count_words() const {
  // unsorted key-value pairs (O(1) average; O(n) worst-case)
  unordered_map<string, int> word_count;
  for_each(this->begin(), this->end(),
           [&word_count](const string &word) { word_count[word]++; });
  return word_count;
}

// Computes and prints and frequency table sorted alphabetically for
// the given text
void Text::print_frequency_table_alpha() const {
  unordered_map<string, int> word_count{this->count_words()};

  map<string, int> word_count_sorted;

  copy(word_count.begin(), word_count.end(),
       inserter(word_count_sorted, word_count_sorted.end()));

  const unsigned int max_word_length = this->get_max_word_length();

  cout << setfill(' ');
  for_each(word_count_sorted.begin(), word_count_sorted.end(),
           [max_word_length](const std::pair<string, int> word) {
             cout << left << setw(max_word_length + 1) << word.first << right
                  << word.second << "\n";
           });
  cout << flush;
}

// Computes and prints and frequency table sorted by decreasing frequency for
// the given text
void Text::print_frequency_table_numer() const {
  unordered_map<string, int> word_count{this->count_words()};

  multimap<int, string> word_count_sorted;

  transform(word_count.begin(), word_count.end(),
            inserter(word_count_sorted, word_count_sorted.end()),
            [](const std::pair<string, int> word) {
              const std::pair<int, string> reversed{word.second, word.first};
              return reversed;
            });

  const unsigned int max_word_length = this->get_max_word_length();

  cout << setfill(' ');
  for_each(word_count_sorted.rbegin(), word_count_sorted.rend(),
           [max_word_length](const std::pair<int, string> word) {
             cout << left << word.first << right << setw(max_word_length + 1)
                  << word.second << "\n";
           });
}

void Text::compute_argument(const string &argument) {
  const size_t separator{argument.find('=')};
  const size_t split{separator == string::npos ? argument.size() : separator};
  const string flag = argument.substr(0, split);
  const string parameter =
      separator == string::npos ? "" : argument.substr(split + 1);

  if (flag == "--print") {
    if (parameter.size() > 0)
      cerr << "warning: --print takes no parameter" << endl;
    print();
  } else if (flag == "--frequency") {
    if (parameter.size() > 0)
      cerr << "warning: --frequency takes no parameter" << endl;
    this->print_frequency_table_numer();

  } else if (flag == "--table") {
    if (parameter.size() > 0)
      cerr << "warning: --table takes no parameter" << endl;
    this->print_frequency_table_alpha();

  } else if (flag == "--substitute") {
    const size_t separator{parameter.find('+')};
    const size_t split{separator == string::npos ? parameter.size()
                                                 : separator};
    const string replaced = parameter.substr(0, split);
    const string replacing =
        separator == string::npos ? "" : parameter.substr(split + 1);

    substitute(replaced, replacing);
  } else if (flag == "--remove") {
    cout << parameter;
    erase(parameter);
  } else {
    cerr << "warning: unknown flag " << flag << endl;
  }
}
