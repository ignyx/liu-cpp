#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {
  ifstream in{"wc.cc"};
  string word{};
  int count{0};

  while(in >> word) {
    cout << word;
    count++;
  }
  return 0;
}
