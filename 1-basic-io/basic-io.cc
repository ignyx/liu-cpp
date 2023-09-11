/*
  File: main.cc
  Authors: Geoffroy Renaut & Paul Alnet
  Created: 30/08/2023
  Course : TDDE18-2023-1
  Description: Basic IO practice.
  Reads and echos different values from stdin and stdout.
*/

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int integer{};
  double real{};
  char letter{};
  string word{};

  cout << "Enter one integer : ";
  cin >> integer;
  cout << "You entered : " << integer << "\n" << endl;

  cout << "Enter four integers : ";
  cin.ignore(1000, '\n');
  cin >> integer;
  cout << "You entered : " << integer << " ";
  cin >> integer;
  cout << integer << " ";
  cin >> integer;
  cout << integer << " ";
  cin >> integer;
  cout << integer << "\n" << endl;

  // Set precision for displaying real numbers
  // Otherwise 2 is displayed as 2 and not 2.000
  cout << fixed << setprecision(3);

  cout << "Enter one integer and one real number : ";
  cin.ignore(1000, '\n');
  cin >> integer;
  cin >> real;
  cout << "The real is : " << right << setw(13) << real << "\n"
       << "The integer is : " << right << setw(10) << integer << "\n"
       << endl;

  cout << "Enter one real and one integer number : ";
  cin.ignore(1000, '\n');
  cin >> real;
  cin >> integer;
  cout << "The real is : " << right << setfill('.') << setw(13) << real << "\n"
       << "The integer is : " << right << setfill('.') << setw(10) << integer
       << "\n"
       << endl;

  cout << "Enter a character : ";
  cin.ignore(1000, '\n');
  cin >> letter;
  cout << "You entered : " << letter << "\n" << endl;

  cout << "Enter a word : ";
  cin.ignore(1000, '\n');
  cin >> word;
  cout << "The word '" << word << "' has " << word.size() << " character(s).\n"
       << endl;

  cout << "Enter an integer and a word : ";
  cin.ignore(1000, '\n');
  cin >> integer;
  cin >> word;
  cout << "You entered '" << integer << "' and '" << word << "'.\n" << endl;

  cout << "Enter a character and a word : ";
  cin.ignore(1000, '\n');
  cin >> letter;
  cin >> word;
  cout << "You entered the string \"" << word << "\" and the character '"
       << letter << "'.\n"
       << endl;

  cout << "Enter a word and real number : ";
  cin.ignore(1000, '\n');
  cin >> word;
  cin >> real;
  cout << "You entered \"" << word << "\" and \"" << real << "\".\n" << endl;

  cout << "Enter a text-line : ";
  cin.ignore(1000, '\n');
  getline(cin, word);
  cout << "You entered : \"" << word << "\"\n" << endl;

  cout << "Enter a second line of text : ";
  // no need to ignore as the previous entry consumes an entire line
  getline(cin, word);
  cout << "You entered : \"" << word << "\"\n" << endl;

  cout << "Enter three words : ";
  // no need to ignore for the same reason
  cin >> word;
  cout << "You entered : '" << word << " ";
  cin >> word;
  cout << word << " ";
  cin >> word;
  cout << word << "'" << endl;

  return 0;
}
