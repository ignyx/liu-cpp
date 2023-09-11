/*
  File: wc.cc
  Authors: Geoffroy Renaut & Paul Alnet
  Created: 30/08/2023
  Course : TDDE18-2023-1
  Description: Wordcount
    Iters through a text file and outputs the number of words, shortest and
    longest words as well as the average length.
*/

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

const string file{"lorem.txt"};
// const string file{"empty.txt"};
// const string file{"single.txt"};
// const string file{"wc.cc"};

int main() {
  ifstream in{file};
  string word{};

  int count{0};
  int totalWordLength{0};
  string shortestWord{""};
  string longestWord{""};

  // handler initial edge case
  if (in >> word) {
    count++;
    totalWordLength += word.size();
    shortestWord = word;
    longestWord = word;
  }

  while (in >> word) {
    count++;
    totalWordLength += word.size();

    if (word.size() < shortestWord.size())
      shortestWord = word;
    longestWord = word.size() > longestWord.size() ? word : longestWord;
  }

  if (count == 0) {
    cout << "WARNING: file is empty" << endl;
    return 1;
  } else {
    // Ensure average is a double
    const double average = static_cast<double>(totalWordLength) / count;

    cout << "There are " << count << " words in the file.\n"

         << "The longest word was \"" << longestWord << "\" with "
         << longestWord.size() << " character(s).\n"

         << "The shortest word was \"" << shortestWord << "\" with "
         << shortestWord.size()
         << " character(s).\n"

         // Ensure displayed average has 2 decimals
         << fixed << setprecision(2)

         << "The average length was " << average << " character(s)." << endl;

    return 0;
  }
}
