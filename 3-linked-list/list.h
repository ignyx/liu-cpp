#ifndef List_H
#define List_H
#include <initializer_list>
#include <iostream>

struct Element;

class List {
private:
  Element *first;

public:
  List();
  List(std::initializer_list<int> List);
  List(const List &other);
  List(List &&other);
  ~List();
  List &operator=(List const &other);
  List &operator=(List &&other);
  void insert(int value);
  int find_value_with_rank(int rank) const;
  int find_rank_with_value(int value) const;
  void delete_element_with_rank(int rank);
  void delete_element_with_value(int value);
  int size() const;
  bool is_empty() const;
  std::string to_string() const;
  void print() const;
};

#endif
