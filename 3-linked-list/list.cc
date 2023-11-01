#include "list.h"
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// construcor, allow multiple values
List::List(std::initializer_list<double> list) : first(nullptr) {
  for (double value : list) {
    insert(value);
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
  } else if (value < first->value) {
    new_element->next = first;
    first = new_element;
    return;
  }

  Element *current_element = first;
  while (current_element->next != nullptr and
         current_element->next->value < value) {
    current_element = current_element->next;
  }
  new_element->next = current_element->next;
  current_element->next = new_element;
}

// copy constructor
List::List(const List &other) : first(nullptr) {
  Element *current_element = other.first;
  while (current_element != nullptr) {
    insert(current_element->value);

    current_element = current_element->next;
  }
}

// move constructor
List::List(List &&other) : first(other.first) { other.first = nullptr; }

// return the value stocked at rank "target_rank", if not find, return 0
double List::find_value_with_rank(int target_rank) {
  if (target_rank < 0)
    return 0.0; // ideally would return an error

  int current_rank{0};
  Element *current_element{first};

  while (current_element != nullptr and current_rank < target_rank) {
    current_rank++;
    current_element = current_element->next;
  }
  if (current_element != nullptr)
    return current_element->value;
  return 0.0;
}

// return the rank of the first apparence of a value, -1 if not found, begin at
// 0
int List::find_rank_with_value(double value) {
  if (first == nullptr) {
    return -1;
  } else if (first->value == value) {
    return 0;
  }
  int rank{1};

  Element *current_element{first};
  while (current_element->next != nullptr and
         current_element->next->value != value) {
    rank++;
    current_element = current_element->next;
  }
  if (current_element->next == nullptr) {
    return -1;
  }
  return rank;
}

// delete the Element at rank "target_rank", do nothing if rank bigger than the
// list size, may have return a boolean but flemme
void List::delete_element_with_rank(int target_rank) {
  if (first == nullptr or target_rank >= size()) {
    return;
  } else if (target_rank == 0) {
    Element *temp = first;
    first = first->next;
    delete temp;
  }

  int current_rank{0};

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
  } else if (first->value == value) {
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

string element_to_string(Element *element) {
  if (element->next == nullptr)
    return to_string(element->value);
  else
    return to_string(element->value) + " " + element_to_string(element->next);
}

string List::to_string() const {
  if (first == nullptr)
    return "";
  else
    return element_to_string(first);
}

// recursively display a linked list of elements
ostream &operator<<(ostream &os, List const &list) {
  os << list.to_string();
  return os;
}

int List::size() {
  int count{0};
  Element *current{first};
  while (current != nullptr) {
    count++;
    current = current->next;
  }
  return count;
}

bool List::is_empty() { return first == nullptr; }

// copy assignment operator
List &List::operator=(List const &other) {
  // Prevent self-assignment
  if (first == other.first)
    return *this;

  // delete this' elements
  Element *current = first;
  while (current != nullptr) {
    Element *temp = current;
    current = current->next;
    delete temp;
  }
  first = nullptr;

  // deep copy new elements
  Element *current_element = other.first;
  while (current_element != nullptr) {
    insert(current_element->value);

    current_element = current_element->next;
  }
  return *this;
}

// move assignment operator
List &List::operator=(List &&other) {
  // Prevent self-assignment
  if (first == other.first)
    return *this;

  Element *current = first;
  while (current != nullptr) {
    Element *temp = current;
    current = current->next;
    delete temp;
  }

  first = other.first;

  other.first = nullptr;

  return *this;
}
