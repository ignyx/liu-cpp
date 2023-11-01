#ifndef List_H
#define List_H
#include <initializer_list>
#include <iostream>

struct Element {
  double value;
  Element *next;
  Element(double value) : value(value), next(nullptr) {}
};

class List {
private:
  Element *first;

public:
  List() : first(nullptr){};
  List(std::initializer_list<double> List);
  List(const List &other);
  List(List &&other);
  ~List();
  List &operator=(List const &other);
  List &operator=(List &&other);
  void insert(double value);
  double find_value_with_rank(int rank);
  int find_rank_with_value(double value);
  void delete_element_with_rank(int rank);
  void delete_element_with_value(double value);
  int size();
  bool is_empty();
  std::string to_string() const;
};

std::ostream &operator<<(std::ostream &os, List const &list);
#endif
