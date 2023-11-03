#ifndef List_H
#define List_H
#include <initializer_list>
#include <iostream>

// TODO: Complementary work needed: Functions that doesn't modify the
// list should be declared const.
//
// TODO: Complementary work needed: Missing print member function.

struct Element {
  int value;
  Element *next;
  Element(int value) : value(value), next(nullptr) {}
};

class List {
private:
  Element *first;

public:
  List() : first(nullptr){};
  List(std::initializer_list<int> List);
  List(const List &other);
  List(List &&other);
  ~List();
  List &operator=(List const &other);
  List &operator=(List &&other);
  void insert(int value);
  int find_value_with_rank(int rank);
  int find_rank_with_value(int value);
  void delete_element_with_rank(int rank);
  void delete_element_with_value(int value);
  int size();
  bool is_empty();
  std::string to_string() const;
};

std::ostream &operator<<(std::ostream &os, List const &list);
#endif
