#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

struct Element {
  double value;
  Element *next;
  Element(int value) : value(value), next(nullptr) {}
};

class List {
public:
  List() : first(nullptr){};
  List(std::initializer_list<int> list);
  List(const List &other);
  ~List();
  List &operator=(List const &other);
  void insert(double value);
  double find_value_with_rank(int rank);
  int find_rank_with_value(double value);
  void delete_element_with_rank(int rank);
  void delete_element_with_value(double value);
  void display();

private:
  Element *first;
};

// construcor, allow multiple values
List::List(std::initializer_list<int> list) : first(nullptr) {
  for (int i : list) {
    insert(i);
  }
}

// destructor
List::~List() {
  Element *current = first;
  while (current != nullptr) {
    Element *temp = current;
    current = current->next;
    delete temp;
  }
}

// insert the given value at the right place in the list
void List::insert(double value) {
  Element *new_element = new Element(value);
  if (first == nullptr) {
    first = new_element;
    return;
  }
  Element *current_element = first;
  while (current_element->next != nullptr or current_element->value < value) {
    current_element = current_element->next;
  }
  new_element->next = current_element->next;
  current_element->next = new_element;
}

// copy constructor
List::List(const List &other) : first(nullptr) {
  if (other.first != nullptr) {
    Element *current_element = other.first;
    while (current_element != nullptr) {
      insert(current_element->value);
      current_element = current_element->next;
    }
  }
}

// return the value stocked at rank "target_rank", if not find, return 0
double List::find_value_with_rank(int target_rank) {
  double value = 0;
  if (first == nullptr) {
    return 0;
  }
  int current_rank(0);

  Element *current_element = first;
  while (current_element->next != nullptr and current_rank + 1 != target_rank) {
    current_element = current_element->next;
    current_rank++;
  }
  if (current_element->next != nullptr) {
    value = current_element->next->value;
  }
  return value;
}

// return the rank of the first apparence of a value, -1 if not found, begin at
// 0
int List::find_rank_with_value(double value) {
  int rank(-1);
  if (first == nullptr) {
    return rank;
  }

  if (first->value == value) {
    return 0;
  }

  Element *current_element = first;
  while (current_element->next != nullptr and
         current_element->next->value != value) {
    current_element = current_element->next;
  }
  if (current_element->next != nullptr) {
    Element *temp = current_element->next;
    current_element->next = current_element->next->next;
    delete temp;
  }
  return rank;
}

// delete the Element at rank "target_rank", do nothing if rank bigger than the
// list size, may have return a boolean but flemme
void List::delete_element_with_rank(int target_rank) {
  if (first == nullptr) {
    return;
  }
  int current_rank(0);

  Element *current_element = first;
  while (current_element->next != nullptr and current_rank + 1 != target_rank) {
    current_element = current_element->next;
    current_rank++;
  }
  if (current_element->next != nullptr) {
    Element *temp = current_element->next;
    current_element->next = current_element->next->next;
    delete temp;
  }
}

// do the same thing than the previous but with the value instead of the rank
void List::delete_element_with_value(double value) {
  if (first == nullptr) {
    return;
  }

  if (first->value == value) {
    Element *temp = first;
    first = first->next;
    delete temp;
    return;
  }

  Element *current_element = first;
  while (current_element->next != nullptr and
         current_element->next->value != value) {
    current_element = current_element->next;
  }
  if (current_element->next != nullptr) {
    Element *temp = current_element->next;
    current_element->next = current_element->next->next;
    delete temp;
  }
}

// well it display the list
void List::display() {
  Element *current = first;
  while (current != nullptr) {
    cout << current->value << " ";
    current = current->next;
  }
  cout << endl;
}
