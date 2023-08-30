/*
  File: main.cc
  Authors: Geoffroy Renaut & Paul Alnet
  Created: 30/08/2023
  Course : TDDE18-2023-1
  Description: Basic IO practice.
  Reads and echos different values from stdin and stdout.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
  int integer{};
  double real{};
  char letter{};
  string word{};

  cout << "Enter one integer : ";
  cin >> integer;
  cout << "You entered : ";
  cout << integer;
  cout << endl;
  cout << endl;

  cout << "Enter four integers : ";
  cin >> integer;
  cout << "You entered : ";
  cout << integer << " ";
  cin >> integer;
  cout << integer << " ";
  cin >> integer;
  cout << integer << " ";
  cin >> integer;
  cout << integer << " ";
  cout << endl;
  cout << endl;

  cout << "Enter one integer and one real number : ";
  cin >> integer;
  cin >> real;
  cout << "The real is : ";
  cout << right << setw(13) << real << endl;
  cout << "The integer is : ";
  cout << right << setw(10) << integer << endl;
  cout << endl;

  cout << "Enter one real and one integer number : ";
  cin >> real;
  cin >> integer;
  cout << "The real is : ";
  cout << right << setfill('.') << setw(13) << real << endl;
  cout << "The integer is : ";
  cout << right << setfill('.') << setw(10) << integer << endl;
  cout << endl;

  cout << "Enter a character : ";
  cin >> letter;
  cout << "You entered : " << letter << endl;
  cout << endl;

  cout << "Enter a word : ";
  cin >> word;
  cout << "The word '" << word << "' has " << word.size() << " character(s).";
  cout << endl;
  cout << endl;

  cout << "Enter an integer and a word : ";
  cin >> integer;
  cin >> word;
  cout << "You entered '" << integer << "' and '" << word << "'." << endl;
  cout << endl;

  cout << "Enter a character and a word : ";
  cin >> letter;
  cin >> word;
  cout << "You entered the string \"" << word;
  cout << "\" and the character '" << letter << "'." << endl;
  cout << endl;

  cout << "Enter a word and real number : ";
  cin >> word;
  cin >> real;
  cout << "You entered \"" << word << "\" and \"" << real << "\"." << endl;
  cout << endl; 

  cout << "Enter a text-line : ";
  cin.ignore(1, '\n');
  getline(cin, word);
  cout << "You entered : \"" << word << "\"" << endl;
  cout << endl;

  cout << "Enter a second line of text : ";
  getline(cin, word);
  cout << "You entered : \"" << word << "\"" << endl;
  cout << endl;

  cout << "Enter three words : ";
  cin >> word;
  cout << "You entered : '" << word << " ";
  cin >> word;
  cout << word << " ";
  cin >> word;
  cout << word << "'";
  cout << endl;
  
  return 0;
}
